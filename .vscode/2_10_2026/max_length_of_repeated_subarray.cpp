
//Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

// class Solution {
// public:
//     vector<int> nums1, nums2;
//     vector<vector<int>> dp;
//     int ans = 0;

//     int help(int i, int j) {

//         if(i < 0 || j < 0)
//             return 0;

//         if(dp[i][j] != -1)
//             return dp[i][j];

//         if(nums1[i] == nums2[j]) {
//             dp[i][j] = 1 + help(i - 1, j - 1);
//             ans = max(ans, dp[i][j]);
//         }
//         else {
//             dp[i][j] = 0;
//         }

//         // Explore other positions
//         help(i - 1, j);
//         help(i, j - 1);

//         return dp[i][j];
//     }

//     int findLength(vector<int>& nums1, vector<int>& nums2) {

//         this->nums1 = nums1;
//         this->nums2 = nums2;

//         int n = nums1.size();
//         int m = nums2.size();

//         dp.assign(n, vector<int>(m, -1));

//         help(n - 1, m - 1);

//         return ans;
//     }
// };
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int ans = 0;

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                if(nums1[i-1] == nums2[j-1]) {

                    dp[i][j] = 1 + dp[i-1][j-1];

                    ans = max(ans, dp[i][j]);
                }
                else {

                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};