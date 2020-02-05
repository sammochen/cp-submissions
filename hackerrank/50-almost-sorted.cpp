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
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll same(VLL & A, VLL & B) {
		REP(i,0,A.size()) {
			if (A[i] != B[i]) return 0;
		}
		return 1;
	}

	void main() {
		ll n;
		cin >> n;
		VLL A(n+2);
		A[0] = -inf;
		A[n+1] = inf;
		REP(i,0,n) {
			cin >> A[i+1];
		}

		VLL bump, dip;
		REP(i,1,n+1) {
			if (A[i-1] < A[i] && A[i] > A[i+1]) {
				bump.push_back(i);
			} else if (A[i-1] > A[i] && A[i] < A[i+1]) {
				dip.push_back(i);
			}
		}

		ll L = -1, R = -1;
		if (bump.size() == 1 && dip.size() == 1) {
			L = bump[0];
			R = dip[0];
		} else if (bump.size() == 2 && dip.size() == 2) {
			L = dip[0] - 1;
			R = bump[1] + 1;
		}
	
		if (L != -1) {
			VLL swapped = A;
			VLL reversed = A;
			VLL sorted = A;
			sort(sorted.begin(), sorted.end());

			swapped[L] = A[R];
			swapped[R] = A[L];

			REP(i,L,R+1) {
				reversed[i] = A[R - (i - L)];
			}

			if (same(swapped, sorted)) {
				cout << "yes" << endl;
				cout << "swap " << L << ' ' << R << endl;
				return;
			}

			if (same(reversed, sorted)) {
				cout << "yes" << endl;
				cout << "reverse " << L << ' ' << R << endl;
				return;
			}
		} 

		cout << "no" << endl;
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
