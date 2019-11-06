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

const ll mod = 1000000;

namespace SOLVE {	
	ll pent(ll x) {
		return (3 * x * x - x) / 2;
	}

	void modify(ll & x) {
		while (x < 0) x += mod;
		x %= mod;
	}

	void main() {
		// Found this online:
		// p[n] = p[n-1] + p[n-2] - p[n-5] - p[n-7] + p[n+12] + p[n-15]
		// for each p[n-k], the k is a pentagonal number
		// the sign alternates every 2

		ll n = 100000; // arbitrarily large number
		VLL p(n);
		VLL subtract(n); // the subtraction sequence - 1-indexed

		REP(i,0,n) {
			subtract[i] = i % 2 ? pent(i/2 + 1) : pent(-(i/2));
		}

		ll ans;
		p[0] = 1;
		REP(i,1,n) {			
			REP(j,1,n) {
				ll sign = ((j+1) % 4 >= 2) ? 1 : -1;
				if (i - subtract[j] >= 0) {
					p[i] += sign * p[i - subtract[j]];
					modify(p[i]);
				} else break;
			}

			if (p[i] == 0) {
				ans = i;
				break;
			}
		}

		cout << ans << endl;
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
