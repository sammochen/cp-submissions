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

const ll nax = 100; // sqrt
const ll mod = 1e9+7;

namespace SOLVE {
	VLL p(nax*nax, 1);
	
	void pp() {
		p[0] = 0;
		p[1] = 0;

		for (ll x = 2; x < nax; x++) {
			if (p[x] == 0) {
				continue;
			}
			
			for (ll f = 2; x * f < nax * nax; f++) {
				p[x*f] = 0;
			}
		}
	}
	
	void main() {
		if (p[0] == 1) pp();

		ll n;
		cin >> n;
		VLL f(4501);
		REP(i,0,n) {
			ll x;
			cin >> x;
			f[x]++;
		}

		VLL dp(8192);
		dp[0] = 1;
		REP(x,3500,4501) {
			VLL next = dp;

			// try against all possible xors, then process
			REP(i,0,8192) {
				// add x^i by number of odds
				next[x ^ i] += dp[i] * ((f[x] + 1) / 2) % mod;
				next[x ^ i] %= mod;
				// add i by number of evens
				next[i] += dp[i] * (f[x] / 2) % mod;
				next[i] %= mod;
			}

			dp = next;
		}

		ll ans =0;
		REP(x,0,8192) {
			ans += p[x] * dp[x] % mod;
			ans %= mod;
		}

		cout << ans << endl;
	}
}


signed main() {
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
