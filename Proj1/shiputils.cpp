#include <ctime>
#include <cstdlib>

int getRand(int lower, int upper)
{
    int result = (rand()) % (upper+1) + lower;
    while (result < lower || result > upper)
    {
        result = (rand()) % (upper+1) + lower;
    }

    return result;
}