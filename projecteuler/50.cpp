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

const ll nax = 1200; // sqrt

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
	
	void main() {
		if (p[0] == 1) pp();
		
		// grab the list of primes under 1000000 and do prefix sums
		VLL P;
		REP(i,1,nax*nax) if (p[i]) P.push_back(i);
		VLL pre(P.size()+1);
		REP(i,0,P.size()) pre[i+1] = pre[i] + P[i];
		
		// say it is bounded by 600 since pre[600] >= n
		ll n = 1000000, m = 600;
		ll streak = 0, ans;
		
		// try all cominations up to 600 long - O(n^2)
		REP(i,1,m) {
			REP(j,i,m) {
				if (pre[j] - pre[i-1] < n && p[pre[j] - pre[i-1]]) {
					if (j - i + 1 > streak) {
						streak = j - i + 1;
						ans = pre[j] - pre[i-1];
					}					
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
