set(command "/usr/bin/cmake;-P;/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/jsoncpp-project-stamp/download-jsoncpp-project.cmake")

execute_process(COMMAND ${command} RESULT_VARIABLE result)
if(result)
  set(msg "Command failed (${result}):\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  message(FATAL_ERROR "${msg}")
endif()
set(command "/usr/bin/cmake;-P;/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/jsoncpp-project-stamp/verify-jsoncpp-project.cmake")

execute_process(COMMAND ${command} RESULT_VARIABLE result)
if(result)
  set(msg "Command failed (${result}):\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  message(FATAL_ERROR "${msg}")
endif()
set(command "/usr/bin/cmake;-P;/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/jsoncpp-project-stamp/extract-jsoncpp-project.cmake")

execute_process(COMMAND ${command} RESULT_VARIABLE result)
if(result)
  set(msg "Command failed (${result}):\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  message(FATAL_ERROR "${msg}")
endif()