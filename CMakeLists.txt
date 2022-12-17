cmake_minimum_required(VERSION 3.24)

project(archimedes_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (WIN32)
  add_definitions(-DABELIAN_WINDOWS)
elseif(APPLE)
  add_definitions(-DABELIAN_MAC)
else()
  add_definitions(-DABELIAN_LINUX)
endif()

add_definitions(-DABELIAN_DEBUG)
add_definitions(-DABELIAN_OPENGL)

add_subdirectory(Archimedes)
add_subdirectory(Abelian)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)

set(VS_STARTUP_PROJECT Archimedes)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR})
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)