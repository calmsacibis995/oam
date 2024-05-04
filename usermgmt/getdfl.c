/*	Copyright (c) 1990 UNIX System Laboratories, Inc.	*/
/*	Copyright (c) 1984, 1986, 1987, 1988, 1989, 1990 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF     	*/
/*	UNIX System Laboratories, Inc.                     	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ident	"@(#)oamintf:usermgmt/getdfl.c	1.1.2.2"

#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#if defined(__SVR4) || defined(__sun) || defined(__illumos__)
#include <deflt.h>
#endif
#include <stdlib.h>

#if !defined(__SVR4) || !defined(__sun) || !defined(__illumos__)

#define	FOREVER		for ( ; ; )
#define	TSTBITS(flags, mask)	(((flags) & (mask)) == (mask))
#define	DC_CASE		0001	/* ON: respect case; OFF: ignore case */
#define	DC_STD		((0) | (DC_CASE))

static FILE *dfile = NULL;
static int Dcflags;		/* [re-]initialized on each call to defopen() */

static void strlower(register char *from, register char *to);
static void strnlower(register char *from, register char *to, register int cnt);

int
defopen(char *fn)
{

	if (dfile != (FILE *) NULL)
		fclose(dfile);

	if (fn == (char *) NULL) {	/* M001 */
		dfile = NULL;
		return(0);
	}

	if ((dfile = fopen(fn, "r")) == (FILE *) NULL)
		return(-1);

	Dcflags = DC_STD;	/* M000 */

	return(0);
}

char *
defread(char *cp)
{
	static char buf[256];	/* M002 */
	register int len;
	register int patlen;

	if (dfile == (FILE *) NULL)
		return((char *) NULL);
	patlen = strlen(cp);

	rewind(dfile);
	while (fgets(buf, sizeof(buf), dfile)) {
		len = strlen(buf);
		if (buf[len-1] == '\n')
			buf[len-1] = 0;
		else
			return((char *) NULL);		/* line too long */
		if (!TSTBITS(Dcflags, DC_CASE)) {	/* M000 ignore case */
			strlower(cp, cp);
			strnlower(buf, buf, patlen);
		}
		if (strncmp(cp, buf, patlen) == 0)
			return(&buf[patlen]);           /* found it */
	}
	return((char *) NULL);
}

static void
strlower(register char *from, register char *to)
{
	register int  ch;

	FOREVER {
		ch = *from++;
		if ((*to++ = tolower(ch)) == '\0')
			break;
	}

	return;
}

static void
strnlower(register char *from, register char *to, register int cnt)
{
	register int  ch;

	while (cnt-- > 0) {
		ch = *from++;
		if ((*to++ = tolower(ch)) == '\0')
			break;
	}
}

#endif

int	mindate, maxdate, warndate, idledate;
int	nflg, xflg, wflg, iflg, tflg;

int
main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	char *char_p;
	register int c, flag = 0;

	char_p = NULL;
	while ((c = getopt(argc, argv, "xnwit")) != EOF) {
		switch (c) {
		case 'x':		/* delet the password */
			xflg = 1;
			break;
		case 'n':
			nflg = 1;
			break;
		case 'w':
			wflg = 1;
			break;
		case 'i':
			iflg = 1;
			break;
		case 't':
			tflg = 1;
			break;
		}
	}
	argv = &argv[optind];
        if( (defopen(*argv)) != 0) {
        	defopen(NULL);                  /* close defaults file */
		exit;
	}
	if(xflg) {
		/*
		 * char_p == NULL when MAXWEEKS note in the file and
		 * *char_p == '\0' when no value assigned to MAXWEEKS.
		 */
		if( (char_p=defread("MAXWEEKS=")) != NULL && *char_p != '\0') {
			if ((maxdate = atoi(char_p)) == -1) {
				maxdate = -1;
			} else {
				maxdate *= 7;
			}
			printf("%d",maxdate);
		}
	} else if (nflg) {
		if( (char_p=defread("MINWEEKS=")) != NULL && *char_p != '\0') {
			mindate = 7 * atoi(char_p);
			if (mindate >= 0)
				printf("%d",mindate);
		}
	} else if (wflg) {
		if( (char_p=defread("WARNWEEKS=")) != NULL && *char_p != '\0') {
			warndate = 7 * atoi(char_p);
			if (warndate >= 0)
				printf("%d",warndate);
		}
	} else if (iflg) {
		if( (char_p=defread("IDLEWEEKS=")) != NULL && *char_p != '\0') {
			idledate = 7 * atoi(char_p);
			if (idledate >= 0)
				printf("%d",idledate);
		}
	} else if (tflg) {
		if( (char_p=defread("TIMEZONE=")) != NULL && *char_p != '\0') 
			printf("%s",char_p);
	}
        defopen(NULL);                  /* close defaults file */
}
