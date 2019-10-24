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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {
	VVLL cost; // cost[node][color]
	VVLL E;
	VLL colours;

	ll other(ll a, ll b) {
		REP(i,0,3) {
			if (i != a && i != b) {
				return i;
			}
		}
		return -1;
	}

	ll price(ll at, ll prev, ll ac, ll pc) {
		ll ans = cost[at][ac];
		colours[at] = ac;

		for (ll to : E[at]) {
			if (to != prev) {
				ans += price(to, at, other(ac,pc), ac);
			}
		}

		return ans;

	}

	void main() {
		ll n;
		cin >> n;
		cost.resize(n+1, VLL(3));
		E.resize(n+1);
		colours.resize(n+1);

		REP(i,0,3) {
			REP(j,0,n) {
				cin >> cost[j+1][i];
			}
		}

		REP(i,0,n-1) {
			ll a, b;
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		// find a leaf, iterate all 6 possibilities (simplifies things)
		
		ll leaf;
		REP(i,1,n+1) {
			if (E[i].size() == 1) {
				leaf = i;
			}
			if (E[i].size() >= 3) {
				cout << -1 << endl;
				return;
			}
		}

		ll finalans = inf;
		VLL finalcolours;

		REP(i,0,3) {
			REP(j,1,3) {
				ll c1 = i, c2 = (i+j)%3;
				ll ans = price(E[leaf][0], leaf, c1, c2) + cost[leaf][c2];
				colours[leaf] = c2;

				if (ans < finalans) {
					finalans = ans;
					finalcolours = colours;
				}
			}
		}

		cout << finalans << endl;
		REP(i, 1, n+1) {
			cout << finalcolours[i] + 1 << ' ';
		}
		cout << endl;
		

				


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
