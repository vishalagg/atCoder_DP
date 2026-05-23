#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<string> grid(n);
	for (int i=0; i<n; i++) {
	    cin >> grid[i];
	}
	
	int MOD = 1e9 + 7;
	
// 	dp[i][j] = #path from 0,0 till i,j
//  dp[i][j] = if grid[i][j] = # then 0
//          else dp[i-1][j] + dp[i][j-1]

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    dp[0][0] = 1;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == '.') {
                if (i - 1 >= 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
            
            if (j - 1 >= 0) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
            }
        }
    }
    
    cout << dp[n-1][m-1];
}
