#ifndef __ERROR__
#define __ERROR__

#include <string>
#include <iostream>

int error(std::string message, std::string from = "Error") {
    std::cout << from << ": " << message << std::endl;
    return 0;
}

#endif