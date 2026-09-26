// C. Schedule Management
// time limit per test2 seconds
// memory limit per test256 megabytes
// There are n
//  workers and m
//  tasks. The workers are numbered from 1
//  to n
// . Each task i
//  has a value ai
//  — the index of worker who is proficient in this task.

// Every task should have a worker assigned to it. If a worker is proficient in the task, they complete it in 1
//  hour. Otherwise, it takes them 2
//  hours.

// The workers work in parallel, independently of each other. Each worker can only work on one task at once.

// Assign the workers to all tasks in such a way that the tasks are completed as early as possible. The work starts at time 0
// . What's the minimum time all tasks can be completed by?

#include <bits/stdc++.h>
using namespace std;

vector<int> fr; // fr[i] = count of tasks where worker i is proficient

// Checks if all m tasks can be finished within time t
bool check(int n, int m, int t) {
		long long maxPossible = 0; // total tasks that can be completed by all workers in t hours

		for (int i = 0; i < n; i++) {
				if (t < fr[i]) {
						// Only enough time to do t proficient tasks (1 hour each)
						maxPossible += t;
				} else {
						// Do all proficient tasks, then use remaining time for non-proficient tasks (2 hours per task)
						maxPossible += fr[i] + (t - fr[i]) / 2;
				}
		}

		return maxPossible >= m; // sufficient if we can cover all tasks
}

void solve() {
		int n, m;
		cin >> n >> m;
		fr.assign(n, 0); // reset frequency vector for this test case

		for (int i = 0; i < m; i++) {
				int temp;
				cin >> temp;
				fr[temp - 1]++; // task i is best done by worker (temp - 1)
		}

		int low = 0, high = 2 * m; // worst case: all tasks take 2 hours

		// Binary search the minimal time when it's possible to finish all tasks
		while (low < high) {
				int mid = (low + high) / 2;
				if (check(n, m, mid)) {
						high = mid; // time is sufficient, try smaller
				} else {
						low = mid + 1; // time is insufficient, try larger
				}
		}

		cout << low << '\n'; // minimal feasible time
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> t;

		while (t--) {
				solve();
		}
}

/*
Time Complexity (TC): O(nlogm + m)
Space Complexity (SC): O(n)
*/
