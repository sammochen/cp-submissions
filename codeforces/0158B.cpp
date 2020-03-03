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
	void main() {
		ll n;
		cin >> n;
		VLL A(5);
		ll x;
		REP(i,0,n) {
			cin >> x;
			A[x]++;
		}

		ll ans = 0;
		ans += A[4];
		A[4] = 0;

		ll onethree = min(A[1], A[3]);
		ans += onethree;
		A[1] -= onethree;
		A[3] -= onethree;

		ans += A[3];
		A[3] = 0;

		ll twos = A[2] / 2;
		ans += twos;
		A[2] %= 2;

		if (A[2] && A[1] >= 2) {
			ans += 1;
			A[2] = 0;
			A[1] -= 2;
		} else if (A[2] && A[1] == 1) {
			ans += 1;
			A[2] = 0;
			A[1] = 0;
		} else if (A[2] && A[1] == 0) {
			ans += 1;
			A[2] = 0;
			A[1] = 0;
		}

		ans += A[1] % 4 == 0 ? A[1] / 4 : A[1] / 4 + 1;
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
