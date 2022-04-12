#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>


int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 2) {
            std::cerr << "Usage client <host>" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    boost::asio::io_context io;

    std::cout << "begin timer...!\n";
    boost::asio::steady_timer timer(io, boost::asio::chrono::seconds(5));

    timer.wait();

    std::cout << "end timer...\n";
    return 0;
}
