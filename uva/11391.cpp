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
	map<VVLL, ll> dp, done;
	ll n, m;

	ll valid(ll i, ll j, VVLL & A) {
		if (i >= 0 && i < n && j >= 0 && j < m) {
			return A[i][j];
		}
		return -1;
	}

	ll get(VVLL A) {
		if (done[A]) return dp[A];

		ll count = 0;
		ll ans = 0;
		VLL di = {-1,-1,-1,0,0,1,1,1};
		VLL dj = {-1,0,1,-1,1,-1,0,1};

		REP(i,0,A.size()) {
			REP(j,0,A[0].size()) {
				if (A[i][j] == 1) {
					count++;

					// look for adjacent, and see if it is a valid jump
					REP(k,0,8) {
						if (valid(i + di[k], j + dj[k], A) == 1 && valid(i + 2*di[k], j + 2*dj[k], A) == 0) {
							VVLL B = A;
							B[i][j] = 0;
							B[i+di[k]][j+dj[k]] = 0;
							B[i+2*di[k]][j+2*dj[k]] = 1;
							ans += get(B);
						}
					}
				}
			}
		}

		if (count == 1) ans = 1;

		done[A] = 1;
		dp[A] = ans;
		return ans;
	}

	ll test = 1;
	void main() {
		ll k;
		in(n, m, k);
		VVLL A(n, VLL(m));
		REP(i,0,k) {
			ll x, y;
			in(x, y);
			A[x-1][y-1] = 1;
		}

		printf("Case %lld: %lld\n", test++, get(A));
	}
}


signed main() {
	ll t;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
