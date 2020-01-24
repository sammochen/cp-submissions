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
const ll nax = 1e6 + 10;

namespace SOLVE {	
	VLL p(nax, 0); // 0 is prime
	VLL primes;
	
	void getprime() {
		for (ll x = 2; x < nax; x++) {
			if (p[x]) {
				continue;
			}

			primes.push_back(x);
			
			for (ll y = x*x; y < nax; y += x) {
				p[y] = 1;
			}
		}
	}

	ll get(ll x) {
		if (x == 1) return 1;

		VLL factors;
		for (ll prime : primes) {
			while (x % prime == 0) {
				factors.push_back(prime);
				x /= prime;
			}
		}
		if (x != 1) factors.push_back(x);

		reverse(factors.begin(), factors.end());
		ll ans = 1, cur = 1;
		for (ll factor : factors) {
			cur *= factor;
			ans += cur;
		}
		return ans;
	}

	void main() {
		getprime();

		ll n;
		cin >> n;
		ll ans = 0;
		REP(i,0,n) {
			ll x;
			cin >> x;
			ans += get(x);
		}

		cout << ans << endl;
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
