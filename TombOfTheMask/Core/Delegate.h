#pragma once
#include <functional>
#include <vector>

template <typename... Args>
struct FDelegate
{
    using FCallback = std::function<void(Args...)>;

public:
    inline void Add(FCallback callback) { callbacks.push_back(callback); }

    template <typename funcClass>
    void Add(funcClass* obj, void (funcClass::*method)(Args...))
    {
        // Add([obj, method](Args... arguments) { obj->method(arguments...) });
        Add(FCallback([obj, method](Args... args) { (obj->*method)(args...); }));
    }

    inline void Broadcast(Args... arguments) const
    {
        for (const auto& callback : callbacks)
        {
            if (callback != nullptr)
                callback(arguments...);
        }
    }

    inline void Clear() { callbacks.clear(); }

private:
    std::vector<FCallback> callbacks;
};