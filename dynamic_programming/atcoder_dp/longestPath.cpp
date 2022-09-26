#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<int, int>;

int n , m;
vector<int> g[10010];
int dp[10010];

int rec(int x)
{
	if(dp[x] != -1)
		return dp[x];

	int ans = 0 ;
	for(auto v:g[x])
		ans = max(ans , 1 + rec(v));

	return dp[x] = ans;

}

void solve()
{
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++)
	{
		int x , y;
		cin >> x >> y;
		g[x].push_back(y);
	}

	memset(dp , -1 , sizeof(dp));

	int final_ans = 0;
	for(int i = 1 ; i<= n ; i++)
		final_ans = max(final_ans , rec(i));

	cout << final_ans << "\n";
	
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