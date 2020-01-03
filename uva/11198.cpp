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
	ll isprime(ll a) {
		VLL p = {0,0,2,3,0,5,0,7,0,0,0,11,0,13,0,0,0,17};
		return p[a] != 0;
	}
	VLL move(VLL A, ll i, ll j) {
		VLL B; // remove from i
		ll temp = A[i];
		REP(x,0,8) {
			if (x == i) continue;
			B.push_back(A[x]);
		}
		VLL C; // put it back in
		REP(x,0,8) {
			if (x == j) C.push_back(temp);
			if (x < 7) C.push_back(B[x]);
		}
		return C;
	}

	void main() {
		VLL A(8);
		ll test = 1;
		while (in(A[0]), A[0]) {
			REP(i,1,8) {
				in(A[i]);
			}

			queue<VLL> Q;
			map<VLL,ll> done, dist;
			Q.push(A);
			done[A] = 1;
			dist[A] = 0;
			ll ans = -1;
			while (Q.size()) {
				VLL at = Q.front(); Q.pop();

				ll sorted = 1;
				REP(i,0,8) {
					if (abs(at[i]) != i+1) sorted = 0;
				}
				if (sorted) {
					ans = dist[at];
					break;
				}
				// try all the moves
				REP(i,0,8) {
					REP(j,i+1,8) {
						if (at[i] * at[j] > 0) continue;
						if (!isprime(abs(at[i]) + abs(at[j]))) continue;
						VVLL nexts(4);
						nexts[0] = move(at, i, j-1);
						nexts[1] = move(at, i, j);
						nexts[2] = move(at, j, i);
						nexts[3] = move(at, j, i+1);

						REP(x,0,4) {
							if (done[nexts[x]]) continue;

							done[nexts[x]] = 1;
							dist[nexts[x]] = dist[at] + 1;
							Q.push(nexts[x]);
						}

					}
				}
			}
			printf("Case %lld: %lld\n", test++, ans);


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
