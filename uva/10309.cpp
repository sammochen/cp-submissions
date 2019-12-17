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
	void ddd(vector<string> A) {
		REP(i,0,10) debug(A[i]);
	}
	// switch 
	void sw(vector<string> & A, ll i, ll j) {
		if (i >= 0 && i < 10 && j >= 0 && j < 10) {
			A[i][j] = A[i][j] == 'O' ? '#' : 'O';
		}
	}

	// switch the whole cross
	void swcross(vector<string> & A, ll i, ll j) {
		if (i >= 0 && i < 10 && j >= 0 && j < 10) {
			sw(A, i, j);
			sw(A, i, j+1);
			sw(A, i, j-1);
			sw(A, i+1, j);
			sw(A, i-1, j);
		}
	}

	ll count(vector<string> A, ll i, ll j) {
		if (i == 10) {
			// check the top row
			REP(jj, 0, 10) {
				if (A[9][jj] == 'O') return inf;
			}
			return 0;
		}

		ll jj = j + 1, ii = i;
		if (jj == 10) {
			jj = 0;
			ii++;
		}

		// strategy: fill it in row by row, and keep the top rows perfect
		// the i = 0 row can be anything - only 2^10 possibilities.
		// fill the rest up iff necessarily
		if (i == 0) {
			vector<string> B = A;
			swcross(B, i, j);
			return min(count(A, ii, jj), count(B, ii, jj) + 1);
		} else {
			if (A[i-1][j] == 'O') {
				vector<string> B = A;
				swcross(B, i, j);
				return count(B, ii, jj) + 1;
			} else {
				return count(A, ii, jj);
			}
		}
	}

	void main() {
		string s;
		while (getline(cin, s), s != "end") {
			vector<string> A(10);
			REP(i,0,10) getline(cin, A[i]);

			cout << s << ' ' << count(A, 0, 0) << endl;
		}
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
