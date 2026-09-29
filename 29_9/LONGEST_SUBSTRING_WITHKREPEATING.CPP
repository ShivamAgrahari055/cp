
// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

// if no such substring exists, return 0.s
class Solution {
public:

    int help(string &s, int l, int r, int k) {

        if(r - l + 1 < k)
            return 0;

        vector<int> cnt(26, 0);

        for(int i = l; i <= r; i++) {
            cnt[s[i] - 'a']++;
        }

        // Find a bad character
        for(int i = l; i <= r; i++) {

            if(cnt[s[i] - 'a'] < k) {

                int left = help(s, l, i - 1, k);
                int right = help(s, i + 1, r, k);

                return max(left, right);
            }
        }

        // Every character occurs at least k times
        return r - l + 1;
    }

    int longestSubstring(string s, int k) {

        return help(s, 0, s.size() - 1, k);
    }
};