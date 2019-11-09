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

const ll nax = 30001;

namespace SOLVE {	
	VLL coins = {5,10,20,50,100,200,500,1000,2000,5000,10000};
	VVLL dp(nax, VLL(coins.size(), -1));

	ll get(ll v, ll ind) {
		if (v == 0) return 1;
		if (v < 0 || ind < 0) return 0;

		if (dp[v][ind] != -1) return dp[v][ind];

		ll ans = 0;
		ans += get(v, ind-1); // choose to not use the coin
		ans += get(v - coins[ind], ind); // choose to use the coin
		
		dp[v][ind] = ans;
		return ans;
	}

	ll get(ll v) {
		return get(v, coins.size() - 1);
	}

	void main() {
		
		VLL amount(nax);
		amount[0] = 1;
		for (ll coin : coins) {
			RREP(i,nax-1,0) {
				amount[i + coin] += amount[i];
			}
		}

		string s;
		while (cin >> s) {
			string ss;
			for (char c : s) {
				if (c != '.') ss += c;
			}
			ll v = stoll(ss);
			if (v == 0) break;
			ll ans = get(v);
			printf("%6s%17lld\n", s.c_str(), ans);
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
