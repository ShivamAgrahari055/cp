A sequence of n
 non-negative integers (n≥2
) a1,a2,…,an
 is called good if for all i
 from 1
 to n−1
 the following condition holds true:
a1&a2&…&ai=ai+1&ai+2&…&an,
where &
 denotes the bitwise AND operation.

You are given an array a
 of size n
 (n≥2
). Find the number of permutations p
 of numbers ranging from 1
 to n
, for which the sequence ap1
, ap2
, ... ,apn
 is good. Since this number can be large, output it modulo 109+7
.

#include <bits/stdc++.h>
using namespace std;

const int N = 200000;           
const int MOD = 1000000007;     
int fact[N + 1];                 

void solve() {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
				cin >> a[i];
		}

		int totalAnd = a[0];
		for (int i = 1; i < n; i++) { 
				totalAnd &= a[i];
		}

		int countAnd = count(a, a + n, totalAnd); 
		if (countAnd <= 1) {
				cout << 0 << "\n";
				return;
		}
		cout << 1LL * countAnd * (countAnd - 1) % MOD * fact[n - 2] % MOD << '\n';
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		fact[0] = 1;
		for (int i = 1; i <= N; i++) {
				fact[i] = (1LL * fact[i - 1] * i) % MOD;
		}

		int t;
		cin >> t;
		while (t--) {
				solve();
		}

		/*
		Time Complexity (TC): O(n)
		Space Complexity (SC): O(n)
		*/
}
