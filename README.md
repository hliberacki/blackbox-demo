# cpp-blackbox-demo

Demo repository showcasing various techniques for accessing private data in C++ classes, highlighting issues with different patterns and demonstrating the cpp-member-accessor library approach.

## Overview

This repository contains examples for a presentation about the cpp-member-accessor library and compares it with other (problematic) patterns for accessing private class members in C++.

## Structure

```
cpp-blackbox-demo/
├── 01_define_private_public/    # Standard private/public access control
│   ├── helper.hpp
│   ├── main.cpp
│   └── README.md
├── 02_pointer_offset_cast/      # Dangerous pointer arithmetic approach
│   ├── example.cpp
│   └── README.md
├── 03_friend_injection/         # Template-based friend injection
│   ├── example.cpp
│   └── README.md
├── 04_template_alias_trick/     # Template specialization approach
│   ├── example.cpp
│   └── README.md
├── 05_accessor_pattern/         # Recommended: cpp-member-accessor library
│   ├── example.cpp
│   └── README.md
└── CMakeLists.txt               # Build configuration for all examples
```

## Examples

### 01: Private/Public Access Control
The standard, recommended way to control access in C++ using `private` and `public` keywords. This is the baseline example showing proper encapsulation.

### 02: Pointer Offset Cast
Demonstrates accessing private members through pointer arithmetic - a **dangerous and unreliable** approach that relies on undefined behavior.

### 03: Friend Injection
Shows the friend injection technique that exploits template instantiation. While more clever, it's still a gray area of the standard and not portable.

### 04: Template Alias Trick
Uses template specialization to create type-specific accessors. More structured but still limited without additional hacks.

### 05: Accessor Pattern (Recommended)
Demonstrates the clean, safe approach using a proper accessor library like cpp-member-accessor. This is the recommended solution for controlled private member access.

## Building

### Requirements
- CMake 3.14 or higher
- C++17 compatible compiler (GCC, Clang, MSVC)

### Build Instructions

```bash
# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
make

# Run individual examples
./01_define_private_public
./02_pointer_offset_cast
./03_friend_injection
./04_template_alias_trick
./05_accessor_pattern
```

## Key Takeaways

| Technique | Safety | Portability | Maintainability | Recommendation |
|-----------|--------|-------------|-----------------|----------------|
| Standard Access Control | ✅ Safe | ✅ Portable | ✅ Easy | ✅ Use for normal cases |
| Pointer Offset Cast | ❌ UB | ❌ Platform-specific | ❌ Fragile | ❌ Never use |
| Friend Injection | ⚠️ Gray area | ⚠️ Compiler-dependent | ⚠️ Complex | ❌ Avoid |
| Template Alias | ⚠️ Incomplete | ✅ Portable | ⚠️ Verbose | ⚠️ Limited use |
| Accessor Pattern | ✅ Safe | ✅ Portable | ✅ Clear | ✅ Recommended |

## Use Cases for Accessor Pattern

- **Unit Testing**: Access private state for comprehensive testing
- **Serialization**: Serialize/deserialize private data members
- **Reflection**: Implement reflection and introspection systems
- **Debugging**: Inspect internal state during development
- **Legacy Code**: Gradually refactor while maintaining compatibility

## License

See [LICENSE](LICENSE) file for details.
