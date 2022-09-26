#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<int, int>;

int n , w;
int weight[100100];
int value[100100];

lli dp[110][100100];

lli rec(int level , int left)
{

	// base case 
	if(level == n)
		return 0;

	// caching 

	if(dp[level][left] != -1)
		return dp[level][left];

	// compute 

	lli ans = rec(level + 1 , left);
	if(left >= weight[level])
		ans = max(ans , rec(level + 1 , left - weight[level]) + value[level] );

	return dp[level][left] = ans;


}

void solve()
{

	cin >> n >> w;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> weight[i] >> value[i];
	}

	memset(dp , -1 , sizeof(dp));

	cout << rec(0 , w) << "\n";
	
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