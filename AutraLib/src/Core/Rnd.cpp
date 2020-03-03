#include <random>

#include "Rnd.h"
#include "Check.h"

namespace AutraLib
{
    // Return a random integer 0 <= x < limit
    int RndInt(size_t limit)
    {
        static std::random_device rand_dev;
        static std::mt19937       generator(rand_dev());

        if (limit == 1)
        {
            return 0;
        }

        CHECK_TRUE(limit > 0, "Invalid Rnd limit!");
        std::uniform_int_distribution<int>  distr(0, (int)limit - 1);
        return distr(generator);
    }

    bool RndBool(int wTrue, int wFalse)
    {
        return RndInt(wTrue + wFalse) >= wFalse;
    }
}