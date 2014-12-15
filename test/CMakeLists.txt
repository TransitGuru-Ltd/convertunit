cmake_minimum_required(VERSION 2.8)

project(convertuint)

# uncomment to use clang as default compiler
# set(CC clang)

# set flags for warnings, errors, and standards
if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE release CACHE STRING
       "Choose the type of build, options are: None Debug Release RelWithDebInfo
        MinSizeRel."
       FORCE )
endif()

set(CSTD c11)
set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -g -std=${CSTD} -pedantic -pedantic-errors")
set(CMAKE_C_FLAGS_RELEASE "-Wall -Wextra -std=${CSTD} -pedantic -pedantic-errors -O3")

# build directories
set(CMAKE_BINARY_DIR build)
set(EXECUTABLE_OUTPUT_PATH bin)

# include and link directories
include_directories(../include)

# dependencies
# add_executable(some_exe main.c src1.c src2.c etc.c)
add_executable(test_bintree test_bintree.c ../src/bintree.c)


# run 'cmake -D GOPROF=true /path/to/this/dir' to use google profiler
if(GOPROF)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lprofiler")
endif(GOPROF)

# run 'cmake -D GPROF=true /path/to/this/dir' to use gnu profiler
if(GPROF)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
endif(GPROF)
