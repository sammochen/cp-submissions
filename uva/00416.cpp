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
	// input is string of Y and N, size 7
	ll bin(string s) {
		ll ans = 0;
		REP(i,0,7) {
			if (s[i] == 'Y') {
				ans |= (1LL << i);
			}
		}
		return ans;
	}

	void main() {
		VLL A = {
			bin("YYYYYYN"), // 0
			bin("NYYNNNN"), // 1
			bin("YYNYYNY"), // 2
			bin("YYYYNNY"), // 3
			bin("NYYNNYY"), // 4
			bin("YNYYNYY"), // 5
			bin("YNYYYYY"), // 6
			bin("YYYNNNN"), // 7
			bin("YYYYYYY"), // 8
			bin("YYYYNYY")  // 9
			}; 

		ll n;
		while (in(n),n) {
			VLL B(n);
			REP(i,0,n) {
				string s;
				in(s);
				B[i] = bin(s);
			}

			ll done = 0;
			REP(start,n-1,10) {
				ll good = 1;
				ll working = (1LL << 7) - 1;
				REP(i,0,n) {
					// check that there are no extras
					if ((B[i] & A[start - i]) != B[i]) good = 0;
					// current must be a subset of working bulbs
					if ((B[i] & working) != B[i]) good = 0;
					ll dead = A[start - i] ^ B[i];
					// any broken stays broken
					working &= ~dead;
				}
				if (good) {
					cout << "MATCH" << endl;
					done = 1;
					break;
				}
			}
			if (!done) {
				cout << "MISMATCH" << endl;
			}

			
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
