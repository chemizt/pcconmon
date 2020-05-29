#include <iostream>

#include <boost/asio.hpp>

int main()
{
    std::cout << "Hi World, I'm Agent" << std::endl;
    
    boost::asio::io_service service;

    return 0;
}