/*  Problem : Merge Overlapping Subarrays

approach :
i) Sort the given array in increasing order
ii) Compare the second element of previous interval with first element of current interval. If previous > current then merge the intervals.

Time Complexity : O(N*logN) + O(N)
Space Complexity : O(N)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(); 

    
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);
        }
        
        else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
    }
};
