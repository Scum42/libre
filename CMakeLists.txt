cmake_minimum_required(VERSION 2.8.1)

set(PROJECT_NAME "Libre")
set(DEMO_NAME "LibreDemo")

set(SDL "${CMAKE_SOURCE_DIR}/extlib/SDL2-2.0.5")
set(SDL_IMAGE "${CMAKE_SOURCE_DIR}/extlib/SDL2_image-2.0.1")
set(BOX2D "${CMAKE_SOURCE_DIR}/extlib/Box2D")

set(SDL_INCLUDE "${SDL}/include")
set(SDL_IMAGE_INCLUDE "${SDL_IMAGE}/include")
set(BOX2D_INCLUDE "${BOX2D}/include")
set(LIBRE_INCLUDE "${CMAKE_SOURCE_DIR}/libre")

set(SDL_LIB "${SDL}/lib/x86")
set(SDL_IMAGE_LIB "${SDL_IMAGE}/lib/x86")
set(BOX2D_LIB "${BOX2D}/lib")

project(${PROJECT_NAME})

include_directories(
	${SDL_INCLUDE}
	${BOX2D_INCLUDE}
	${SDL_IMAGE_INCLUDE}
	${LIBRE_INCLUDE}
)

link_directories(
	${SDL_LIB}
	${BOX2D_LIB}
	${SDL_IMAGE_LIB}
)

FILE(GLOB LIBRE_SOURCES libre/*)
FILE(GLOB DEMO_SOURCES libreDemo/*)

add_library(
    ${PROJECT_NAME}
    ${LIBRE_SOURCES}
)

add_executable(
	${DEMO_NAME}
	${DEMO_SOURCES}
)

target_link_libraries(
	${PROJECT_NAME}
	SDL2
	SDL2_image
	Box2D-debug
)

target_link_libraries(
	${DEMO_NAME}
	${PROJECT_NAME}
)

add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${SDL_LIB}/SDL2.dll"
	"${CMAKE_CURRENT_BINARY_DIR}/$<CONFIGURATION>"
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${SDL_IMAGE_LIB}/SDL2_image.dll"
	"${CMAKE_CURRENT_BINARY_DIR}/$<CONFIGURATION>"
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${SDL_IMAGE_LIB}/libpng16-16.dll"
	"${CMAKE_CURRENT_BINARY_DIR}/$<CONFIGURATION>"
)