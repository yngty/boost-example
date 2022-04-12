#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

void print(const boost::system::error_code& e, boost::asio::steady_timer* t, int* count) {
    if (*count < 5) {
        std::cout << *count << std::endl;
        ++(*count);
        t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
        t->async_wait(boost::bind(print, boost::asio::placeholders::error, t, count));
    }
}
int main(int argc, char const *argv[])
{
    int count {0};

    boost::asio::io_context io;

    boost::asio::steady_timer timer(io, boost::asio::chrono::seconds(1));

    timer.async_wait(boost::bind(print, boost::asio::placeholders::error, &timer, &count));
    io.run();

    std::cout << "Final count is " << count << std::endl;
    return 0;
}
