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
	ll mod = 1e9;
	
	VVLL operator*(VVLL a, VVLL b) {
		VVLL c(a.size(), VLL(b[0].size()));
		
		REP(i,0,a.size()) {
			REP(j,0,a[0].size()) {
				REP(k,0,b[0].size()) {
					c[i][k] += a[i][j] * b[j][k];
					c[i][k] %= mod;
				}
			}
		}
		
		return c;			
	}
	
	VVLL operator^(VVLL a, ll k) {
		if (k == 1) {
			return a;
		}
		VVLL half = a ^ (k / 2);
		half = half * half;
		if (k % 2) {
			half = half * a;
		}
		return half;
	}

	void main() {
		VVLL A(22, VLL(22));
		ll a,b,c,d,e,f,g,h,n;
		cin >> a >> b >> c >> d >> e >> f >> g >> h >> n;
		A[0][a-1]++;
		A[0][b-1 + 11]++;
		A[0][c-1 + 11]++;
		A[0][9] = 1;

		A[9][9] = d;
		A[9][10] = d;
		A[10][10] = d;

		A[11][e-1 + 11]++;
		A[11][f-1]++;
		A[11][g-1]++;
		A[11][20] = 1;

		A[20][20] = h;
		A[20][21] = h;
		A[21][21] = h;

		REP(i,1,9) A[i][i-1] = 1;
		REP(i,12,20) A[i][i-1] = 1;

		VVLL x(22, VLL(1, 1));
		x[9][0] = 0;
		x[10][0] = 1;

		x[20][0] = 0;
		x[21][0] = 1;

		n++;

		VVLL ans = (A^n)*x;
		cout << ans[0][0] << ' ' << ans[11][0] << endl;
		
	}
}


signed main() {
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
