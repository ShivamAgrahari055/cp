
// Egor has a table of size n×m
// , with lines numbered from 1
//  to n
//  and columns numbered from 1
//  to m
// . Each cell has a color that can be presented as an integer from 1
//  to 105
// .

// Let us denote the cell that lies in the intersection of the r
// -th row and the c
// -th column as (r,c)
// . We define the manhattan distance between two cells (r1,c1)
//  and (r2,c2)
//  as the length of a shortest path between them where each consecutive cells in the 
//  path must have a common side. The path can go through cells of any color. 
//  For example, in the table 3×4
//  the manhattan distance between (1,2)
//  and (3,3) is 3.
// , one of the shortest paths is the following: (1,2)→(2,2)→(2,3)→(3,3)
// .

// Egor decided to calculate the sum of manhattan distances between 
// each pair of cells of the same color. Help him to calculate this sum.
##################################################################################################################


// 2. Why you need the sum of earlier coordinates

// Say we're at a new cell with row i, and the color has appeared k times
// before at rows r₁, r₂, ..., r_k. The distances to those earlier cells (row part only) are:

// (i - r₁) + (i - r₂) + ... + (i - r_k)
// Group the terms: = k·i - (r₁ + r₂ + ... + r_k)

###################################################################################################################
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
  int n,m ; cin >>n>>m ;
  vector<vector<int>> v(n, vector<int>(m));
  int ans = 0;

  // pass 1: row-major -> rows are non-decreasing, so no abs needed
  map<int,vector<int>> mp ;              // color -> {count, sumOfRows}
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> v[i][j];
      int c = v[i][j];
      if(!mp.count(c)) mp[c] = {0, 0};
      ans += i * mp[c][0] - mp[c][1];
      mp[c][0]++;
      mp[c][1] += i;
    }
  }

  // pass 2: column-major -> columns are non-decreasing
  mp.clear();                            // color -> {count, sumOfCols}
  for(int j=0;j<m;j++){
    for(int i=0;i<n;i++){
      int c = v[i][j];
      if(!mp.count(c)) mp[c] = {0, 0};
      ans += j * mp[c][0] - mp[c][1];
      mp[c][0]++;
      mp[c][1] += j;
    }
  }

  cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}