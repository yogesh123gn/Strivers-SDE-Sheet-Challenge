/* Problem : Valid Anagrams

Time Complexity: O(N)
Space Complexity: O(26);

*/


#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    int n = str1.length();
    int m = str2.length();

    if(n != m)
    {
        return (int)false;
    }
    
    int arr[26] = {0};

    for(int i=0;i<n;i++)
    {
        arr[str1[i] - 'a']++;
        arr[str2[i] - 'a']--;
    }

    for(int i=0;i<26;i++)
    {
        if(arr[i] != 0)
        {
            return (int)false;
        }
    }
    return (int)true;
}
