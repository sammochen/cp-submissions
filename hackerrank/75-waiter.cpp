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

const ll nax = 120; // sqrt
const ll inf = 1e9 +7;

namespace SOLVE {
	VLL p(nax*nax, 1);
	VLL primes;
	VLL lowest(nax*nax, inf); // lowest[i] gives the lowest prime factor
	map<ll,ll> ind;
	
	void pp() {
		p[0] = 0;
		p[1] = 0;

		for (ll x = 2; x < nax; x++) {
			if (p[x] == 0) {
				continue;
			}

			lowest[x] = x;
			
			for (ll f = 2; x * f < nax * nax; f++) {
				p[x*f] = 0;
				if (x*f<10010) lowest[x*f] = min(lowest[x*f], x);
			}
		}

		ll count = 0;
		REP(i,0,nax*nax) if (p[i]) {
			ind[i] = count++;
			lowest[i] = i;
			primes.push_back(i);
		}
	}
	
	void main() {
		if (p[0] == 1) pp();

		ll n, k;
		cin >> n >> k;
		VLL A(n);
		REP(i,0,n) cin >> A[i];

		// tag the first k primes
		VVLL ans(k);
		VLL spare;

		REP(i,0,n) {
			if (ind[lowest[A[i]]] >= k) spare.push_back(A[i]);
			else ans[ind[lowest[A[i]]]].push_back(A[i]);
		}

		REP(i,0,k) {
			if (i%2 == 0) {
				REP(j,0,ans[i].size()) {
					cout << ans[i][j] << endl;
				}
			} else {
				RREP(j,ans[i].size() - 1, 0) {
					cout << ans[i][j] << endl;
				}
			}
		}

		if (k%2 == 1) {
			REP(i,0,spare.size()) cout << spare[i] << endl;
		} else {
			RREP(i,spare.size() - 1, 0) cout << spare[i] << endl;
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
