#! /usr/bin/bash

for i in $( ls ); do
  echo file: $i
  cat ./$i
done
