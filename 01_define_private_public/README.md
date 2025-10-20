# Example 01: Private and Public Access Control

This example demonstrates the standard C++ access control mechanism using `private` and `public` keywords.

## Overview

The `BlackBox` class has a private member `secret_value` that cannot be accessed directly from outside the class. Instead, public getter and setter methods provide controlled access to the private data.

## Key Points

- Private members are encapsulated and hidden from external access
- Public methods provide the interface for interacting with the object
- This is the standard, recommended way to control access in C++
- Attempting to access `secret_value` directly would result in a compilation error

## Building and Running

```bash
cd 01_define_private_public
g++ -std=c++17 main.cpp -o example
./example
```

## Expected Output

```
Initial value: 42
Modified value: 100
```
