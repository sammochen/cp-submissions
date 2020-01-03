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
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll n, m;
	ll best, freq;

	void go(ll ind, ll mask, ll count, VLL & E) {
		if (ind == n) {
			best = max(best, count);
			ll maximal = 1;
			REP(i,0,n) {
				// if i is not in mask
				if (((1LL << i) & mask) == 0) {
					// and it has no edging cities inside
					if ((E[i] & mask) == 0) {
						// it is possible to add i, so it is not maximal
						maximal = 0;
					}
				}
			}
			freq += maximal;
			return;
		}

		// skip ind
		go(ind+1, mask, count, E);

		// try add the ind, only if neighbours arent there
		if (mask & E[ind]) return;

		go(ind+1, mask | (1LL << ind), count+1, E);
	}

	void main() {
		in(n, m);
		VLL E(n); // bitmask of city! 1 is edge
		REP(i,0,m) {
			ll a, b;
			in(a, b);
			E[a] |= (1LL << b);
			E[b] |= (1LL << a);
		}

		best = freq = 0;
		go(0, 0, 0, E);
		cout << freq << endl << best << endl;


	}
}


signed main() {
	ll t;
	t = 1;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
