/*	Copyright (c) 1990 UNIX System Laboratories, Inc.	*/
/*	Copyright (c) 1984, 1986, 1987, 1988, 1989, 1990 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF     	*/
/*	UNIX System Laboratories, Inc.                     	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ident	"@(#)oamintf:usermgmt/moddate.c	1.1.1.1"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

int
main(int argc, char *argv[])
{
	time_t tstamp;
	struct tm *tmp;

	if (argc != 2) {
		printf("Usage: %s <days>\n", argv[0]);
		exit(1);
	}

	tstamp = (atoi(argv[1]) * 24LL * 60 * 60) + (24LL * 60 * 60 / 2);
	tmp = localtime(&tstamp);
	printf("%d/%d/%d", tmp->tm_mon + 1, tmp->tm_mday, tmp->tm_year + 1900);
}
