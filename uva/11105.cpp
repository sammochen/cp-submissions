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
	VLL p(250010, 1);
	VLL primes;
	
	void pp() {
		p[0] = 0;

		for (ll x = 5; x < 510; x += 4) {
			if (p[x / 4] == 0) {
				continue;
			}
			
			for (ll f = 5; 1; f += 4) {
				if (x*f/4 >= 250010) break;
				p[x*f / 4] = 0;
			}
		}

		REP(i,0,p.size()) {
			if (p[i]) primes.push_back(i*4 + 1);
		}

	}


	void main() {
		pp();
		debug(primes.size());
		map<ll,ll> semi;
		REP(i,0,primes.size()) {
			REP(j,i,primes.size()) {
				if (primes[i]*primes[j] > 1000010) break;
				semi[primes[i]*primes[j] / 4] = 1;
			}
		}

		VLL pre(250010);
		REP(i,1,pre.size()) {
			pre[i] = pre[i-1] + semi[i];
		}

		ll n;
		while (cin >> n, n) {
			cout << n << ' ' << pre[n/4] << endl;
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
