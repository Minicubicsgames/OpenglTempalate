cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)
project(LearnOpenglTutorial)

if(MSVC)
    add_compile_options(/utf-8)
endif()

if(WIN32)
    add_compile_definitions(OS_WINDOWS)
elseif(APPLE)
    add_compile_definitions(OS_MACOS)
elseif(UNIX)
    add_compile_definitions(OS_LINUX)
elseif(ANDROID)
    add_compile_definitions(OS_ANDROID)
endif()

file(GLOB_RECURSE SRC "src/*.cpp" "src/*.c")

include_directories("${CMAKE_SOURCE_DIR}/include")
link_directories("${CMAKE_SOURCE_DIR}/lib")

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} glfw3)
target_link_libraries(${PROJECT_NAME} spdlog)
target_link_libraries(${PROJECT_NAME} imgui)