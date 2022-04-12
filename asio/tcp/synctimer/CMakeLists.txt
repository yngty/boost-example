cmake_minimum_required(VERSION 3.10)

project(tcp)

find_package(Boost REQUIRED COMPONENTS system thread)

add_executable(client client.cpp)

target_link_libraries(client 
    PRIVATE
        Boost::system
        Boost::thread
)