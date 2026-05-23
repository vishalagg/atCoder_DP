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
	int total_val = 0;
	
	for (int i=0; i<n; i++) {
	    cin >> wt[i];
	    cin >> val[i];
	    total_val += val[i];
	}
	
	// dp[i] = min wt required to generate value i.
	// dp[i] = min(dp[i], w[i] + dp[i - v[i]]);
	vector<long long> dp(total_val + 1, 1e18);
	dp[0] = 0;
	
	for (int i=0; i<n; i++) {
	    for (int j=total_val; j>=val[i]; j--) {
	        dp[j] = min (dp[j], wt[i] + dp[j - val[i]]);
	    }
	}
	
	int ans = 0;
	for (int v = 0; v <= total_val; v++) {
        if (dp[v] <= w)
            ans = v;
    }

    cout << ans;
}
