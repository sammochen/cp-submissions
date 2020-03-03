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
	ll countp(ll L, ll R, ll p) {
		ll ans = 0;
		if (L % p == 0) ans++;
		ans += (R / p) - (L / p);
		return ans;
	}

	void main() {
		ll n, p;
		cin >> n >> p;
		vector<db> E(2); // E[0] is expected if prime, E[1] is expected if not prime
		// vector<db> p(2); // p[0] is probability of prev being prime, 1 being nonprime

		vector<pair<db,db>> A(n+1); // A[i].first is prime, .second is nonprime
		REP(i,0,n) {
			ll L, R;
			cin >> L >> R;
			ll total = R - L + 1;
			ll primes = countp(L, R, p);
			A[i].first = (db)(primes) / total;
			A[i].second = 1.0 - A[i].first;
		}

		A[n] = A[0];

		double ans = 0;
		REP(i,1,n+1) {
			ans += A[i].first;
			ans += A[i].second * A[i-1].first;
		}
		ans *= 2000; // benefit per pair
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
