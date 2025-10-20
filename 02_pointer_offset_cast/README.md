# Example 02: Pointer Offset Cast

This example demonstrates accessing private members through pointer arithmetic and type casting.

## Overview

This technique uses `reinterpret_cast` and pointer arithmetic to access private members by calculating their offset in memory. This is a **dangerous and unreliable** approach.

## Key Points

- **Undefined Behavior**: This violates C++ standards and is technically undefined behavior
- **Platform Dependent**: Memory layout can vary between compilers, platforms, and optimization levels
- **Fragile**: Changes to class structure break this approach immediately
- **Dangerous**: Can lead to crashes, data corruption, and security vulnerabilities
- **Not Maintainable**: Extremely difficult to maintain and debug

## Why This is Bad

1. Memory layout is not guaranteed by the C++ standard
2. Compiler optimizations can reorder members
3. Padding and alignment can change
4. Different compilers may lay out memory differently
5. Virtual functions add hidden vtable pointers

## Building and Running

```bash
cd 02_pointer_offset_cast
g++ -std=c++17 example.cpp -o example
./example
```

## Expected Output

```
Value via getter: 42
Value via offset cast: 42

WARNING: This approach is:
  - Undefined behavior
  - Platform dependent
  - Fragile and breaks easily
  - Not recommended for production code!
```

**Note**: While this may work on some platforms, it's fundamentally unsafe and should never be used in production code.
