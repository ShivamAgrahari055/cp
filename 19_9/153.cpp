//sorted array me ek part uthakar phle rkh diya gya h an=b min nikalo
//nums = [3,4,5,1,2]


class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return nums[l];
    }
};