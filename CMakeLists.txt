cmake_minimum_required(VERSION 2.6)

project(LuaGrip)

find_package(Lua51 REQUIRED)
include_directories(${LUA_INCLUDE_DIR})
set(LIBS ${LIBS} ${LUA_LIBRARIES})

set(CMAKE_CXX_FLAG "-Wall")
file(GLOB SOURCE_FILE *.cpp)

add_library(luagrip ${SOURCE_FILE})
target_link_libraries(luagrip ${LIBS})

INSTALL(FILES luagrip.hpp DESTINATION include/luagrip)
INSTALL(FILES libluagrip.pc DESTINATION /usr/lib/pkgconfig/)
INSTALL(TARGETS luagrip LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
