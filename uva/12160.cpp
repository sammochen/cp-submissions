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

const ll inf = 1e9+7;

namespace SOLVE {	
	void main() {
		ll t = 1;
		while (1) {
			ll start, end, n;
			cin >> start >> end >> n;
			if (start == 0 && end == 0 && n == 0) return;
			VLL steps(n);
			REP(i,0,n) cin >> steps[i];

			VLL d(10000, inf);
			queue<ll> Q;

			d[start] = 0;
			Q.push(start);
			while (Q.size()) {
				ll at = Q.front();
				Q.pop();

				for (ll step : steps) {
					ll to = (at + step) % 10000;
					if (d[at] + 1 < d[to]) {
						d[to] = d[at] + 1;
						Q.push(to);
					}
				}
			}

			cout << "Case " << t++ << ": ";
			if (d[end] == inf) cout << "Permanently Locked" << endl;
			else cout << d[end] << endl;
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
