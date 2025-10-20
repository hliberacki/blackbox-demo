#include <iostream>
#include <cstddef>

class BlackBox {
private:
    int secret_value = 42;

public:
    int get_value() const {
        return secret_value;
    }
};

// Accessing private member using pointer offset cast
// WARNING: This is undefined behavior and highly fragile!
int access_private_via_offset(const BlackBox& box) {
    // Cast the object to a char pointer, then offset to the private member
    const char* base = reinterpret_cast<const char*>(&box);
    
    // Assuming secret_value is at offset 0 (depends on memory layout)
    const int* value_ptr = reinterpret_cast<const int*>(base);
    
    return *value_ptr;
}

int main() {
    BlackBox box;
    
    std::cout << "Value via getter: " << box.get_value() << std::endl;
    std::cout << "Value via offset cast: " << access_private_via_offset(box) << std::endl;
    
    std::cout << "\nWARNING: This approach is:" << std::endl;
    std::cout << "  - Undefined behavior" << std::endl;
    std::cout << "  - Platform dependent" << std::endl;
    std::cout << "  - Fragile and breaks easily" << std::endl;
    std::cout << "  - Not recommended for production code!" << std::endl;
    
    return 0;
}
