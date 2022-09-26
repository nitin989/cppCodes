#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<int, int>;

int n;
double prob[3010];
double dp[3010][3010];
bool done[3010][3010];

double rec(int level, int headCount)
{

	if(level > n)
		return 0.0;

	if(level == n)
	{
		if(headCount > n - headCount)
			return 1.0;
		
		return 0.0; 
	}


	if(done[level][headCount])
		return dp[level][headCount];

	done[level][headCount] = true;

	double ans = prob[level]*rec(level + 1 , headCount + 1) + 
	(1.0-prob[level])*rec(level+1 , headCount);

	return dp[level][headCount] = ans;

}

void solve()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> prob[i];

	//memset(dp , 1.0 , sizeof(dp));
	memset(done,false,sizeof(done));

	cout << setprecision(9) << rec(0,0) << "\n";

	
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