#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int arr[n][3];
	for (int i=0; i<n; i++) {
	    cin >> arr[i][0];
	    cin >> arr[i][1];
	    cin >> arr[i][2];
	}
	
	// dp[i][j] = max happiness if do jth activity on ith day.
	// dp[i][j] = max(arr[i][j] + dp[i-1][k]) where k = other 2 activities than j
	vector<vector<int>> dp(n + 1, vector<int>(3, 0));
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	
	for (int i=1; i<n; i++) {
	    dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);
	    dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);
	    dp[i][2] = arr[i][2] + max(dp[i-1][0], dp[i-1][1]);
	}
	
	cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}
