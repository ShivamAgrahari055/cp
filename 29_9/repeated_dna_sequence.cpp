
// The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

// For example, "ACGAATTCCG" is a DNA sequence.
// When studying DNA, it is useful to identify repeated sequences within the DNA.

// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

class Solution {
public:

    unordered_map<string, int> mp;
    vector<string> ans;

    void help(string &s) {

        if(s.length() < 10)
            return;

        string temp = "";

        for(int i = 0; i < 10; i++) {
            temp += s[i];
        }

        mp[temp]++;

        for(int i = 10; i < s.length(); i++) {

            temp.erase(0, 1);
            temp += s[i];

            mp[temp]++;
        }

        // find repeated sequences
        for(auto &x : mp) {
            if(x.second > 1) {
                ans.push_back(x.first);
            }
        }
    }

    vector<string> findRepeatedDnaSequences(string s) {

        help(s);

        return ans;
    }
};
or
class Solution {
public:

    int get(char c) {

        if(c == 'A') return 0;
        if(c == 'C') return 1;
        if(c == 'G') return 2;
        return 3;
    }

    vector<string> findRepeatedDnaSequences(string s) {

        unordered_map<int, int> mp;
        vector<string> ans;

        if(s.size() < 10)
            return ans;

        int x = 0;

        // First 10 characters
        for(int i = 0; i < 10; i++) {
            x = (x << 2) | get(s[i]);
        }

        mp[x]++;

        // Sliding window
        for(int i = 10; i < s.size(); i++) {

            // Remove first 2 bits
            x &= (1 << 18) - 1;

            // Add new character
            x = (x << 2) | get(s[i]);

            mp[x]++;

            if(mp[x] == 2) {
                ans.push_back(s.substr(i - 9, 10));
            }
        }

        return ans;
    }
};

// x &= (1 << 18) - 1;        // remove first character
// x = (x << 2) | get(s[i]);  // add new character