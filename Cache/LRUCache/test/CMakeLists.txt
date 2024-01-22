# Google Test
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)

FetchContent_MakeAvailable(googletest)

function(add_test_executable name)
  ADD_EXECUTABLE(${name} ${ARGN})
  TARGET_LINK_LIBRARIES(${name} lru_cache ${DEPS} gtest)
  ADD_TEST(NAME ${name} COMMAND ${name})
endfunction()

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)

add_test_executable(node_test
  node_test.cpp
)

add_test_executable(lru_test
  lru_test.cpp
)
