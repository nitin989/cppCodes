#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<int, int>;
const int mod = 1e9 + 7;

vector<string> g(1010);
int h, w;
int dp[1010][1010];

int rec(int x , int y)
{
	if(x >= h || y >= w || g[x][y] == '#')
		return 0;

	if(x == h-1 && y == w-1)
		return 1;

	if(dp[x][y] != -1)
		return dp[x][y];

	int ans = 0;
	if(g[x+1][y] != '#')
		ans = (ans +rec(x+1,y)) % mod;
	if(g[x][y +1] != '#')
		ans = (ans + rec(x,y+1)) % mod;

	return dp[x][y] = ans%mod;

}

void solve()
{
	cin >> h >> w;
	for(int i = 0; i < h ; i++)
		cin >> g[i];
	memset(dp , -1 , sizeof(dp));

	cout << rec(0,0) << "\n";
	
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