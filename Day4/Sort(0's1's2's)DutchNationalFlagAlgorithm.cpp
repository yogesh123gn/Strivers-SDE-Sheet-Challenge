/* Problem : Sort an Array of 0's 1's and 2's Also Known as
             Dutch National Flag Algorithm
This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.The rules are the following:
arr[0b &.low-1] contains 0. [Extreme left part]
arr[lowb &.mid-1] contains 1.
arr[high+1b &.n-1] contains 2. [Extreme right part], n = size of the array   

Approach :

First, we will run a loop that will continue until mid <= high.

There can be three different values of mid pointer i.e. arr[mid]
If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.

If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.

If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray from index high+1 to (n-1) only contains 2.

In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. So, we will check the value of mid again in the next iteration.

Finally, our array should be sorted.

Time Complexity :O(N) => N is size of array
Sapce Complexity : O(1) => constant space
*/



class Solution
{
public:
  void sortColors (vector < int >&nums)
  {
    int n = nums.size ();
    int low = 0, mid = 0, high = n - 1;
    for (int i = 0; i < n; i++)
      {
	if (nums[mid] == 0)
	  {
	    swap (nums[mid], nums[low]);
	    mid++;
	    low++;
	  }
	else if (nums[mid] == 1)
	  {
	    mid++;
	  }
	else
	  {
	    swap (nums[mid], nums[high]);
	    high--;
	  }
      }
  }
};
