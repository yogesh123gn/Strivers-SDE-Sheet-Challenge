/* Count Number of Subarrays with given xor K 
Time complexity : o(N^2)
Space Complexity : O(N)
*/

#include<unordered_map>

 int subarraysWithSumK(vector < int > a, int b) {

    int n =a.size();

    unordered_map<int,int>mpp;

    int xorr =0;

    int cnt =0;

    for(int i =0; i<n ;i++){

         xorr =xorr^a[i];

        if(xorr==b){

            cnt++;

        }

        int x =xorr^b;

        if(mpp.find(x)!=mpp.end())

            cnt += mpp[x];

            mpp[xorr]++;

        }

    return cnt;

    }
