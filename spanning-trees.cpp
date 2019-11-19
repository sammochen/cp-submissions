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

namespace SOLVE {	
	void main() {
		ll a, b;
		cin >> a >> b;

		if ((a == 2 || a == 3) && b == 0) {
			cout << -1 << endl;
		}

		ll n = a - b;
		cout << (a-b-1)*2 + b << endl;

		ll E = 1, V = 0;

		if (n == 1) {
			// 1 node, no edge in common
			V = 1;
		} if (n == 2) {
			// 3 nodes, 1 edge in common
			cout << "1 2 " << E++ << endl;
			cout << "2 3 " << E++ << endl;
			cout << "1 3 " << E++ << endl;
			V = 3;
		} else if (n == 3) {
			// 4 nodes, 1 edge in common
			cout << "1 2 " << E++ << endl;
			cout << "1 3 " << E++ << endl;
			cout << "1 4 " << E++ << endl;
 			cout << "2 4 " << E++ << endl;
			cout << "3 4 " << E++ << endl;
			V = 4;
		} else if (n >= 4) {
			// n nodes, 0 edge in common
			for (ll x = 1; x <= n-1; x++) {
				cout << x << ' ' << x+1 << ' ' << E++ << endl;
			}
			for (ll x = 2; x <= n-2; x+=2) {
				cout << x << ' ' << x+2 << ' ' << E++ << endl;
			}
			cout << n- (n%2) << ' ' << 1 << ' ' << E++ << endl;
			for (ll x = 1; x <= n-2; x+=2) {
				cout << x << ' ' << x+2 << ' ' << E++ << endl;
			}
			V = n;
		}

		REP(i, V+1, a+1) cout << "1 " << i << " " << E++ << endl;
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
