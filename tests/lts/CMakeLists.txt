set(TESTS
  empty-graph
  one-edge
  cycle
)

# Copy the test data from the source directory to the build directory.

foreach(_test ${TESTS})
  foreach(_ext lts output)
    configure_file(
      ${CMAKE_CURRENT_SOURCE_DIR}/${_test}.${_ext}
      ${CMAKE_CURRENT_BINARY_DIR}/${_test}.${_ext}
      COPYONLY
    )
  endforeach(_ext)
endforeach(_test)

# Finally, add compilation targets for all of the test executables.

add_executable(lts/read test-lts.cc)
set_target_properties(
  lts/read
  PROPERTIES
  OUTPUT_NAME test-lts
)
target_link_libraries(lts/read hst)
foreach(_test ${TESTS})
  add_test(
    lts:read:${_test}
    bash -c "./test-lts < ${_test}.lts | cmp - ${_test}.output"
  )
endforeach(_test)
