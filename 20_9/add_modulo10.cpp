// You are given an array of n
//  integers a1,a2,…,an

// You can apply the following operation an arbitrary number of times:

// select an index i
//  (1≤i≤n
// ) and replace the value of the element ai
//  with the value ai+(aimod10)
// , where aimod10
//  is the remainder of the integer dividing ai
//  by 10
// .
// For a single index (value i
// ), this operation can be applied multiple times. If the operation is applied repeatedly to the same index, then the current value of ai
//  is taken into account each time. For example, if ai=47
//  then after the first operation we get ai=47+7=54
// , and after the second operation we get ai=54+4=58
// .

// Check if it is possible to make all array elements equal by applying multiple (possibly zero) operations.

// For example, you have an array [6,11]
// .

// Let's apply this operation to the first element of the array. Let's replace a1=6
//  with a1+(a1mod10)=6+(6mod10)=6+6=12
// . We get the array [12,11]
// .
// Then apply this operation to the second element of the array. Let's replace a2=11
//  with a2+(a2mod10)=11+(11mod10)=11+1=12
// . We get the array [12,12]
.
// Thus, by applying 2
//  operations, you can make all elements of an array equal.
#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
				cin >> a[i];
		}

		// Make all odd numbers even in one operation: odd + (odd % 10) = even
		for (int i = 0; i < n; i++) {
				if (a[i] % 2 == 1) {
						a[i] += a[i] % 10; // after this, last digit is in {0,2,4,6,8}
				}
		}

		// If already all equal, we're done
		if (count(a, a + n, a[0]) == n) { // quick uniformity check
				cout << "YES\n";
				return;
		}

		// If any number ends with 0 now, it can no longer change (stuck state)
		// If not all equal yet and some end with 0, it's impossible
		for (int i = 0; i < n; i++) {
				if (a[i] % 10 == 0) { // stuck at this value forever
						cout << "NO\n";
						return;
				}
		}

		// Drive all numbers to have last digit 2; from there, each operation adds 2
		// Hence numbers become equivalent modulo 20
		for (int i = 0; i < n; i++) {
				while (a[i] % 10 != 2) { // repeatedly apply until unit digit becomes 2
						a[i] += a[i] % 10;
				}
				a[i] %= 20; // collapse to its residue class under +2 steps
		}

		// If all residue classes match, they can be made equal; otherwise not
		if (count(a, a + n, a[0]) == n) {
				cout << "YES\n";
				return;
		} else {
				cout << "NO\n";
		}
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> t;

		while (t--) { // process each test case
				solve();
		}
}

// Time Complexity (TC): O(n)
// Space Complexity (SC): O(1)
