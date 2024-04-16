#include <iostream>
#include <vector>
#include <assert.h>
// https://www.testdome.com/tests/cpp-online-test/34#
std::vector<int> simulate(const std::vector<int> &entries)
{
    std::vector<int> ans = {};
    int size = entries.size();
    for (int i = 0; i < size; i++)
    {
        int pos_left = i - 3, pos_right = i + 4;
        if (pos_left >= 0 && pos_right < size)
        {
            if (entries[pos_left] >= entries[i] || entries[pos_right] >= entries[i])
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(entries[i]);
            }
        }
        else if ((pos_left < 0 && pos_right < size))
        {
            if (entries[pos_right] >= entries[i])
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(entries[i]);
            }
        }
        else if ((pos_right >= size && pos_left >= 0))
        {
            if (entries[pos_left] >= entries[i])
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(entries[i]);
            }
        }
        else
        {
            ans.push_back(entries[i]);
        }
    }
    assert(ans.size() == size);
    return ans;
}

#ifndef RunTests
int main()
{
    std::vector<int> result = simulate({1, 2, 0, 5, 0, 2, 4, 3, 3, 3});
    for (int value : result)
    {
        std::cout << value << " ";
    }
    // Expected output
    // 1, 0, 0, 5, 0, 0, 0, 3, 3, 0
}
#endif