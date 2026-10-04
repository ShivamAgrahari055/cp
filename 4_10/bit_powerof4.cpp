

class Solution {
public:
    bool isPowerOfFour(int num) {

        if (num <= 0)
            return false;

        int cnt = 0;

        for (int i = 0; i < 31; i++) {

            if (num & (1 << i)) {

                cnt++;

                // More than one 1
                if (cnt > 1)
                    return false;

                // 1 is at odd position
                if (i % 2 != 0)
                    return false;
            }
        }

        return cnt == 1;
    }
};