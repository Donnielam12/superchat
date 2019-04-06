#include <asio.hpp>
#include <iostream>

int main(){
    asio::io_context io;
    tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve(argv[1], argv[2]);
    tcp::socket socket=&io;
    
    return 0;
}