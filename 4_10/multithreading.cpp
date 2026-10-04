


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mn =a[n-1];
    int ans = 1;

    for(int i = n - 2; i >= 0; i--) {

        if(a[i] < mn) {
            mn = a[i];
            ans++;
        }
        else break ;
       
    }

    cout <<n- ans << endl;

    return 0;
}