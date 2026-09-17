//cf 2264
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    // Max heap containing the smallest (m-1) elements
    priority_queue<int> pq;

    int sum = 0;
    int ans = LLONG_MIN;

    for (int i = 0; i < n; i++) {

        // a[i] can be the LAST selected element
        if (pq.size() == m - 1) {
            ans = max(ans, m * a[i] - sum);
        }

        // Add a[i] to candidates for previous elements
        pq.push(a[i]);
        sum += a[i];

        // Keep only the smallest m-1 elements
        if (pq.size() > m - 1) {
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}