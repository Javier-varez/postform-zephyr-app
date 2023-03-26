if(CONFIG_CORTEX_M_ATOMIC_POLYFILL)
  zephyr_library()

  set(cortex_m_atomics_dir ${ZEPHYR_CORTEX_M_ATOMICS_MODULE_DIR})

  zephyr_library_sources(
    ${cortex_m_atomics_dir}/src/atomic.cpp
  )

endif()
