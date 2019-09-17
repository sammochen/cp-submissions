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

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
string to_string(bool b) {return b ? "true" : "false";}
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

namespace SOLVE {
	VLL p(nax*nax, 1);
	
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
	}
	
	ll same(ll a, ll b) {
		string A = to_string(a);
		string B = to_string(b);
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		return A == B;
	}
	
	ll same(ll a, ll b, ll c) {
		return same(a,b) && same(b,c);
	}
	
	void main() {
		if (p[0] == 1) pp();
		
		string ans;
		
		// iterate through i
		REP(i,1000,10000) {
			string ii = to_string(i);
			
			// let j be some larger permutation of i
			while (next_permutation(ii.begin(), ii.end())) {
				ll j = stol(ii);
				
				// let k be next in the arithmetic sequence
				ll k = 2 * j - i;
				if (k >= 10000) break;
				if (same(i,j,k) && p[i] && p[j] && p[k]) {
					ans = to_string(i) + to_string(j) + to_string(k);
				}
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
