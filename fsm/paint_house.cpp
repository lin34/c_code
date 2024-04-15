// https://leetcode.com/problems/paint-house/description/
class Solution
{
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs)
    {
        // write your code here
        /*
        Adjacent houses cannot be the same color
        paint cost is specific to each house
        find minimum cost
        dynamic programming, use an n by 3 cache
        */
        int n = costs.size();
        vector<vector<int>> dp; // n by 3
        // how to index the dp? n = house, c = color. dp[n][c]
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dp[i][0] = costs[i][0];
                dp[i][1] = costs[i][1];
                dp[i][2] = costs[i][1];
            }
            else
            {
                dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
                dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
                dp[i][2] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};