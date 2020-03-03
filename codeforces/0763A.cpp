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

namespace SOLVE {	
	VVLL E;
	VLL colours;

	// returns 1 if the subtree rooted at 'at' is all 'colour'
	ll onecolour(ll at, ll prev, ll colour) {
		if (colours[at] != colour) return 0;
		for (ll to : E[at]) {
			if (to != prev) {
				if (onecolour(to, at, colour) == 0) return 0;
			}
		}
		return 1;
	}

	// returns 1 if you 'can' root the tree from v
	ll root(ll v) {
		for (ll e : E[v]) {
			if (onecolour(e, v, colours[e]) == 0) return 0;
		}
		return 1;
	}

	void main() {
		ll n;
		cin >> n;
		E.resize(n+1);
		REP(i,0,n-1) {
			ll a, b;
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		colours.resize(n+1);
		REP(i,1,n+1) {
			cin >> colours[i];
		}

		ll start1 = -1, start2 = -1;
		// look for an edge with two different colours
		REP(one,1,n+1) {
			for (ll two : E[one]) {
				if (colours[one] != colours[two]) {
					start1 = one, start2 = two;
				}
			}
		}

		if (start1 == -1) {
			cout << "YES" << endl;
			cout << 1 << endl;
			return;
		}

		if (root(start1)) {
			cout << "YES" << endl;
			cout << start1 << endl;
			return;
		}

		if (root(start2)) {
			cout << "YES" << endl;
			cout << start2 << endl;
			return;
		}

		cout << "NO" << endl;

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
