#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
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

const ll inf = (ll)1e18 + 5;

const ll nax = 2300;

VLL pre(5000010);

namespace SOLVE {	
	VLL p(nax*nax, 0); // let p[i] be the sum of prime factors, not including itself

	void init() {
		p[0] = -1;
		p[1] = -1;

		for (ll x = 2; x < nax*nax; x++) {
			if (p[x]) {
				continue;
			}
			
			for (ll f = 2; x * f < nax*nax; f++) {
				p[x*f] += x;
			}
		}
	}
	
	ll psum(ll x) {
		if (p[x] == 0) return x;
		return p[x];
	}

	ll deprime(ll x) {
		return p[psum(x)] == 0;
	}
	
	void main() {
		init();

		REP(i,2,30) debug(i, p[i], psum(i), deprime(i));

		REP(i,1,pre.size()) pre[i] = pre[i-1] + deprime(i);

		ll a, b;
		while (cin >> a, a) {
			cin >> b;
			debug(a,b);
			cout << pre[b] - pre[a-1] << endl;
		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
