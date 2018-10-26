#! /bin/bash

i=$1
# ensure $i is between 0 <=i <= 9
if [ "$i" -lt 0 ] || [ "$i" -gt 9 ]; then
  echo "USAGE: $0 <int>"
  exit 0
fi

for j in `seq 0 9`; do
  for k in `seq 0 9`; do
    for l in `seq 0 9`; do
      output=$(echo "UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ $$i$j$k$l" | nc localhost 30002 -w1)
      echo $output
      echo $output | grep Wrong >/dev/null
      if [ $? -eq 0 ]; then
        echo "$i$j$k$l: FAILED.."
      else
        echo "$i$j$k$l: SUCCESS!"
      fi
    done
  done
done
