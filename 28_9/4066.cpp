
// You are given a 1-indexed integer array nums.

// You can choose two distinct values x and y and perform the following operation at most once:

// Replace every occurrence of x in nums with y.
// Return the maximum possible number of pairs of adjacent elements that are equal after performing the operation.
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        
        map<pair<int,int>,int> mp ;
        int base = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) base++;
            else{

                int x = min(nums[i],nums[i+1]) ;
                int y = max(nums[i],nums[i+1]) ;

                mp[{x,y}]++;
            }

        }

        int mx = 0;
        for(auto &x:mp){
            mx = max(mx,x.second) ;
        }
        return base + mx ;
    }
};