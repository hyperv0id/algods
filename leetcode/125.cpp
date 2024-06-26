class Solution {
  public:
    bool isLetter(char &c) {
        // 变成小写
        if (c <= 'Z' && c >= 'A') {
            c -= 'A' - 'a';
        }
        return (c <= '9' && c >= '0') || (c <= 'z' && c >= 'a');
    }
    bool isPalindrome(string s) {

        if (s.length() <= 1) {
            return true;
        }
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (l < r && !isLetter(s[l])) {
                l++;
            }
            while (l < r && !isLetter(s[r])) {
                r--;
            }
            if (s[l] - s[r] != 0) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
