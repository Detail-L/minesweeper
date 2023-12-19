cmake_minimum_required(VERSION 3.24)

project(Minesweeper)

aux_source_directory(./src ALL_SRCS)
include_directories(./src)
include(./3rdpart/ege/ege-config.cmake)

add_executable(minesweeper ${ALL_SRCS} ./rc/source.rc)
target_link_libraries(minesweeper EGE)
