cmake_minimum_required(VERSION 3.10)

project(asio-demo1)

find_package(Boost REQUIRED COMPONENTS system thread)
add_executable(server server.cpp)

add_executable(client client.cpp)


target_link_libraries(server 
    PRIVATE
        Boost::system
        Boost::thread
)

# target_link_libraries(client 
#     PRIVATE
#         Boost::system
# )