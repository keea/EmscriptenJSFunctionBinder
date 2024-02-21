cmake_minimum_required(VERSION 3.13)
project(EmscriptenJSFunctionBinder)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

add_executable(EmscriptenJSFunctionBinder
    ${SRC}
)

if(EMSCRIPTEN)
  set(LOPTS "${LOPTS} -lembind")
  set(LOPTS "${LOPTS} -s MODULARIZE=1")
  set(LOPTS "${LOPTS} -s 'EXPORT_NAME=\"createModule\"'")
  set_target_properties(EmscriptenJSFunctionBinder
        PROPERTIES 
        LINK_FLAGS ${LOPTS}
  )
endif()