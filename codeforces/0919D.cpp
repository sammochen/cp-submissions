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

namespace SOLVE {	
	VVLL E;

	void main() {

		ll n, m;
		string s;
		cin >> n >> m >> s;

		E.resize(n+1);
		VLL indeg(n+1);

		REP(i,0,m) {
			ll a, b;
			cin >> a >> b;
			E[a].push_back(b);
			indeg[b]++;
		}

		queue<ll> Q;
		REP(i,1,n+1) {
			if (indeg[i] == 0) {
				Q.push(i);
			}
		}

		if (Q.size() == 0) {
			cout << -1 << endl;
			return;
		}

		VVLL dp(n+1, VLL(26));
		ll ans = 0;
		ll count = 0;

		// topological ordering
		while (Q.size()) {
			ll at = Q.front();
			Q.pop();

			count++;
			dp[at][s[at-1] - 'a']++;
			ans = max(ans, dp[at][s[at-1] - 'a']);

			// update all future ones
			for (ll to : E[at]) {
				indeg[to]--;
				if (indeg[to] == 0) Q.push(to);
				REP(i,0,26) {
					dp[to][i] = max(dp[to][i], dp[at][i]);

				}
			}

		}

		if (count != n) cout << -1 << endl;
		else cout << ans << endl;
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
