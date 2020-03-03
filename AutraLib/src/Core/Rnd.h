#pragma once

#include <vector>

namespace AutraLib
{
    // Return a random integer 0 <= x < limit
    int RndInt(size_t limit);

    bool RndBool(int wTrue = 1, int wFalse = 1);

    template <class T>
    const T& GetRandomElement(const std::vector<T>& vector)
    {
        return vector.at(RndInt(vector.size()));
    }
}
