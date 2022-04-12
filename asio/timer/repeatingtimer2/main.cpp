#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>


class Printer {
    public:
    Printer(boost::asio::io_context& io): timer(boost::asio::steady_timer(io, boost::asio::chrono::seconds(1))), count(0) {
        timer.async_wait(boost::bind(&Printer::print, this));
    }
    ~ Printer() {
        std::cout << "Final count is " << count << std::endl;
    }

    void print() {
        if (count < 5) {
             std::cout  << count << std::endl;
             ++count;
             timer.expires_at(timer.expiry() + boost::asio::chrono::seconds(1));
             timer.async_wait(boost::bind(&Printer::print, this));
        }
    }
    private:
    boost::asio::steady_timer timer;
    int count;
};

int main(int argc, char const *argv[])
{

    boost::asio::io_context io;
    Printer p(io);
    io.run();

    return 0;
}
