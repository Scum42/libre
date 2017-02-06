cmake_minimum_required(VERSION 2.8.1)

set(PROJECT_NAME "libre")

set(SDL "${CMAKE_SOURCE_DIR}/extlib/SDL2-2.0.5")
set(BOX2D "${CMAKE_SOURCE_DIR}/extlib/Box2D")

set(SDL_INCLUDE "${SDL}/include")
set(BOX2D_INCLUDE "${BOX2D}/include")

set(SDL_LIB "${SDL}/lib/x86")
set(BOX2D_LIB "${BOX2D}/lib")

project(${PROJECT_NAME})

include_directories(
	${SDL_INCLUDE}
	${BOX2D_INCLUDE}
)

link_directories(
	${SDL_LIB}
	${BOX2D_LIB}
)

FILE(GLOB SOURCES src/*)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
)

target_link_libraries(
	${PROJECT_NAME}
	SDL2
	Box2D-debug
)

add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${SDL_LIB}/SDL2.dll"
	"${CMAKE_CURRENT_BINARY_DIR}/$<CONFIGURATION>"
)