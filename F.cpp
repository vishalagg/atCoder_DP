#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	
	//dp[i][j] = max matching subsequence from s[i...n] and t[j...m]
	//dp[i][j] = if s[i]=s[j] then 1 + (dp[i+1][j+1]) else
	//           max(dp[i][j+1], d[i+1][j])
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = n-1; i>=0; i--) {
	    for (int j = m-1; j>=0; j--) {
	        if (s[i] == t[j]) {
	            dp[i][j] = 1 + dp[i+1][j+1];
	        } else {
	            dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
	        }
	    }
	}
	
	string ans = "";
	int i = 0, j = 0;
	while (i < n && j < m) {
	    if (s[i] == t[j]) {
	        ans += s[i];
	        i++; j++;
	    } else if (dp[i+1][j] < dp[i][j+1]) {
	        j++;
	    } else {
	        i++;
	    }
	}
	cout << ans;
}
