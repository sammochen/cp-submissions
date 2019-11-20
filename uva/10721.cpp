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
typedef vector<VVLL> VVVLL;

namespace SOLVE {	
	VVVLL dp(51, VVLL(51, VLL(51,-1)));

	// n is total, k is how many bars, m is maximum size of bar
	ll get(ll n, ll k, ll m) {
		if (n == 0 && k == 0) return 1;
		if (n <= 0) return 0;
		if (k <= 0) return 0;
		if (m <= 0) return 0;

		if (dp[n][k][m] != -1) return dp[n][k][m];

		ll ans = 0;
		REP(i,1,m+1) {
			ans += get(n-i, k-1, m);
		}
		dp[n][k][m] = ans;
		return ans;
	}
	void main() {
		ll a, b, c;
		while (cin >> a >> b >> c) {
			ll ans = get(a,b,c);
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
