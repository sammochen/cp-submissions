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

const ll inf = 1e18;

namespace SOLVE {	
	ll get(VVLL & dp, VLL & A, ll i, ll k) {
		if (i == -1) return 0;
		if (k == 0) return inf;
		
		if (dp[i][k] != -1) return dp[i][k];

		ll ans = inf;
		REP(j,0,i+1) {
			ans = min(ans, get(dp, A, j-1, k-1) + (A[i] - A[j]) * (A[i] - A[j]));
		}

		dp[i][k] = ans;
		return ans;
	}

	void main() {
		ll n, k;
		cin >> n >> k;

		VLL A(n);
		VVLL dp(n, VLL(k+1, -1));
		REP(i,0,n) cin >> A[i];
		sort(A.begin(), A.end());

		ll ans = get(dp, A, n-1, k);
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
