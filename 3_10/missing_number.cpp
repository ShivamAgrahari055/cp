
//array given find missing number in that array has element [0,n]
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
    }
};