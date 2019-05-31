cmake_minimum_required(VERSION 2.6)
project(OpenGL)
set(OpenGL_VERSION_MAJOR 0)
set(OpenGL_VERSION_MINOR 45)

configure_file (
"${PROJECT_SOURCE_DIR}/config.h.in"
"${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_library(MathFunctions mysqrt.cxx)



option(USE_MYMATH
"Use tut provided math implementation" ON)


if(USE_MYMATH)
	include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
	add_subDirectory(MathFunctions)
	set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)

add_executable(play main.cpp)
target_link_libraries(OpenGL &{EXTRA_LIBS})