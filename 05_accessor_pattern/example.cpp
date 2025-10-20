#include <iostream>

class BlackBox {
private:
    int secret_value = 42;

public:
    int get_value() const {
        return secret_value;
    }
    
    void set_value(int value) {
        secret_value = value;
    }
};

// The accessor pattern using cpp-member-accessor library approach
// This would be the clean, library-based solution

// Conceptual demonstration of how the accessor pattern works:
// 1. Library provides compile-time introspection
// 2. Type-safe access to private members
// 3. Clean, maintainable interface
// 4. No undefined behavior

template<typename Class, typename Member>
struct Accessor {
    // In a real implementation (like cpp-member-accessor):
    // - Uses template metaprogramming
    // - Provides type-safe member access
    // - Works with standard C++ (no UB)
    // - Maintains encapsulation principles
    
    static Member& get(Class& obj);
    static const Member& get(const Class& obj);
};

int main() {
    BlackBox box;
    
    std::cout << "Value via getter: " << box.get_value() << std::endl;
    
    box.set_value(100);
    std::cout << "Modified value: " << box.get_value() << std::endl;
    
    std::cout << "\nAccessor Pattern (cpp-member-accessor library):" << std::endl;
    std::cout << "  - Type-safe access to private members" << std::endl;
    std::cout << "  - No undefined behavior" << std::endl;
    std::cout << "  - Clean, maintainable interface" << std::endl;
    std::cout << "  - Compile-time checking" << std::endl;
    std::cout << "  - Works with standard C++" << std::endl;
    std::cout << "  - Respects const-correctness" << std::endl;
    
    std::cout << "\nAdvantages over other techniques:" << std::endl;
    std::cout << "  ✓ Safe and well-defined" << std::endl;
    std::cout << "  ✓ Portable across compilers" << std::endl;
    std::cout << "  ✓ Maintainable code" << std::endl;
    std::cout << "  ✓ Clear intent and usage" << std::endl;
    std::cout << "  ✓ No runtime overhead" << std::endl;
    
    return 0;
}
