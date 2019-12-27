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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll n;
	ll A[80][80];
	ll dp[80][80][6][2];

	ll get(ll i, ll j, ll k, ll left) {
		if (k < 0) return -inf;
		if (i < 0) return -inf;
		if (j < 0 || j >= n) return -inf;

		if (dp[i][j][k][left] != -1) return dp[i][j][k][left];
		

		// base case
		if (i == 0 && j == 0) {
			if (A[i][j] < 0 && k <= 0) return -inf;
			return A[i][j];
		}

		// else, return the best of going on with your direction, or going up
		// if going up, you can max of left or right
		ll ans = -inf;
		ll kk = (A[i][j] < 0) ? k - 1 : k;

		// continue
		ll cont = get(i, j + (left ? -1 : 1), kk, left);
		if (cont != -inf) ans = max(ans, A[i][j] + cont);
		
		ll upright = get(i-1, j, kk, 0);
		if (upright != -inf) ans = max(ans, A[i][j] + upright);

		ll upleft = get(i-1, j, kk, 1);
		if (upleft != -inf) ans = max(ans, A[i][j] + upleft);

		dp[i][j][k][left] = ans;
		return ans;

	}

	ll test = 1;
	void main() {
		ll k;
		while (in(n, k), n || k) {
			memset(dp, -1, sizeof(dp));

			REP(i,0,n) REP(j,0,n) in(A[i][j]);

			// ans is to get to n-1, n-1 with k negatives
			ll ans = get(n-1, n-1, k, 1);
			
			if (ans == -inf) printf("Case %lld: impossible\n", test++);
			else printf("Case %lld: %lld\n", test++, ans);
		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
