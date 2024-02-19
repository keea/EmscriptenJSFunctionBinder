cmake_minimum_required(VERSION 3.13)
project(EmscriptenJSFunctionBinder)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

add_executable(EmscriptenJSFunctionBinder
    ${SRC}
)

if(EMSCRIPTEN)
  set_target_properties(EmscriptenJSFunctionBinder PROPERTIES SUFFIX ".html")
  target_link_options(EmscriptenJSFunctionBinder PRIVATE "-sUSE_WEBGPU=1")
endif()