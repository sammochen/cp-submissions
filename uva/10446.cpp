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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<ull> VLL;
typedef vector<VLL> VVLL;

namespace SOLVE {	
	VVLL dp(65, VLL(65));
	VVLL done(65, VLL(65));

	ull f(ll a, ll b) {
		ull count = 1;
		if (a <= 0) return count;
		if (a == 1) return count;
		if (b < 1) return count;

		if (done[a][b]) return dp[a][b];

		REP(i,1,b+1) {
			count += f(a-i,b);
		}

		done[a][b] = 1;
		dp[a][b] = count;
		return count;
	}
	
	void main() {
		ll a, b;
		ll t = 1;
		while (cin >> a >> b) {
			if (a > 60) return;
			cout << "Case " << t << ": " << f(a,b) << endl;
			t++;
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
