cmake_minimum_required(VERSION 2.8)

project(mcp23017)

set (mcp23017_VERSION_MAJOR 1)
set (mcp23017_VERSION_MINOR 0)

add_library(${PROJECT_NAME} STATIC mcp23017.c mcp23017.h)

install(TARGETS mcp23017 DESTINATION lib)
install(FILES mcp23017.h DESTINATION include)