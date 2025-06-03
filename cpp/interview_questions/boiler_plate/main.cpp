#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
class MathUtils
{
public:
    static double average(double a, double b)
    {
        return (a + b) / 2;
    }
};

#ifndef RunTests
int main()
{
    double ans = MathUtils::average(2, 1);
    std::cout << ans;
    assert(ans == 1.5);
}
#endif