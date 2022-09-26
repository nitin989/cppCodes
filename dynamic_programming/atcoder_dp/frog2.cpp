#include <bits/stdc++.h>
using namespace std;

int n , k ;
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

	int ans = rec(level - 1) + abs(height[level] - height[level -1]);
	for(int i = 2 ; i <= k ; i++)
	{
		ans = 	min(ans  , rec(level -  i) + abs(height[level] - height[level -i]));

	}
	

	return dp[level] = ans;

}

void solve()
{
	cin >> n >> k;
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