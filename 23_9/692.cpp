
// For priority_queue, the comparator makes the element considered lowest priority appear at the top.

// If frequencies differ, a.second < b.second makes the higher frequency appear first.

// If frequencies are equal, a.first > b.first makes the lexicographically smaller word appear first.
class Compare {
public:
    bool operator()(pair<string, int> a, pair<string, int> b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;

        for (auto &x : words) {
            m[x]++;
        }

        priority_queue<pair<string, int>,
                       vector<pair<string, int>>,
                       Compare> pq;

        for (auto &[word, freq] : m) {
            pq.push({word, freq});
        }

        vector<string> ans;

        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};