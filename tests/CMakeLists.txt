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
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

# field/scalar ------------------------------------------------------------------------------------------------
add_executable(field_scalar field_scalar.cpp)
target_include_directories(field_scalar PRIVATE ../src/fields)
target_link_libraries(field_scalar PRIVATE GTest::GTest PRIVATE Fields)
add_test(NAME field_scalar COMMAND field_scalar)