#include <iostream>
#include <boost/asio.hpp>


int main(int argc, char const *argv[])
{
    boost::asio::io_context io;

    std::cout << "begin timer...!\n";
    boost::asio::steady_timer timer(io, boost::asio::chrono::seconds(5));

    timer.wait();

    std::cout << "end timer...\n";
    return 0;
}
