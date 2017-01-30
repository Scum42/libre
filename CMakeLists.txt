cmake_minimum_required(VERSION 2.8.1)

set(PROJECT_NAME "libre")

set(SDL "extlib/SDL2-2.0.5")
set(BOX2D "extlib/Box2D")

project(${PROJECT_NAME})

include_directories(
	"${SDL}/include"
	"${BOX2D}/include"
)

link_directories(
	"${SDL}/lib/x86"
	"${BOX2D}/lib"
)

FILE(GLOB SOURCES src/*)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
)

target_link_libraries(
	${PROJECT_NAME}
	SDL2
	Box2D-release
)