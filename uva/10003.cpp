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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll solve(ll start, ll end, VLL & A, ll & x, VVLL & dp) {
		if (start > end) return 0;
		if (dp[start][end] != -1) return dp[start][end];

		ll top = end == A.size() - 1 ? x : A[end+1];
		ll bot = start == 0 ? 0 : A[start - 1];
		ll rem = top - bot;
		
		ll ans = inf;
		REP(i,start,end+1) {
			ans = min(ans, solve(start, i-1, A, x, dp) + solve(i+1, end, A, x, dp) + rem);
		}
		
		dp[start][end] = ans;
		return ans;
	}

	void main() {
		while (1) {
			ll x;
			cin >> x;
			if (x == 0) return;
			ll n;
			cin >> n;

			VVLL dp(n, VLL(n, -1));

			VLL A(n);
			REP(i,0,n) cin >> A[i];

			ll ans = solve(0, n-1, A, x, dp);
			cout << "The minimum cutting is " << ans << "." << endl;
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
