

set(command "/usr/bin/perl;/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl/Configure;no-shared;no-asm;--prefix=/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl-install;--openssldir=/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl-install;linux-x86_64")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl-stamp/openssl-configure-out.log"
  ERROR_FILE "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl-stamp/openssl-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl-stamp/openssl-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "openssl configure command succeeded.  See also /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl-stamp/openssl-configure-*.log")
  message(STATUS "${msg}")
endif()
