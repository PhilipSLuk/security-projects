

set(command "${make}")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/pelib-project-stamp/pelib-project-build-out.log"
  ERROR_FILE "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/pelib-project-stamp/pelib-project-build-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/pelib-project-stamp/pelib-project-build-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "pelib-project build command succeeded.  See also /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/pelib-project-stamp/pelib-project-build-*.log")
  message(STATUS "${msg}")
endif()
