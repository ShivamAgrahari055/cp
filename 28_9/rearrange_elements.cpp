

// You are given an integer array nums.

// You start with an empty array ans. Repeat the following operation until nums is empty:

// Identify all distinct values currently present in nums.
// Remove one occurrence of every distinct value currently in nums, and append those values to ans in ascending order.
// Return the array ans


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> ans ;
        
        map<int, int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        while (true) {
            bool done=false;
            for (auto &p : vec) {
                if (p.second>0) {
                    ans.push_back(p.first);
                    p.second--;
                    done=true;
                }
            }
            if (!done) break;
        }
        return ans ;
            
    }
};