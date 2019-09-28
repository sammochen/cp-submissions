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
	void f() {
		cout << -1 << endl;
		exit(0);
	}

	void main() {
		ll n, k, m;
		cin >> n >> k >> m;
		if (k == pow(2, n)) {
			if (m != n) f();
			REP(i,1,pow(2,n)+1) cout << i << ' ';
			return;
		}

		if (k < pow(2,m)) {
			f();
		}

		// if m was 2:
		// 1 2 3 x x+1 4 5..

		REP(i,1,pow(2,m)) {
			cout << i << ' ';
		}

		cout << k << ' ';
		if (pow(2,n) != k) cout << k+1 << ' ';

		REP(i,pow(2,m),pow(2,n)+1) {
			if (i != k && i != k+1) {
				cout << i << ' ';
			}
		}




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
