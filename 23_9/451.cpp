

class Compare {
public:
    bool operator()(pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;

        map<char, int> m;

        for (auto &x : s) {
            m[x]++;
        }

        for (auto &[u, v] : m) {
            pq.push({u, v});
        }

        string ans = "";

        while (!pq.empty()) {
            char ch = pq.top().first;
            int freq = pq.top().second;
            pq.pop();

            while (freq--) {
                ans += ch;
            }
        }

        return ans;
    }
};

//bucket sort