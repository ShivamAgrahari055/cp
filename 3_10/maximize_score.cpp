
// You are given an array a
//  of length 2n
// . Each integer from 1
//  to n
//  occurs exactly twice in a
// .

// Initially, your score is 0
// .

// You can repeatedly perform the following operation while a
//  is non-empty:

// Choose an integer x
//  that is present in a
// .
// Let l
//  and r
//  be the indices of the leftmost and rightmost occurrences of x
//  in the current array, respectively. If x
//  occurs only once, then l=r
// .
// Add (r−l+1)2
//  to your score.
// Delete the elements al,al+1,…,ar
//  from a
// . The remaining elements are concatenated without changing their order and re-indexed starting from 1
// .
// Find the maximum possible score after making the array empty.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solveMemo(
    int i,
    int len,
    const vector<int>& a,
    const vector<int>& first_pos,
    const vector<int>& last_pos,
    vector<long long>& memo
) {
    // Base case
    if (i > len)
        return 0;

    // Already calculated
    if (memo[i] != -1)
        return memo[i];

    // Choice 1: delete only a[i]
    long long choice1 =
        1 + solveMemo(i + 1, len, a, first_pos, last_pos, memo);

    // Choice 2: delete the complete range
    long long choice2 = 0;

    // Only consider range when i is the first occurrence
    if (first_pos[a[i]] == i) {

        int r = last_pos[a[i]];

        long long range_len = r - i + 1;

        choice2 =
            range_len * range_len +
            solveMemo(r + 1, len, a, first_pos, last_pos, memo);
    }

    return memo[i] = max(choice1, choice2);
}

void solve() {

    int n;
    cin >> n;

    int len = 2 * n;

    vector<int> a(len + 1);

    vector<int> first_pos(n + 1, 0);
    vector<int> last_pos(n + 1, 0);

    // Read array and store first/last positions
    for (int i = 1; i <= len; i++) {

        cin >> a[i];

        if (first_pos[a[i]] == 0) {
            first_pos[a[i]] = i;
        }
        else {
            last_pos[a[i]] = i;
        }
    }

    // -1 means "not calculated yet"
    vector<long long> memo(len + 2, -1);

    cout << solveMemo(
        1,
        len,
        a,
        first_pos,
        last_pos,
        memo
    ) << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}