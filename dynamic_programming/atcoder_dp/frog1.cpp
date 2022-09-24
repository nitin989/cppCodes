#include <bits/stdc++.h>
using namespace std;

int n;
int height[100010];
int dp[100010];

int rec(int level)
{

	// base case 
	if(level < 0)
		return 1e9;

	if(level == 0)
		return 0;

	// caching 
	if(dp[level] != -1)
		return dp[level];

	// computation 

	int ans = 0;
	ans = 	min(rec(level - 1) + abs(height[level] - height[level -1])  , 
		rec(level - 2) + abs(height[level] - height[level -2]));

	return dp[level] = ans;

}

void solve()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> height[i];

	memset(dp , -1 , sizeof(dp));
	cout << rec(n-1) << "\n";
}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}