#include "helper.hpp"
#include <iostream>

int main() {
    BlackBox box;
    
    std::cout << "Initial value: " << box.get_value() << std::endl;
    
    box.set_value(100);
    std::cout << "Modified value: " << box.get_value() << std::endl;
    
    // Cannot access private member directly:
    // std::cout << box.secret_value << std::endl;  // Compilation error!
    
    return 0;
}
