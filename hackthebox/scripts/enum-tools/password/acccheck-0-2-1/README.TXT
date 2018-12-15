acccheck.pl - Windows SMB Password Dictionary Attack Tool
Copyright (C) 2008 Faisal Dean (Faiz)

The tool is designed as a password dictionary attack tool that targets windows authentication via the SMB protocol. It is really a wrapper script around the 'smbclient' binary, and as a result is dependent on it for its execution.

The simplest way to run the tool is as follows:

./acccheck.pl -t 10.10.10.1

This mode of execution attempts to connect to the target ADMIN$ share with the username 'Administrator' and a [BLANK] for the password.

./acccheck.pl -t 10.10.10.1 -u test -p test

This mode of execution attempts to connect to the target IPC$ share with the username 'test' and a password 'test'.

Each -t, -u and -p flags can be substituted by -T, -U and -P, where each represents an input file rather than a single input from standard in.

E.g.
./acccheck.pl -T iplist -U userfile -P passwordfile

Only use -v mode on very small dictionaries, otherwise, this has the affect of slowing the scan down to the rate the system writes to standard out.

Any username/password combinations found are written to a file called 'cracked' in the working directory.

Any comments can be emailed to me at:

fmd@portcullis-security.com
