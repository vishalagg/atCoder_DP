#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> h(n, 0);
	
	for (int i=0; i<n; i++) {
	    cin >> h[i];
	}
	
	//dp[i] = min cost to reach i...n;
	//dp[i] = min (dp[i], dp[i + j] + abs(h[i + j] - h[i])) for all 0 < j <= k
	vector<int> dp(n + 1, 1e9);
	dp[n - 1] = 0;
	
	for (int i=n-2; i>=0; i--) {
	    for (int j=1; j<=k; j++) {
	        
	        if (i + j >= n) break;
	        dp[i] = min(dp[i], dp[i + j] + abs(h[i + j] - h[i]));
	    }
	}
	
	cout << dp[0];
}
