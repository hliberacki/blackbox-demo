#include <iostream>
#include <type_traits>

#ifdef TEST_ACCESS_PRIVATE
#define private public
#endif

class Message
{
private:
    void serialize() const { std::cout << "[PRIVATE] serialize()\n"; }
};

template <typename, typename = void>
struct has_serialize : std::false_type
{
};

template <typename T>
struct has_serialize<T, std::void_t<decltype(std::declval<T>().serialize())>>
    : std::true_type
{
};

template <typename T>
inline constexpr bool has_serialize_v = has_serialize<T>::value;

struct FallbackPolicy
{
    void run() const { std::cout << "FallbackPolicy::run()\n"; }
};

struct CustomPolicy
{
    void run() const { std::cout << "CustomPolicy::run()\n"; }
};

template <typename T>
struct PolicySelector : std::conditional_t<has_serialize_v<T>, CustomPolicy, FallbackPolicy>
{
};

struct TestNode : PolicySelector<Message>
{
    void execute() const { run(); }
};

int main()
{
    TestNode node;
    node.execute();
}
