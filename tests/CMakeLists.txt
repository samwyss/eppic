# inspired by https://matgomes.com/integrate-google-test-into-cmake/

# setup ----------------------------------------------------------------------------------------------------------------
include(FetchContent)

# dependencies ---------------------------------------------------------------------------------------------------------
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
        EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(googletest)

# compiling and linking ------------------------------------------------------------------------------------------------
add_executable(example_test example_test.cpp)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

target_link_libraries(example_test
        PRIVATE
        GTest::GTest
        Core)

# tests ----------------------------------------------------------------------------------------------------------------
add_test(example_gtests example_test)