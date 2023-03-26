if(CONFIG_POSTFORM)
  zephyr_library()

  set(postform_dir ${ZEPHYR_POSTFORM_MODULE_DIR})

  # Get version number
  execute_process(
    COMMAND git describe
    WORKING_DIRECTORY ${postform_dir}
    OUTPUT_STRIP_TRAILING_WHITESPACE
    OUTPUT_VARIABLE POSTFORM_VERSION)
  message(VERBOSE "postform version is ${POSTFORM_VERSION}")

  zephyr_library_sources(
    ${postform_dir}/libpostform/src/file_logger.cpp
    ${postform_dir}/libpostform/src/format_validator.cpp
    ${postform_dir}/libpostform/src/macros.cpp
    ${postform_dir}/libpostform/src/platform.cpp
    ${postform_dir}/libpostform/src/rtt/transport.cpp)

  zephyr_include_directories(
    ${postform_dir}/libpostform/inc
  )

  zephyr_linker_sources(SECTIONS ${postform_dir}/libpostform/postform_zephyr.ld)

  set_source_files_properties(
    ${postform_dir}/libpostform/src/platform.cpp
    PROPERTIES
    COMPILE_FLAGS -DPOSTFORM_COMMIT_ID=${POSTFORM_VERSION}
  )

  zephyr_compile_options($<$<COMPILE_LANGUAGE:CXX>:-std=gnu++20>)

endif()
