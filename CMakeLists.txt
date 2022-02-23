cmake_minimum_required(VERSION 3.22)
project(cubic C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
IF (WIN32)
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mwindows")
ENDIF ()

include_directories(src)

file(GLOB_RECURSE core-sources CONFIGURE_DEPENDS "src/cubic-core/*.c")
file(GLOB_RECURSE server-sources CONFIGURE_DEPENDS "src/cubic-server/*.c")
file(GLOB_RECURSE client-sources CONFIGURE_DEPENDS "src/cubic-client/*.c")

add_library(cubic-core ${core-sources})
IF (WIN32)
    target_link_libraries(cubic-core ws2_32)
ENDIF ()

add_executable(cubic-server ${server-sources})
target_link_libraries(cubic-server cubic-core)

add_executable(cubic-client ${client-sources})
IF (WIN32)
    target_link_libraries(cubic-client cubic-core opengl32 glew32 glfw3)
ELSE ()
    target_link_libraries(cubic-client cubic-core GL GLEW glfw)
ENDIF ()