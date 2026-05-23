#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> list(n + 1);
	vector<int> indegree(n + 1, 0);
	for (int i=1; i<=m; i++) {
	    int x, y;
	    cin >> x >> y;
	    list[x].push_back(y);
	    indegree[y]++;
	}
	
	queue<int> q;
	for (int i=1; i<=n; i++) {
	    if (indegree[i] == 0)   q.push(i);
	}
	
	vector<int> topo;
	while (!q.empty()) {
	    int u = q.front();
	    q.pop();
	    topo.push_back(u);
	    
	    for (int v: list[u]) {
	        indegree[v]--;
	        if (indegree[v] == 0) {
	            q.push(v);
	        }
	    }
	}
	
// 	dp[i] = max length path from ith node;
//  dp[i] = 1 + max(dp[j]); where j belongs to list[i] following topo.
    int ans = 0;
    
    vector<int> dp(n + 1, 0);
    for (int i=n-1; i>=0; i--) {
        int u = topo[i];
        for (int v: list[u]) {
            dp[u] = max(dp[u], 1 + dp[v]);
        }
        ans = max(ans, dp[u]);
    }
    
    cout << ans << "\n";

}
