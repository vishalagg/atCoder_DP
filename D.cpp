#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, w;
	cin >> n >> w;
	
	int wt[n];
	int val[n];
	
	for (int i=0; i<n; i++) {
	    cin >> wt[i];
	    cin >> val[i];
	}
	
	//  dp[x] = maximum value achievable with capacity x after processing first i items
	vector<long long> dp(w + 1, 0);
	
	for (int i=0; i<n; i++) {
	    for (int x=w; x>=wt[i]; x--) {
	        dp[x] = max(dp[x], val[i] + dp[x - wt[i]]);
	    }
	}
	
	cout << dp[w];
	
	
	
	// dp[i][x] = max val with x wt allowed from i...n;
	// dp[i][x] = max(dp[i+1][x], val[i] + dp[i+1][x-wt[i]])
	
// 	vector<vector<long long>> dp(2, vector<long long>(w+1, 0)); // since only i and i+1 rows are required.
	
// 	for (int i=0; i<=w; i++) {
// 	    dp[(n - 1) % 2][i] = (i >= wt[n-1]) ? val[n-1] : 0;
// 	}
	
// 	for (int i=n-2; i>=0; i--) {
// 	    for (int x = 0; x <= w; x++) {
// 	        long long skip = dp[(i + 1) % 2][x];
            
//             long long take = 0;
//             if (x >= wt[i]) { 
//                 take = val[i] + dp[(i + 1) % 2][x - wt[i]];
//             }
            
//             dp[i % 2][x] = max(skip, take);
// 	    }
// 	}
	
// 	cout << dp[0][w];
}
