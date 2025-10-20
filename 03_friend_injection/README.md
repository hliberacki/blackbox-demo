# Example 03: Friend Injection

This example demonstrates the friend injection technique, which exploits template instantiation to create friend functions at compile time.

## Overview

Friend injection is a technique that uses template instantiation to "inject" friend functions into a class, allowing access to private members. This exploits the C++ template system in a way that operates in a gray area of the standard.

## Key Points

- **Template Exploitation**: Uses template instantiation to create friend relationships
- **Compile-time Trick**: Relies on template mechanics rather than runtime hacks
- **Limited Portability**: May not work consistently across all compilers
- **Complex Setup**: Requires careful template programming
- **Gray Area**: While technically legal, it's questionable design

## How It Works

1. Define a template that declares a friend function
2. Instantiate the template with specific types
3. The friend function is "injected" during instantiation
4. This friend function can access private members

## Issues

1. Not all compilers handle friend injection the same way
2. Template complexity makes code harder to understand
3. Brittle - changes to the class require updating the injection code
4. May break with different compiler versions or standard modes

## Building and Running

```bash
cd 03_friend_injection
g++ -std=c++17 example.cpp -o example
./example
```

## Notes

This technique, while clever, is generally not recommended for production code. It trades clarity and maintainability for the ability to bypass access controls. Modern C++ has better alternatives for most use cases that require flexible access patterns.
