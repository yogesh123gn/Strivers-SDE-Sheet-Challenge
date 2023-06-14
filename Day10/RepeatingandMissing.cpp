/* Problem : Find Missing and Repeating number

Time Complexity : O(N)
Space Complexity: O(1)

*/

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
	
	
	long long SN = n*(n+1) / 2;
	long long S2N = (n*(n+1) * (2 * n+1)) / 6;

    long long S=0,S2=0;

	for(int i=0;i<n;i++)
	{
		S+=arr[i];
		S2+=(long long)arr[i] * (long long)arr[i];
	}
    
	long long val1 = S -SN;

	long long val2 = S2 - S2N;

	val2 /= val1;

	long long x = (val1+val2) / 2;
	long long y = x - val1;

	return {(int)y,(int)x};
}
