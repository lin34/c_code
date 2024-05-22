#include <vector>
#include <stdexcept>
#include <iostream>

int countNumbers(const std::vector<int>& sortedVector, int n)
{
    if(sortedVector.size() == 0){
        return 0;
    }
    if(sortedVector[0] > n){
        return 0;
    }
    if(sortedVector[sortedVector.size() - 1] < n){
        return sortedVector.size() - 1;
    }
    //binary search
    //find the first number greater than n
    int low = 0, high = sortedVector.size() - 1;
    while(low < high){
        int m = low + (high - low)/2;
        if(sortedVector[m] < n){
            low = m + 1;
        }
        else{
            high = m - 1;
        }
    }
    return low;
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 3, 5, 7 };
    std::cout << countNumbers(v, 4) << "should be 2";
}
#endif