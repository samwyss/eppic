# CMake Setup ----------------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# EPPIC Setup
project(EPPIC
        VERSION 0.0.0
        LANGUAGES CXX
        HOMEPAGE_URL https://github.com/samwyss/eppic
)

# compiler flags -------------------------------------------------------------------------------------------------------
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("Building EPPIC using GNU compiler flags specified in CMakeLists.txt")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-O0 -Wall -g3)
    elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
        # may also add -fopt-info-vec-all for vectorization report
        add_compile_options(-O3 -g0 -DNDEBUG -Wall -fstrict-aliasing -ftree-vectorize -march=native -mtune=native -mprefer-vector-width=512 -fno-trapping-math -fno-math-errno -flto)
    elseif (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
        # may also add -fopt-info-vec-all for vectorization report
        add_compile_options(-O3 -g3 -Wall -fstrict-aliasing -ftree-vectorize -march=native -mtune=native -mprefer-vector-width=512 -fno-trapping-math -fno-math-errno -flto)
    endif ()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message("Building EPPIC using MSVC compiler flags specified in CMakeLists.txt")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(/Od /Zi)
    elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
        # may also add /Qvec-report:2 for vectorization report
        add_compile_options(/O2 /GL /arch:AVX512 /fp:contract /Gw /Gy)
        add_link_options(/LTCG:STATUS)
    elseif (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
        # may also add /Qvec-report:2 for vectorization report
        add_compile_options(/O2 /GL /arch:AVX512 /fp:contract /Gw /Gy /Zi)
        add_link_options(/LTCG:STATUS)
    endif ()
endif ()

# dependencies ---------------------------------------------------------------------------------------------------------
find_package(MPI REQUIRED COMPONENTS CXX)

# compiling and linking ------------------------------------------------------------------------------------------------
add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
        MPI::MPI_CXX
)

target_include_directories(${PROJECT_NAME}
        PRIVATE ${PROJECT_SOURCE_DIR}/src
        PRIVATE ${PROJECT_BINARY_DIR}
        PRIVATE ${MPI_CXX_INCLUDE_PATH}
        PRIVATE ${PROJECT_BINARY_DIR}
)