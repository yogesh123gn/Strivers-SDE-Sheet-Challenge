//Problem :- Kadane's Algorithm (Maximum Subarray)
/* 
Brute Force Approach : Looping through each sunarray and finding sum to return maximum sum  Time Complexity :O(N^3) Space Complexity : O(1)

Better Approach :   If we carefully observe, we can notice that to get the sum of the current subarray we just need to add 
the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1]. Time Complexity : O(N^2) Space Complexity : O(1)

Optimal Approach : i)We will run a loop(say i) to iterate the given array.
ii)Now, while iterating we will add the elements to the sum variable and consider the maximum one.
iii)If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer. 
Time Complexity : O(N) => where N is size of input
Space Complexity : O(1) 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
          sum += nums[i];
          maxi = max(sum,maxi);
          if(sum < 0)
          {
              sum = 0;
          }
        }
        return maxi;
    }
};