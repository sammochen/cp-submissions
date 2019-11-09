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

const ll nax = 50; // sqrt

namespace SOLVE {
	VLL p(nax*nax, 1);
	VLL P;
	
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

		REP(i,0,nax*nax) if (p[i]) P.push_back(i);
	}
	
	void main() {
		if (p[0] == 1) pp();
		
		ll n = 1121, k = 15;
		
		// dp[n][k][maxprime] = dp[n-prime][k-1][prime]
		// we do not need to keep track of which prime is used, so memory can be reduced by a dimension
		// runtime: O(n * k * primes)
		// memory: O(n * k)

		VVLL dp(n, VLL(k)); // dp[i][j] gives number of ways of making i allowing up to j primes
		dp[0][0] = 1;

		for (ll prime : P) {
			RREP(i,n-1,0) {
				RREP(j,k-1,0) {
					if (i + prime < n && j + 1 < k) dp[i+prime][j+1] += dp[i][j];
				}
			}
		}

		ll a, b;
		while (cin >> a >> b) {
			if (a == 0 && b == 0) return;
			ll ans = dp[a][b];
			cout << ans << endl;
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
