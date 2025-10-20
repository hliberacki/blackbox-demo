#include <iostream>

class BlackBox {
private:
    int secret_value = 42;

public:
    int get_value() const {
        return secret_value;
    }
};

// Friend injection technique - exploiting template instantiation
template<typename Tag, typename Member>
struct AccessPrivate {
    friend Member get_member(Tag) {
        return Member{};
    }
};

// Tag for identifying the member we want to access
struct SecretValueTag {};

// Explicit instantiation that "injects" the friend function
template struct AccessPrivate<SecretValueTag, int BlackBox::*>;

// Declaration of the friend function (now accessible)
int BlackBox::* get_member(SecretValueTag);

// Helper function to access the private member
int access_secret_value(const BlackBox& box) {
    auto member_ptr = get_member(SecretValueTag{});
    return box.*member_ptr;
}

int main() {
    BlackBox box;
    
    std::cout << "Value via getter: " << box.get_value() << std::endl;
    
    // This technique requires knowing the exact member pointer at compile time
    // and exploits friend injection, which is a gray area in C++
    std::cout << "\nNOTE: Friend injection technique:" << std::endl;
    std::cout << "  - Exploits template instantiation mechanics" << std::endl;
    std::cout << "  - Works in a gray area of the standard" << std::endl;
    std::cout << "  - May not work on all compilers" << std::endl;
    std::cout << "  - Requires careful setup and maintenance" << std::endl;
    
    // Note: The actual access won't work without explicit member pointer initialization
    // This is a demonstration of the concept
    
    return 0;
}
