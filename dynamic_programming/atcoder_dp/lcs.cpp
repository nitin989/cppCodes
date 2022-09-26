#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<int, int>;

string s ,t ;
int n , m;

int dp[3010][3010];
string sol;

// Form 3 
int rec(int i , int j)
{
	// base case 
	if(i == n || j == m)
		return 0;

	// caching 
	if(dp[i][j] != -1)
		return dp[i][j];

	// computation 
	int ans = 0;
	if(s[i] == t[j])
		ans = 1 + rec(i+1 , j+1);
	else
		ans = max(rec(i+1, j) , rec(i, j+1));

	// save and return 

	return dp[i][j] = ans;

}

void printSol(int i , int j)
{
	if(i ==n || j == m)
		return;

	if(rec(i , j) == rec(i+1,j))
		printSol(i+1,j);
	else if (rec(i , j) == rec(i,j+1))
		printSol(i , j+1);
	else
	{
		sol += s[i];
		printSol(i+1,j+1);
	}
}


void solve()
{
	cin >> s >> t;
	n  = s.length();
	m  = t.length();
	memset(dp , -1 , sizeof(dp));
	int lcs = rec(0 , 0);
	//cout << lcs << "\n";
	printSol(0,0);
	cout << sol << "\n";
	sol = "";

	
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