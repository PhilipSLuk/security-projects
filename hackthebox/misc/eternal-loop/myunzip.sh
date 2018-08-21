#! /bin/bash

echo "hello world"

# initialize to our first zip file..
file=37366.zip

while [ true ];
do

  if [[ $file =~ .*\.zip ]];
  then
    echo "zip file: $file"
    nextfile=$(unzip -l $file | grep -v $file | grep zip | awk '{print $4}')
    passwd=$(echo $nextfile | tr ".zip" "\n")
    if [[ -z "$passwd" ]];
    then
      echo "WARNING: no password pattern found"
      unzip $file
    else
      unzip -P $passwd $file
    fi
    if [[ $? -ne 0 ]];
    then
      echo "ERROR: something went wrong with unzip"
      exit;
    fi
    file=$nextfile
  else
    echo "$file is NOT a zip file";
    exit
  fi

done
