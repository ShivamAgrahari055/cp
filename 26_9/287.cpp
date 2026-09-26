#find duplicate number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Answer is between 1 and n
        int low = 1;
        int high = nums.size() - 1;

        while(low < high) {

            // Binary search on ANSWER

            int cnt = 0;

            // Count numbers <= mid
            for(auto &x : nums) {
                if(x <= mid)
                    cnt++;
            }

            // Too many numbers in [1...mid]
            // Therefore duplicate is in left half
            if(cnt > mid)
                high = mid;

            // Otherwise duplicate is in right half
            else
                low = mid + 1;
        }

        return low;
    }
};

#taking xor from 1 to n and again xor with numbers in array works when the duplicate appears only once .and that too all numbers from 1 to n