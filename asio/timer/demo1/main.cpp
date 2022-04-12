#include <iostream>
#include <boost/asio.hpp>


void init() {


}
int main(int argc, char const *argv[])
{
    init();

    boost::asio::io_service io_svc;
    boost::asio::io_service::work worker(io_svc);
    io_svc.run();
    std::cout << "We will see this line in console window.\n";
    return 0;
}
