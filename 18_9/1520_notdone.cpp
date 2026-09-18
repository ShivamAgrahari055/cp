// 1520. Maximum Number of Non-Overlapping Substrings
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

// The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
// A substring that contains a certain character c must also contain all occurrences of c.
// Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

// Notice that you can return the substrings in any order.
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int,int>> intervals;

        for (int i = 0; i < n; i++) {
            if (i != first[s[i] - 'a'])
                continue;

            int start = i;
            int end = last[s[i] - 'a'];
            bool valid = true;

            for (int j = start; j <= end; j++) {
                int c = s[j] - 'a';

                if (first[c] < start) {
                    valid = false;
                    break;
                }

                end = max(end, last[c]);
            }

            if (valid)
                intervals.push_back({start, end});
        }

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prev = -1;

        for (auto [l, r] : intervals) {
            if (l > prev) {
                ans.push_back(s.substr(l, r - l + 1));
                prev = r;
            }
        }

        return ans;
    }
};