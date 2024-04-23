#include <pepito/pepito.h>
#include <iostream>

namespace pepito {

    void echo(const std::string& name) {
        std::cout << "Hello, " << name << "\n";
    }

}