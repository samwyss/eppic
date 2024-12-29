# CMake Setup ----------------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# EPPIC Setup
project(EPPIC
        VERSION 0.0.0
        LANGUAGES CXX
        HOMEPAGE_URL https://github.com/samwyss/eppic
)

# compiler flags -------------------------------------------------------------------------------------------------------
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-O0 -Wall -g3)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    # may also add -fopt-info-vec-all for vectorization report
    add_compile_options(-O3 -g0 -DNDEBUG -Wall -fstrict-aliasing -ftree-vectorize -march=native -mtune=native -mprefer-vector-width=512 -fno-trapping-math -fno-math-errno -flto)
elseif (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    # may also add -fopt-info-vec-all for vectorization report
    add_compile_options(-O3 -g3 -Wall -fstrict-aliasing -ftree-vectorize -march=native -mtune=native -mprefer-vector-width=512 -fno-trapping-math -fno-math-errno -flto)
endif ()

# dependencies ---------------------------------------------------------------------------------------------------------
find_package(MPI REQUIRED COMPONENTS CXX)

# compiling and linking ------------------------------------------------------------------------------------------------
add_executable(${PROJECT_NAME}
        src/main.cpp
)

add_library(Core
        ${PROJECT_SOURCE_DIR}/src/core/model.cpp
        ${PROJECT_SOURCE_DIR}/src/core/model.hpp
        ${PROJECT_SOURCE_DIR}/src/core/config.cpp
        ${PROJECT_SOURCE_DIR}/src/core/config.hpp
)

add_library(Utils)

add_library(Fields)

add_library(Constants
        ${PROJECT_SOURCE_DIR}/src/constants/physical.hpp
)

target_link_libraries(Core
        PUBLIC MPI::MPI_CXX
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE Core
        PRIVATE MPI::MPI_CXX
)

target_include_directories(Core
        PUBLIC ${MPI_CXX_INCLUDE_PATH}
)

target_include_directories(${PROJECT_NAME}
        PRIVATE ${PROJECT_BINARY_DIR}
        PRIVATE ${PROJECT_SOURCE_DIR}/src/core
        PRIVATE ${MPI_CXX_INCLUDE_PATH}
)