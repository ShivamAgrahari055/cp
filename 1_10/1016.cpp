
// Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.

// A substring is a contiguous sequence of characters within a string.

class Solution {
public:
    bool queryString(string s, int n) {

        for (int x = 1; x <= n; x++) {

            int num = x;
            string binary = "";

            while (num > 0) {
                binary += char('0' + num % 2);
                num /= 2;
            }

            reverse(binary.begin(), binary.end());

            if (s.find(binary) == string::npos)
                return false;
        }

        return true;
    }
};