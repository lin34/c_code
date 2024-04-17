/*
User
Write a method that, efficiently with respect to time used, finds the first product in a vector that occurs only once in that vector. If there are no unique products in the vector, an empty string should be returned.

For example, for vector products containing ("Apple", "Computer", "Apple", "Bag"), firstUniqueProduct(products) should return 'Computer'.
*/
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string firstUniqueProduct(const std::vector<std::string> &products)
{
    // Create a hash map to store product counts
    std::unordered_map<std::string, int> productCounts;

    // Count occurrences of each product
    for (const std::string &product : products)
    {
        productCounts[product]++;
    }

    // Find the first product with count 1
    for (const std::string &product : products)
    {
        if (productCounts[product] == 1)
        {
            return product; // Return the first unique product
        }
    }

    // No unique product found, return an empty string
    return "";
}

#ifndef RunTests
int main()
{
    std::vector<std::string> products = {"Apple", "Computer", "Apple", "Bag"};
    std::cout << firstUniqueProduct(products);
    return 0;
}
#endif
