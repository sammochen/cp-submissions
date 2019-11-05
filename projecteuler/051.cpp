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

const ll nax = 1000; // sqrt

namespace SOLVE {
	VLL p(nax*nax, 1);
	set<ll> P;
	
	void pp() {
		p[0] = 0;
		p[1] = 0;

		for (ll x = 2; x < nax; x++) {
			if (p[x] == 0) {
				continue;
			}

			for (ll f = 2; x * f < nax * nax; f++) {
				p[x*f] = 0;
			}
		}


		for (ll x = 1; x < nax * nax; x++) {
			if (p[x]) P.insert(x);
		}
	}

	ll isprime(ll x) {
		if (x > nax * nax * nax * nax) assert(0);
		if (x < nax * nax) {
			return p[x];
		}

		for (ll prime : P) {
			if (x % prime == 0) {
				return 0;
			}

			if (prime * prime > x) return 1;
		}
		return 1;
	}

	map<string, VLL> freq;

	void updateMap(ll x) {
		VVLL f(10);
		string s = to_string(x);
		REP(i,0,s.length()) {
			f[s[i]-'0'].push_back(i);
		}

		REP(i,0,10) {
			REP(mask,1,(1LL<<f[i].size())) {
				string copy = s;
				// for every mask, toggle asterisk
				REP(bit,0,f[i].size()) {
					if ((1LL << bit) & mask) {
						copy[f[i][bit]] = '*';
					}
				}

				freq[copy].push_back(x);
				if (freq[copy].size() >= 8) { // 8!!!!!
					ll ans = freq[copy][0];
					cout << ans << endl;
					exit(0);
				}
			}
		}
	}
	
	void main() {
		if (p[0] == 1) pp();
		
		ll n = 10000000;
		ll cnt = 0;
		REP(x,2,10000000) {
			if (isprime(x)) {
				cnt ++;
				updateMap(x);
			}
		}
		debug(n, cnt);

		

		
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
