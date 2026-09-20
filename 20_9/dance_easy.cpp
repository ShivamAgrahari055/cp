// You are given two arrays of integers a1,a2,…,an
//  and b1,b2,…,bn
// . Before applying any operations, you can reorder the elements of each array as you wish. Then, in one operation, you will perform both of the following actions, if the arrays are not empty:

// Choose any element from array a
//  and remove it (all remaining elements are shifted to a new array a
// ),
// Choose any element from array b
//  and remove it (all remaining elements are shifted to a new array b
// ).
// Let k
//  be the final size of both arrays. You need to find the minimum number of operations required to satisfy ai<bi
//  for all 1≤i≤k
// .

// This problem was too easy, so the problem author decided to make it more challenging. You are also given a positive integer m
// . Now, you need to find the sum of answers to the problem for m
//  pairs of arrays (c[i],b)
// , where 1≤i≤m
// . Array c[i]
//  is obtained from a
//  as follows:

// c[i]1=i
// ,
// c[i]j=aj
// , for 2≤j≤n
// .


#include <bits/stdc++.h>

using namespace std;

// Returns true if, after removing `ops` elements from the end of both arrays
// and reordering optimally, we can make every pair satisfy a[i] < b[i].
bool check(int ops, vector<int> a, vector<int> b) {
	// Remove `ops` largest elements from `a` (a is sorted ascending later)
	// and `ops` smallest elements from `b` (b is sorted descending later).
	for (int i = 0; i < ops; i++) {
		a.pop_back();
		b.pop_back();
	}

	// After sorting `b` in descending order and popping from back (smallest),
	// reverse to get ascending order so we can pair smallest with smallest.
	reverse(b.begin(), b.end());

	// Check element-wise: pairing i-th smallest of `a` with i-th smallest of `b`.
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] >= b[i]) {
			return false;
		}
	}
	return true;
}

void solve() {
	int n, m;
	cin >> n >> m; // m = 1 in the easy version; a[0] must be 1.

	vector<int> a(n), b(n);
	a[0] = 1; // Because m = 1, the only possible a1 is 1.
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	// Sort `a` ascending and `b` descending to prepare for the feasibility check.
	sort(a.begin(), a.end());                 // O(nlogn)
	sort(b.begin(), b.end(), greater<>());   // O(nlogn)

	// Binary search the minimum number of operations to remove from both arrays.
	int low = 0, high = n;
	while (low < high) { // O(logn)
		int mid = (low + high) / 2;
		if (check(mid, a, b)) { // O(n) time, O(n) space due to copies
			high = mid;
		} else {
			low = mid + 1;
		}
	}

	cout << low << '\n';
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

/*
Time Complexity (TC): O(nlogn)
Space Complexity (SC): O(n)
*/
