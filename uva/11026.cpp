/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

namespace SOLVE {	
	void main() {
		while (1) {
			ll a, b;
			cin >> a >> b;
			if (a == 0 && b == 0) return;

			VLL A(a);
			REP(i,0,a) cin >> A[i];

			VVLL dp(a+1, VLL(a+1)); 
			// dp[i][k] gives sum of first i elements, grouped by k
			// dp[i][j] = A[i] * dp[i-1][j-1] + dp[i-1][j]

			// base case: 0 elements is 1
			REP(i,0,a+1) dp[i][0] = 1;


			REP(i,1,a+1) { // for the first a elements
				REP(j,1,i+1) { // choosing up to i groups
					dp[i][j] = A[i-1] * dp[i-1][j-1] + dp[i-1][j];
					dp[i][j] %= b;
				}
			}

			ll ans = 0;
			REP(i,0,a+1) {
				ans = max(ans, dp[a][i] % b);
			}
			cout << ans << endl;

		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
