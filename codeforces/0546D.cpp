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

const ll n = 5000000;
const ll nax = 2240; // sqrt(n)

namespace SOLVE {
	VLL p(nax*nax, -1);
	
	void pp() {
		for (ll x = 2; x < nax; x++) {
			if (p[x] != -1) {
				continue;
			}
			
			for (ll f = 2; x * f < nax * nax; f++) {
				p[x*f] = x; // note the number with a prime factor
			}
		}
	}
	
	void main() {
		if (p[0] == -1) pp();

		VLL P; // list of primes under 5000000
		REP(i,1,nax) {
			if (p[i]) P.push_back(i);
		}

		VLL dp(n+1);
		VLL pre(n+1);
		REP(i,2,n+1) {
			if (p[i] == -1) dp[i] = 1;
			else {
				dp[i] = dp[i / (p[i])] + 1;
			}
			pre[i] = pre[i-1] + dp[i];
		}

		ll q;
		cin >> q;
		string ans;

		REP(i,0,q) {
			ll a, b;
			cin >> a >> b;
			ll x = pre[a] - pre[b];
			ans += to_string(x) + "\n";
		}

		cout << ans << endl;
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
