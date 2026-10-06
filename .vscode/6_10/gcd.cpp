
// You are given two arrays a
//  and b
//  of length n
// .

// For each index i
//  (1≤i≤n
// ) of array a
// , you can perform the following operation at most once:

// choose an arbitrary integer m
//  (m≠ai
// ) such that 1≤m≤bi
// , and set ai:=m
// .
// Let the array after performing all the operations be a′
// . You can only perform operations in such a way that the following condition holds:

// for all 1≤l<r≤n
// , gcd(al,al+1,…,ar)=gcd(a′l,a′l+1,…,a′r).
// Here, gcd(x,y)
//  denotes the greatest common divisor (GCD) of integers x
//  and y
// .

// You have to determine the maximum number of operations that can be performed while ensuring that the condition remains satisfied.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);

        for (auto &x : a)
            cin >> x;

        // b[i] = a[i], so we don't actually need to read/store b
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
        }

        int ans = 0;

        // First element
        if (gcd(a[0], a[1]) < a[0])
            ans++;

        // Middle elements
        for (int i = 1; i < n - 1; i++) {
            ll left = gcd(a[i - 1], a[i]);
            ll right = gcd(a[i], a[i + 1]);

            ll need = lcm(left, right);

            if (need < a[i])
                ans++;
        }

        // Last element
        if (gcd(a[n - 2], a[n - 1]) < a[n - 1])
            ans++;

        cout << ans << '\n';
    }

    return 0;
}