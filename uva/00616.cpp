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

namespace SOLVE {	
	ll possible(ll x, ll people, ll times) {
		if (times == people) return x % people == 0;
		if (x % people != 1) return 0;
		x = x / people * (people - 1);
		return possible(x, people, times+1);
	}

	void main() {
		ll n;
		while (cin >> n, n >= 0) {
			// it needs to = 1 mod some number
			// if i take 1 away from n, it needs to be divisible
			ll x = n-1;
			ll ans = -inf;
			for (ll f = 1; f * f <= x; f++) {
				if (x % f == 0) {
					if (possible(n, f, 0)) ans = max(ans, f);
					if (possible(n, x/f, 0)) ans = max(ans, x/f);
				}
			}
			if (ans == -inf) printf("%lld coconuts, no solution\n", n);
			else printf("%lld coconuts, %lld people and 1 monkey\n", n, ans);
			
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
