#include <iostream>
#include <type_traits>

#ifdef TEST_ACCESS_PRIVATE
#define private public
#endif

class Message
{
private:
    void serialize() const
    {
        std::cout << "[PRIVATE] serialize()\n";
    }
};

template <typename T>
concept HasSerialize = requires(const T &t) {
    t.serialize();
};

template <HasSerialize T>
void process(const T &obj)
{
    std::cout << "→ Using user-provided serialize()\n";
    obj.serialize();
}

template <typename T>
void process(const T &)
{
    std::cout << "→ Using fallback serializer\n";
}

int main()
{
    Message msg;
    process(msg);
}
