function(copy_runtime_dlls target)
  set(copy_command "copy_if_different;$<TARGET_RUNTIME_DLLS:${target}>;$<TARGET_FILE_DIR:${target}>")
  add_custom_command(TARGET ${target} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E "$<IF:$<BOOL:$<TARGET_RUNTIME_DLLS:${target}>>,${copy_command},true>"
    COMMAND_EXPAND_LISTS
  )
endfunction()

function(copy_file target)
  add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${ARGN} $<TARGET_FILE_DIR:${target}>
    COMMAND_EXPAND_LISTS
  )
endfunction()
