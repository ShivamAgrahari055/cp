// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0.

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.rbegin(), stones.rend());

        while (stones.size() > 1) {
            int st = 0;
            int end = 1;

            if (stones[st] == stones[end]) {
                stones.erase(stones.begin() + st);
                stones.erase(stones.begin() + st);
            }
            else {
                int temp = stones[st];

                stones.erase(stones.begin() + st);

                stones[0] = temp - stones[0];
            }

            sort(stones.rbegin(), stones.rend());
        }

        if (stones.empty()) return 0;

        return stones[0];
    }
};
#here important thing is how erase works ..erase operates immediately and item at index 1 immediately becomes index 0 ;

#method 2
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (auto x : stones) {
            pq.push(x);
        }

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            if (a != b) {
                pq.push(a - b);
            }
        }

        if (pq.empty()) return 0;

        return pq.top();
    }
};