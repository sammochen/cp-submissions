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

const ll nax = 320; // sqrt(100000)

namespace SOLVE {
	VVLL p(nax*nax);
	
	void pp() {
		for (ll x = 2; x < nax; x++) {
			if (p[x].size() != 0) {
				continue;
			}
			
			for (ll f = 2; x * f < nax * nax; f++) {
				p[x*f].push_back(x);
			}
		}
	}
	
	void main() {
		pp();

		ll n;
		cin >> n;

		if (n == 1) {
			cout << 1 << endl;
			return;
		}

		map<ll,ll> dp;
		ll ans = 0;

		REP(i,0,n) {
			ll x;
			cin >> x;

			ll best = 0;
			for (ll f : p[x]) {
				best = max(best, dp[f]);
				best = max(best, dp[x/f]);
			}
			best = max(best, dp[x]);

			for (ll f : p[x]) {
				dp[f] = max(dp[f], best+1);
				dp[x/f] = max(dp[x/f], best+1);
			}	
			dp[x] = max(dp[x], best+1);

			ans = max(ans, best+1);	
		}

		cout << ans << endl;



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
