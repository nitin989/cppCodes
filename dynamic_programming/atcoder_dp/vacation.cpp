#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<int, int>;


int n;
lli  actvts[100100][3];
lli dp[100100][3];

// Form 1 problem 

lli rec(int level , int last)
{
	// pruning 

	// base case 
	if(level == n)
		return 0;

	// caching 

	if(last != -1 && dp[level][last] != -1)
		return dp[level][last];

	// computation
	lli ans = 0; 
	for(int i = 0 ; i < 3 ; i++)
	{
		if(i != last)
		{
			ans = max(ans , rec(level + 1 , i) + actvts[level][i] );
		}
	}

	// return and save

	if(last == -1)
		return ans;
	return dp[level][last] = ans;

}


void solve()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			cin >> actvts[i][j];	
		}
	}

	memset(dp , -1 , sizeof(dp));

	//cout << max(rec(1 , 0 ) + actvts[0][0] , max( rec(1,1) + actvts[0][1] , rec(1,2) + actvts[0][2]  )) << "\n";

	cout << rec(0,-1) << "\n";
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