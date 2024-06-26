/*
Q6
The caching feature of the FunctionCache class does not work in the implementation provided.

Find and fix the bug.
*/
#include <iostream>
#include <unordered_map>
#include <memory>
#include <functional>
#include <tuple>
#include <string>
#include <utility>

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
        auto args = std::make_tuple(first, second);
        auto it = calculations.find(args);
        if (it != calculations.end())
            return it->second;

        int calculation = function(first, second);
        calculations[args] = calculation;
        return calculation;
    }

private:
    typedef std::tuple<int, int> key_t;

    struct key_hash : public std::unary_function<key_t, std::size_t>
    {
        std::size_t operator()(const key_t& k) const
        {
            return std::get<0>(k) ^ std::get<1>(k);
        }
    };
    struct key_equal : public std::binary_function<key_t, key_t, bool>
    {
        bool operator()(const key_t& v0, const key_t& v1) const
        {
            return (
            std::get<0>(v0) == std::get<0>(v1) &&
            std::get<1>(v0) == std::get<1>(v1)
        );
        }
    };

    typedef std::unordered_map<const key_t,int,key_hash,key_equal> map_t;
    //                                             ^ this is our custom hash

    map_t calculations;
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