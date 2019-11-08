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
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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
	VLL coins = {1,5,10,25,50};
	VVLL dp(30001, VLL(5, -1));

	ll get(ll v, ll ind) {
		if (v < 0) return 0;
		if (v == 0) return 1;
		if (dp[v][ind] != -1) return dp[v][ind];
		
		ll ans = 0;
		REP(i,0,ind+1) {
			ans += get(v - coins[i], i);
		}
		dp[v][ind] = ans;
		return ans;
	}

	ll get(ll v) {
		return get(v, 4);
	}

	void main() {
		ll x;
		while (cin >> x) {
			ll ans = get(x);
			if (ans == 1) {
				cout << "There is only 1 way to produce " << x << " cents change." << endl;
			} else {
				cout << "There are " << ans << " ways to produce " << x << " cents change." << endl;
			}
		}
	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
