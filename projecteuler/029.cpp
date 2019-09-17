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

namespace SOLVE {
	ll n = 100;
	
	// return number of distinct given the power
	ll d(ll x) {
		VLL A(n*x + 1);
		REP(a,1,x+1) {
			REP(b,2,n+1) {
				A[a*b] = 1;
			}
		}
		ll ans = 0;
		for (ll aa : A) ans += aa;
		return ans;
	}
	
	void main() {
		// [a,b] = [a^k,b/k]
		
		VLL A(n+1);
		ll ans = 0;
		REP(i,2,n+1) {
			if (A[i]) continue;
			for (ll k = 1; k > 0; k++) {
				if (pow(i,k) > n) {
					ans += d(k-1);
					debug(i, k-1);
					break;
				}
				A[pow(i,k)] = 1;
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
