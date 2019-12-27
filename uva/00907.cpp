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
	// returns the min max up to ind with k splits
	ll get(ll ind, ll k, VLL & A, VVLL & dp) {
		if (ind == -1) return 0;
		if (k == 0) return inf;
		if (dp[ind][k] != -1) return dp[ind][k];

		ll total = 0;
		ll best = inf;

		// return the best split from ind backwards
		RREP(i,ind,0) {
			total += A[i];
			best = min(best, max(total, get(i-1, k-1, A, dp)));
		}
		
		dp[ind][k] = best;
		return best;
	}
	void main() {
		ll n, k;
		while (cin >> n >> k) {
			n++;
			k++;
			VLL A(n);
			REP(i,0,n) cin >> A[i];

			// how to split A into k bits, with the minimum total
			VVLL dp(n, VLL(k+1, -1));
			ll ans = get(n-1, k, A, dp);
			printf("%lld\n", ans);
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
