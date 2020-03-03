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
	VLL subtree;
	vector<db> etime;

	// subtree
	ll s(ll at) {
		ll count = 1;
		for (ll to : E[at]) {
			count += s(to);
		}
		subtree[at] = count;
		return count;
	}

	// random visit
	void r(ll at) {
		// v(at) = v(parent) + 1 + sum(subtree(allotherchildren)) / 2 
		// as a parent, you can determine the time of all children
		for (ll to : E[at]) {
			etime[to] = etime[at] + 1 + (subtree[at] - 1 - subtree[to]) / 2.0;
			r(to);
		}
	}

	void main() {
		ll n;
		cin >> n;
		E.resize(n+1);
		subtree.resize(n+1);
		etime.resize(n+1);
		etime[1] = 1;

		REP(i,2,n+1) {
			ll x;
			cin >> x;
			E[x].push_back(i);
		}

		s(1);
		r(1);
		
		REP(i,1,n+1) {
			cout << etime[i] << ' ';
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
