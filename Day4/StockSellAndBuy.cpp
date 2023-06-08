/* Problem : Buy and Sell Stock To gain Maximum Profit

Approach:
 i)Create a variable maxPro and store 0 initially.
 ii)Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.
 iii)Run a for loop from 0 to n.
 iv)Update the minPrice if it is greater than the current element of the array
 v)Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
 vi)Return the maxPro.

 Time Complexity: O(N) => N is array size
 Space Complexity : O(1)
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            mini = min(mini,prices[i]);
            profit = max(profit,prices[i]-mini);
        }
        return profit;
    }
};