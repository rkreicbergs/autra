#pragma once

#include <vector>

namespace AutraLib
{
    class Register
    {
    public:
        const int from;
        const int to;
        static std::vector<Register> RegisterPool;
        Register(int from, int to);

        static void LoadData();
    };
}
