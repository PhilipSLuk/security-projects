

set(command "/usr/bin/cmake;-Dmake=${make};-Dconfig=${config};-P;/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-stamp/tinyxml2-project-download-Release-impl.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-stamp/tinyxml2-project-download-out.log"
  ERROR_FILE "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-stamp/tinyxml2-project-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-stamp/tinyxml2-project-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "tinyxml2-project download command succeeded.  See also /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-stamp/tinyxml2-project-download-*.log")
  message(STATUS "${msg}")
endif()
