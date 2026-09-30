

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.
class Solution {
public:
    int numberOfSubstrings(string s) {

        int last[3] = {-1, -1, -1};
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {

            last[s[i] - 'a'] = i;

            int mn = min({last[0], last[1], last[2]});
            if(mn != -1)
                ans += mn + 1;
        }

        return ans;
    }
};