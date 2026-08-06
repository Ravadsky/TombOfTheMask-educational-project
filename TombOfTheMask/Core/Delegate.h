#pragma once
#include <functional>
#include <vector>

using FCallback = std::function<void(Args...)>;

template <typename... Args>
class FDelegate
{
public:
    template <typename funcClass>
    void Add(funcClass* obj, void (funcClass::*method)(Args...))
    {
        Add([obj, method](Args... arguments) { obj->method(arguments...) });
    }

    inline void Broadcast(Args... arguments) const
    {
        for (const auto& callback : callbacks)
        {
            if (callback != nullptr)
                callback(arguments);
        }
    }

    inline void Clear() { callbacks.clear(); }

private:
    inline void Add(FCallback callback) { callbacks.push_back(callback); }

    std::vector<FCallback> callbacks;
};