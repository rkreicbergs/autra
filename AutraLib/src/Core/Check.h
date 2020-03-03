#pragma once

#include <stdexcept>

#define CHECK_TRUE(condition, message) CheckTrue((condition), __FILE__, __LINE__, (message))

namespace AutraLib
{ 
    inline void CheckTrue(bool condition, const char* fname, int line, const char* message)
    {
        if (!condition)
        {
            throw std::runtime_error(message);
        }
    }
}
