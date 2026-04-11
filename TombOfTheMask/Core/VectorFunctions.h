#pragma once
#include "CoreMinimal.h"
#include <vector>
#include <algorithm>

// Очистка векторов слабых указателей
template <typename T> inline void ClearVectorForExpiredPtr(std::vector<std::weak_ptr<T>> vec)
{
    auto iter =
        std::remove_if(vec.begin(), vec.end(), [](const std::weak_ptr<T> &pointer) { return pointer.expired(); });
    vec.erase(iter, vec.end());
}