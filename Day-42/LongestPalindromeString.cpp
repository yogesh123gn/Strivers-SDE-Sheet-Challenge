/* Problem : Longest Palindrome  String
Time Complexity : O(N^2)
Space Complexity : O(N^2)
*/


class Solution {
    int solve(int i, int j, string &s) {
        int l = i, r = j, n = s.size();
        while(l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        return i - l;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size(), oddSize = 0, evenSize = 0, evenCentre, oddCentre;

        for(int i = 0; i < n; i++) {
            int l = solve(i, i, s);
            if(l > oddSize) {
                oddCentre = i;
                oddSize = l;
            }
            if(i == n - 1) break;
            l = solve(i, i + 1, s);
            if(l > evenSize) {
                evenCentre = i;
                evenSize = l;
            }
        }
       
        string odd = s.substr(oddCentre - oddSize + 1, oddSize * 2 - 1);
        string even = evenSize ? s.substr(evenCentre - evenSize + 1, evenSize * 2) : "";
        
        return even.size() > odd.size() ? even : odd;
    }
};
