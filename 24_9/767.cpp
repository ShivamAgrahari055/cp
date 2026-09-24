Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.
class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> m;

        for (auto &x : s) {
            m[x]++;
        }

        int n = s.size();

        // Check whether reorganization is possible
        for (auto &c : m) {
            int temp = c.second;

            if (n - temp < temp - 1) return "";
        }

        // Store characters in decreasing order of frequency
        vector<pair<int, char>> v;

        for (auto &c : m) {
            v.push_back({c.second, c.first});
        }

        sort(v.rbegin(), v.rend());

        string ans(n, ' ');
        int idx = 0;

        // Place the most frequent characters at even indices,
        // then continue at odd indices
        for (auto &c : v) {
            int freq = c.first;
            char ch = c.second;

            while (freq--) {
                if (idx >= n) idx = 1;

                ans[idx] = ch;
                idx += 2;
            }
        }

        return ans;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> m;

        for (auto &x : s) {
            m[x]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &c : m) {
            if (c.second > (s.size() + 1) / 2) {
                return "";
            }

            pq.push({c.second, c.first});
        }

        string ans = "";

        while (pq.size() >= 2) {
            auto a = pq.top();
            pq.pop();

            auto b = pq.top();
            pq.pop();

            ans += a.second;
            ans += b.second;

            a.first--;
            b.first--;

            if (a.first > 0) pq.push(a);
            if (b.first > 0) pq.push(b);
        }

        if (!pq.empty()) {
            auto a = pq.top();

            if (a.first > 1) return "";

            ans += a.second;
        }

        return ans;
    }
};