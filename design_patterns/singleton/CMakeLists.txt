cmake_minimum_required(VERSION 2.3)

project(singleton)
add_library(DEPS STATIC singleton_thread_safe.cpp )
add_executable(singleton main.cpp )
target_link_libraries(singleton PUBLIC DEPS)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)

if(THREAD_SAFE)
    add_definitions(-DTHREAD_SAFE)
endif()
