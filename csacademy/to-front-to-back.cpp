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
	void main() {
		ll n;
		cin >> n;
		VLL A(n);
		REP(i,0,n) cin >> A[i];
		
		VLL lis(n+1); // lis[i] = length of longest increasing subsequence that ends at i	
		ll length = 0;
		ll L, R;
		
		
		REP(i,0,n) {
			lis[A[i]] = lis[A[i] - 1] + 1;
			if (lis[A[i]] > length) {
				length = lis[A[i]];
				R = A[i];
				L = A[i] - lis[A[i]] + 1;
			}
		}
		
		ll ans = n - length;
		cout << ans << endl;
		RREP(j,L-1,1) {
			cout << j << ' ' << 0 << endl;
		}
	
		REP(j,R+1,n+1) {
			cout << j << ' ' << 1 << endl;
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
