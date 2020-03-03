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

namespace SOLVE {	
	// returns the chance of:
	// choosing a at least once when choosing x times
	db solve(ll a, ll b, ll x) {
		// b -> b-x / (a+b) -> (a+b-x)
		db ans = 1.0;
		REP(i,0,x) {
			ans *= (db)(b - i);
			if (ans == 0) break;
			ans /= (db)(a + b - i);
		}

		return 1.0 - ans;
	}

	void main() {
		// it does not matter how many people are from other teams! only his team or not
		
		ll n, m, h;
		cin >> n >> m >> h;

		ll a = -1, b = 0;

		REP(i,1,m+1) {
			ll x;
			cin >> x;

			if (i == h) {
				a += x;
			} else {
				b += x;
			}
		}

		if (a + b < n - 1) {
			cout << -1 << endl;
			return;
		}

		// chance of choosing 
		db ans = solve(a,b,n-1);
		cout << setprecision(20) << ans << endl;

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
