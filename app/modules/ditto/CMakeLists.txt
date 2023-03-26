if(CONFIG_DITTO)
  zephyr_library()

  set(ditto_dir ${ZEPHYR_DITTO_MODULE_DIR})

  zephyr_library_sources(
    ${ditto_dir}/src/assert.cpp
    ${ditto_dir}/src/hash.cpp
    ${ditto_dir}/src/crc32c.cpp
    ${ditto_dir}/src/arch/arm.cpp
  )

  zephyr_include_directories(
    ${ditto_dir}/include
    ${CMAKE_CURRENT_LIST_DIR}
  )

endif()
