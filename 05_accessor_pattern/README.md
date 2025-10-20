# Example 05: Accessor Pattern (cpp-member-accessor)

This example demonstrates the recommended approach using a proper accessor library like cpp-member-accessor.

## Overview

The accessor pattern, as implemented by libraries like cpp-member-accessor, provides a clean, safe, and maintainable way to access private members when needed (e.g., for testing, serialization, or reflection).

## Key Points

- **Type-Safe**: Full compile-time type checking
- **No UB**: Works within the C++ standard, no undefined behavior
- **Maintainable**: Clear, understandable code
- **Portable**: Works across different compilers and platforms
- **Zero Overhead**: No runtime performance penalty
- **Const-Correct**: Properly handles const and non-const access

## How It Works

1. Library uses template metaprogramming
2. Provides explicit, type-safe accessor interface
3. Respects C++ access control principles
4. Enables controlled access for specific use cases

## Advantages Over Previous Examples

### vs. Pointer Offset Cast (Example 02)
- ✓ No undefined behavior
- ✓ Platform independent
- ✓ Compiler optimizations don't break it

### vs. Friend Injection (Example 03)
- ✓ More portable across compilers
- ✓ Clearer intent
- ✓ Easier to maintain

### vs. Template Alias Trick (Example 04)
- ✓ Complete solution, not just framework
- ✓ No need for additional hacks
- ✓ Better type safety

## Use Cases

1. **Unit Testing**: Access private state for thorough testing
2. **Serialization**: Serialize/deserialize private data
3. **Reflection**: Implement reflection systems
4. **Debugging**: Inspect internal state
5. **Migration**: Gradually refactor legacy code

## Building and Running

```bash
cd 05_accessor_pattern
g++ -std=c++17 example.cpp -o example
./example
```

## Expected Output

```
Value via getter: 42
Modified value: 100

Accessor Pattern (cpp-member-accessor library):
  - Type-safe access to private members
  - No undefined behavior
  - Clean, maintainable interface
  - Compile-time checking
  - Works with standard C++
  - Respects const-correctness

Advantages over other techniques:
  ✓ Safe and well-defined
  ✓ Portable across compilers
  ✓ Maintainable code
  ✓ Clear intent and usage
  ✓ No runtime overhead
```

## Recommendation

For production code that needs controlled access to private members, use a proper library solution like cpp-member-accessor rather than ad-hoc techniques.
