#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> h(n, 0);
	
	for (int i=0; i<n; i++) {
	    cin >> h[i];
	}
	
	//dp[i] = min cost to reach i...n;
	//dp[i] = min(dp[i + 1] + abs(h[i+1] - h[i]), dp[i + 1] + abs(h[i+2] - h[i]))
	vector<int> dp(n + 1, 1e9);
	dp[n - 1] = 0;
	
	for (int i=n-2; i>=0; i--) {
	    
	    dp[i] = abs(h[i+1] - h[i]) + dp[i+1];
	    
	    if (i + 2 < n)
    	    dp[i] = min(dp[i], abs(h[i+2] - h[i]) + dp[i+2]);
	}
	
	cout << dp[0];
}
