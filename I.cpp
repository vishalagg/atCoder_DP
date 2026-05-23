#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<double> p(n);
	for (int i=0; i<n; i++) {
	    cin >> p[i];
	}
	
	
// 	dp[i][j]=prob of getting exactly j heads after tossing first i coins;
//  dp[i][j]=p[i]*dp[i-1][j-1] + (1-p[i])*dp[i-1][j];

//  dp[i] = prob of getting exactly i heads
    vector<double> dp(n + 1, 0);
    dp[0] = 1;

    for (int i=0; i<n; i++) {
        for (int j=n; j>=0; j--) {
            double heads_prob = (j - 1 >= 0) ? p[i] * dp[j - 1]: 0.0;
            double tails_prob = (1.0 - p[i]) * dp[j];
            
            dp[j] = heads_prob + tails_prob;
        }
    }
    
    double total_prob = 0.0;
    for (int j = (n + 1) / 2; j <= n; j++) {
        total_prob += dp[j];
    }
    cout << fixed << setprecision(10) << total_prob << "\n";
}
