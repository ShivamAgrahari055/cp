// 2231. Largest Number After Digit Swaps by Parity
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

// Return the largest possible value of num after any number of swaps.

 

class Solution {
public:
    int largestInteger(int num) {

        priority_queue<int> peven;
        priority_queue<int> podd;

        string s = to_string(num);

        for (auto &x : s) {
            int digit = x - '0';

            if (digit % 2 == 0)
                peven.push(digit);
            else
                podd.push(digit);
        }

        for (int i = 0; i < s.length(); i++) {

            int digit = s[i] - '0';

            if (digit % 2 == 0) {
                int temp = peven.top();
                peven.pop();

                s[i] = temp + '0';
            }
            else {
                int temp = podd.top();
                podd.pop();

                s[i] = temp + '0';
            }
        }

        return stoi(s);
    }
};
// +0 TO CONVERT CHAR TO NUM OR -0 TO CONVERT NUM TO CHAR