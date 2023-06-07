//Problem :- Next Permutation
/* 
Brute Force Approach : Compute all permutaions of given input 
Better Approach : Use "next_permutaion(firstIndex, lastIndex)" function from C++ STL
Optimal Approach : i) Find Break point in array from end such that at least one element is greater than current element.
ii) Swap current index element with elemnt just greater than it.
iii) Since array will be sorted in decreasing order simply reverse array using reverse() method.  
Time Complexity : O(N) => where N is No. of elements in array input
Space Complexity : O(1) 
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            reverse(nums.begin(),nums.end());
        }
        else{
             
             for(int i=n-1;i>index;i--)
            {
               if(nums[index] < nums[i])
               {
                swap(nums[index],nums[i]);
                break;
               }
            }

            reverse((nums.begin() + index + 1),nums.end());
        }

    }
};