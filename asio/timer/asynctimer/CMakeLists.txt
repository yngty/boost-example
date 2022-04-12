cmake_minimum_required(VERSION 3.10)

project(async-timer)

find_package(Boost REQUIRED COMPONENTS system thread)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}  
    PRIVATE
        Boost::system
        Boost::thread
)