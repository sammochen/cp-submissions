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

	ll get(ll v, VVLL & E, VLL & dp) {
		if (dp[v] != -1) return dp[v];
		if (E[v].size() == 0) return 1;
		ll ans = 0;
		for (ll u : E[v]) {
			ans += get(u, E, dp);
		}
		dp[v] = ans;
		return ans;
	}
	void main() {
		ll n;
		ll f = 1;
		while (cin >> n) {
			if (!f) cout << endl;
			f = 0;

			VVLL E(n);
			VLL dp(n, -1);
			REP(i,0,n) {
				ll k;
				cin >> k;
				REP(j,0,k) {
					ll x;
					cin >> x;
					E[i].push_back(x);
				}
			}

			ll ans = get(0, E, dp);
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
