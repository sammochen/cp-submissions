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
	string s;
	ll n;

	ll three(ll i) {
		ll mask = 0;
		REP(j,i-1,i+2) {
			if (j >= 0 && j < n) mask |= (1LL << j);
		}
		return mask;
	}

	ll makei(char c) {
		if (c >= 'A' && c <= 'Z') {
			return c - 'A' + 9;
		} else {
			return c - '1';
		}
	}
	
	ll get(ll col, ll mask, VVLL & dp) {
		if (col == n) return 1;
		if (dp[col][mask] != -1) return dp[col][mask];
		ll ans = 0;

		if (s[col] != '?') {
			ll i = makei(s[col]);
			if ((1LL << i) & mask) ans = 0;
			else ans = get(col + 1, three(i), dp);
		} else {
			REP(i,0,n) {
				if (!((1LL << i) & mask)) ans += get(col + 1, three(i), dp);
			}
		}

		dp[col][mask] = ans;
		return ans;
	}
	void main() {
		while (cin >> s) {
			n = s.size();
			VVLL dp(n, VLL(1LL << n, -1));

			ll ans = get(0, 0, dp);
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
