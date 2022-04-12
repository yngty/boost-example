#include <iostream>
#include <boost/asio.hpp>

void print(const boost::system::error_code& e) {
    std::cout << e.message() << std::endl;
}
int main(int argc, char const *argv[])
{
    boost::asio::io_context io;

    std::cout << "begin timer...!\n";
    boost::asio::steady_timer timer(io, boost::asio::chrono::seconds(5));

    timer.async_wait(&print);
    io.run();
    std::cout << "end timer...\n";
    return 0;
}
