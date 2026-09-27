
// Polycarp is designing a level for a game. The level consists of n
//  segments on the number line, where the i
// -th segment starts at the point with coordinate li
//  and ends at the point with coordinate ri
// .

// The player starts the level at the point with coordinate 0
// . In one move, they can move to any point that is within a distance of no more than k
// . After their i
// -th move, the player must land within the i
// -th segment, that is, at a coordinate x
//  such that li≤x≤ri
// . This means:

// After the first move, they must be inside the first segment (from l1
//  to r1
// );
// After the second move, they must be inside the second segment (from l2
//  to r2
// );
// ...
// After the n
// -th move, they must be inside the n
// -th segment (from ln
//  to rn
// ).
// The level is considered completed if the player reaches the n
// -th segment, following the rules described above. After some thought, Polycarp realized that it is impossible to complete the level with some values of k
// .

// Polycarp does not want the level to be too easy, so he asks you to determine the minimum integer k
//  with which it is possible to complete the level.

#include <bits/stdc++.h>

using namespace std;

int segmentStart[200000], segmentEnd[200000];

bool isReachableWithJump(int segmentCount, int maxJump)
{
	int currentMinPosition = 0;  // After i moves: minimal coordinate we can be at
	int currentMaxPosition = 0;  // After i moves: maximal coordinate we can be at

	for (int i = 0; i < segmentCount; i++)
	{
		// From any position in [currentMinPosition, currentMaxPosition],
		// we can move at most maxJump left/right
		currentMaxPosition += maxJump;
		currentMinPosition -= maxJump;

		// Intersect reachable range with the i-th segment [l_i, r_i]
		int reachableStart = max(currentMinPosition, segmentStart[i]);
		int reachableEnd = min(currentMaxPosition, segmentEnd[i]);

		// If intersection is empty, we cannot land in segment i
		if (reachableStart > reachableEnd)
		{
			return false;
		}

		// Narrow our reachable range to the intersection for the next step
		currentMinPosition = reachableStart;
		currentMaxPosition = reachableEnd;
	}

	// We successfully found a landing point for every segment
	return true;
}

void solveTestCase()
{
	int segmentCount;
	cin >> segmentCount;

	for (int i = 0; i < segmentCount; i++)
	{
		cin >> segmentStart[i] >> segmentEnd[i];  // Segments must be visited in given order
	}

	int low = 0, high = 1e9;  // Binary search on the minimal feasible jump length k

	while (low < high)
	{
		int mid = (low + high) / 2;  // Candidate k
		if (isReachableWithJump(segmentCount, mid))
		{
			// k = mid works; try to find smaller
			high = mid;
		}
		else
		{
			// k = mid doesn't work; need larger k
			low = mid + 1;
		}
	}

	cout << low << '\n';  // Minimal k making the path possible
}

int main()
{
	int testCases;
	cin >> testCases;

	for (int testCase = 0; testCase < testCases; testCase++)
	{
		solveTestCase();
	}
}
