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

const ll inf = 1e9+7;

namespace SOLVE {	
	VLL dp(1005, -1);

	ll get(ll i) {
		if (i == 0) return 0;
		if (i < 0) return inf;
		if (dp[i] != -1) return dp[i];
		
		dp[i] = min({get(i-1), get(i-2), get(i-5)}) + 1;
		return dp[i];
	}

	void main() {
		ll n;
		cin >> n;
		VLL A(n);

		ll small = inf;
		REP(i,0,n) {
			cin >> A[i];
			small = min(small, A[i]);
		}

		ll ans = inf;

		// Safety - it might be lower than the small - but no more than 5 since that will never be optimal
		REP(d,0,6) {
			ll cur = 0;
			REP(i,0,n) {
				cur += get(A[i] - small + d);
			}
			ans = min(ans, cur);
		}

		cout << ans << endl;
	}
}


signed main() {
	int t;
	// t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
