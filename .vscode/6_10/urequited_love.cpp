
// K1o0n reached the stage where, for complete happiness, he only lacked a musical instrument, and bought a synthesizer second-hand. The instrument has n
//  keys, giving a1,a2,…,an
//  units of audience love.

// Playing one note at a time is boring, so K1o0n learned a single technique — a triad: three keys with one key between each pair, pressed simultaneously. A triad starting at x
//  (1≤x≤n−4
// ) is the keys x
// , x+2
// , and x+4
// , which brings ax+ax+2−ax+4
//  units of audience love.

// The keys are old, and each can withstand exactly one press. Therefore, K1o0n wants to choose exactly two different triads that do not share any keys. In addition, he wants both triads to bring the same amount of audience love.

// Count the number of ways to choose two such triads.





#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        int m = n - 4;
        vector<int> val(m);

        for (int i = 0; i < m; i++) {
            val[i] = a[i] + a[i + 2] - a[i + 4];
        }

        unordered_map<int, long long> freq;
        long long ans = 0;

        for (int j = 0; j < m; j++) {
            // Count all earlier triads with the same value.
            ans += freq[val[j]];

            // Remove pairs whose triads overlap.
            if (j >= 2 && val[j] == val[j - 2])
                ans--;

            if (j >= 4 && val[j] == val[j - 4])
                ans--;

            // Add current triad for future pairs.
            freq[val[j]]++;
        }

        cout << ans << '\n';
    }

    return 0;
}
