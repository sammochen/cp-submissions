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
	void set(ll & x, ll bit, ll v) {
		if (v == 0) {
			x = x & (~(1LL << bit));
		} else {
			x = x | (1LL << bit);
		}
	}

	ll get(ll & x, ll bit) {
		return (1LL << bit) & x ? 1 : 0;
	}

	void setState(ll & state, ll ind, ll v) {
		set(state, ind*2+1, get(v, 1));
		set(state, ind*2, get(v, 0));
	}

	ll getState(ll & state, ll ind) {
		ll v = 0;
		v |= get(state, 2*ind+1) << 1;
		v |= get(state, 2*ind);
		return v;
	}

	void main() {
		ll n;
		cin >> n;
		ll state = 0;
		REP(i,0,n) {
			ll x;
			cin >> x;
			x--;
			setState(state, i, x);
		}
		
		queue<ll> Q;
		VLL dist((1LL << (2*n)), inf);
	
		Q.push(state);
		dist[state] = 0;

		while (Q.size()) {
			ll at = Q.front(); Q.pop();
			// find top of each pole
			VLL top(4, n);

			REP(i,0,n) {
				top[getState(at, i)] = min(top[getState(at, i)], i);
			}
			if (top[0] == 0 && top[1] == n && top[2] == n && top[3] == n) {
				cout << dist[at] << endl;
				return;
			}

			// try move the top of the 4 into something else
			REP(i,0,4) {
				if (top[i] == n) continue; // if nothing is on this stack

				// move it on a stack that has a value bigger than it
				REP(j,0,4) {
					if (top[j] > top[i]) {
						ll next = at;
						setState(next, top[i], j);

						if (dist[next] != inf) continue;

						Q.push(next);
						dist[next] = dist[at] + 1;
					}
				}
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
