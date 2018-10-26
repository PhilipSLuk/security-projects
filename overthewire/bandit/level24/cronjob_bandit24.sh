#!/bin/bash

myname=$(whoami)

cd /var/spool/$myname
echo "Executing and deleting all scripts in /var/spool/$myname:"
for i in * .*;
do
    if [ "$i" != "." -a "$i" != ".." ];
    then
    echo "Handling $i"
    timeout -s 9 60 ./$i
    rm -f ./$i
    fi
done
