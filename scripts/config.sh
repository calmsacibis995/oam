#!/bin/bash

#
# Check for superuser permissions.
#
if [ "$EUID" -ne 0 ]
	then echo "The following script must be run as superuser."
	exit 1
fi

echo "You are about to configure the Operations, Administration and Maintenance
(OA&M) user interface."

#
# Create the sysadm login and set a password prior to installing the OA&M files.
# The login is necessary for sysadm to function, as the program will error out otherwise.
#
if id -u "sysadm" >/dev/null 2>&1; then
	echo >&2 "The OA&M administrative login <sysadm> already exists.
Please re-set the password for it now."
	passwd sysadm
else
	useradd -g root -c "general system administration" -d /usr/admin -s /usr/sbin/sysadm -m sysadm > /dev/null 2>&1
	ret=$?
	case "${ret}" in
	0)
		echo >&2 "Please set a password for your OA&M administrative login <sysadm> now."
		passwd sysadm
		;;
	*)
		echo >&2 "ERROR: Cannot create the OA&M administrative login <sysadm>.
This login must be available for installation of OA&M to be successful."
		exit 1
		;;
	esac
fi

echo "All is done. Assuming you have installed the fmli utility, you may
launch the OA&M user interface with the 'sysadm' command. If you haven't
installed it yet, install it as soon as possible."

exit 0
