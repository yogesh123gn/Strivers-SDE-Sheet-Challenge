/* Problem : merge Two Sorted Arrays

Time Complexity : O((n+m)*log(n+m))
Space Complexity : O(1)

*/

#include<vector>
#include <bits/stdc++.h> 

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size();
	int m = b.size();
	reverse(a.begin(), a.end());
	int z = min(n, m);

	for(int i = 0; i < z; i++){
		if(a[i] > b[i]){
			swap(a[i], b[i]);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}
