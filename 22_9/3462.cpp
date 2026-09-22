
// You are given a 2D integer matrix grid of size n x m, an integer array limits of length n, and an integer k. The task is to find the maximum sum of at most k elements from the matrix grid such that:

// The number of elements taken from the ith row of grid does not exceed limits[i].

// Return the maximum sum.
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = grid.size();

        for (int i = 0; i < n; i++) {
            vector<int> row = grid[i];

            sort(row.rbegin(), row.rend());

            int cnt = min((int)row.size(), limits[i]);

            for (int j = 0; j < cnt; j++) {
                if (row[j] <= 0) continue;

                pq.push(row[j]);

                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        long long ans = 0;

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};