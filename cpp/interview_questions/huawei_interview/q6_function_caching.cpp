/*
The caching feature of the FunctionCache class does not work in the implementation provided.

Find and fix the bug.
*/
#include <iostream>
#include <unordered_map>
#include <memory>
#include <functional>

class FunctionCache
{
    class Parameters
    {
    public:
        Parameters(int first, int second)
        {
            this->first = first;
            this->second = second;
        }

        int first;
        int second;
    };

public:
    FunctionCache(std::function<int(int, int)> function) : function(function) {}

    int calculate(int first, int second)
    {
        auto args = std::make_shared<Parameters>(first, second);
        auto it = calculations.find(args);
        if (it != calculations.end())
            return it->second;

        int calculation = function(first, second);
        calculations[args] = calculation;
        return calculation;
    }

private:
    std::unordered_map<std::shared_ptr<Parameters>, int> calculations;
    std::function<int(int, int)> function;
};

#ifndef RunTests

int modulo(int a, int b)
{
    std::cout << "Function modulo has been called.\n";
    return a % b;
}

int main()
{
    FunctionCache cache(modulo);

    // Function modulo should be called.
    std::cout << cache.calculate(5, 2) << std::endl;

    // Function modulo should be called.
    std::cout << cache.calculate(7, 4) << std::endl;

    // Function modulo shouldn't be called because we have already made a call with arguments (5, 2)!
    std::cout << cache.calculate(5, 2) << std::endl;
}
#endif