#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	VLL A;
	VVLL dp;

	ll get(ll a, ll b) {
		if (a == b+1) return 0;
		if (dp[a][b] != -1) return dp[a][b];
		
		ll ans = -inf;
		ll pre = 0;
		REP(i,a,b+1) {
			pre += A[i];
			ans = max(ans, pre - get(i+1, b));
		}
		ll suf = 0;
		RREP(i,b,a) {
			suf += A[i];
			ans = max(ans, suf - get(a, i-1));
		}
		dp[a][b] = ans;
		return ans;
	}
	void main() {
		ll n;
		while (cin >> n, n) {
			A.clear();
			dp.clear();
			A.resize(n);
			dp.resize(n, VLL(n, -1));

			REP(i,0,n) cin >> A[i];
			ll ans = get(0, n-1);

			cout << ans << endl;
		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
