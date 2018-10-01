

set(command "make;-j1;install_sw")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl-stamp/openssl-install-out.log"
  ERROR_FILE "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl-stamp/openssl-install-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl-stamp/openssl-install-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "openssl install command succeeded.  See also /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/deps/openssl/openssl/src/openssl-stamp/openssl-install-*.log")
  message(STATUS "${msg}")
endif()
