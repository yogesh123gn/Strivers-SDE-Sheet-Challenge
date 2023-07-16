/* Problem : Reverse words in a string
Time Complexity : O(N)
Space Complexity : O(1)
*/


class Solution {
public:
    string reverseWords(string s) {

        string temp = "";
        string ans = "";

        // making left point to first non space char
        int left = 0;
        while (s[left] == ' ') {
            left++;
        }

        // making right point to last non space char
        int right = s.length() - 1;
        while (s[right] == ' ') {
            right--;
        }

        while (left <= right) {
            if (s[left] != ' ') {
                temp += s[left];
            }
            else {
                if (s[left - 1] == ' ') {
                    left++;
                    continue;
                }
                else {
                    ans = temp + " " + ans;
                    temp = "";
                }
            }
            left++;
        }
        ans = temp + " " + ans;
        ans.erase(ans.begin() + ans.length() - 1); // to erase extra space at the end
        return ans;
    }
};
