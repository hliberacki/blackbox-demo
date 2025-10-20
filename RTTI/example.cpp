#include <iostream>
#include <memory>

#ifdef TEST_ACCESS_PRIVATE
#define private public
#endif

class Interface
{
public:
    virtual ~Interface() = default;
    virtual void run() const = 0;
};

class ImplementationBase : private Interface
{
public:
    void run() const override { std::cout << "ImplementationBase::run()\n"; }
};

class ServiceImpl : public ImplementationBase
{
public:
    void specificLogic() const
    {
        std::cout << "ServiceImpl::specificLogic()\n";
    }
};

void framework_api(Interface *iface)
{
    std::cout << "framework_api: trying dynamic_cast<ServiceImpl*>...\n";
    if (auto *s = dynamic_cast<ServiceImpl *>(iface))
    {
        std::cout << "→ dynamic_cast<ServiceImpl*> succeeded\n";
        s->specificLogic();
    }
    else
    {
        std::cout << "→ dynamic_cast<ServiceImpl*> failed\n";
    }

    iface->run();
}

int main()
{
    ServiceImpl impl;
    Interface *iface = reinterpret_cast<Interface *>(&impl);

    framework_api(iface);
}
