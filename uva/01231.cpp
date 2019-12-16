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
	VVLL dp;
	VVLL acorns;
	ll t, h, f;

	// returns amount if you are at h. you can pick up any acorns
	ll get(ll i, ll j) {
		if (j < 0) return 0;
		if (dp[i][j] != -1) return dp[i][j];
		ll ans = 0;		
		
		if (i < t) {
			// pick up acorns
			ans += acorns[i][j];

			// either: go down or go to the limbo tree
			ans += max(get(i, j-1), get(t, j-f));
		} else {
			// if at the limbo tree, try all of them
			REP(tt,0,t) {
				ans = max(ans, get(tt, j));
			}
		}

		dp[i][j] = ans;
		return ans;
	}

	void main() {
		
		in(t, h, f);
		acorns.clear();
		acorns.resize(t, VLL(h+1, 0));
		REP(i,0,t) {
			ll x;
			in(x);
			REP(j,0,x) {
				ll y;
				in(y);
				acorns[i][y]++;
			}
		}

		dp.clear();
		dp.resize(t+1, VLL(h+1, -1));

		ll ans = 0;
		REP(i,0,t) {
			ans = max(ans, get(i, h));
		}
		printf("%lld\n", ans);



	}
}


signed main() {
	ll t;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
