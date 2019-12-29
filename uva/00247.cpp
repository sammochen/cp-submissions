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
	ll time;
	VVLL scc;
	
	void dfs(ll at, VVLL & E, VLL & first, VLL & low, stack<ll> & stack, VLL & onstack) {
		first[at] = time;
		low[at] = time;
		stack.push(at);
		onstack[at] = 1;
		time++;

		for (ll to : E[at]) {
			if (first[to] == -1) {
				dfs(to, E, first, low, stack, onstack);
				low[at] = min(low[at], low[to]);
			} else if (onstack[to]) {
				low[at] = min(low[at], first[to]);
			}
		}

		if (first[at] == low[at]) {
			VLL comp;
			ll last;
			do {
				last = stack.top();
				comp.push_back(last);
				onstack[last] = 0;
				stack.pop();
			} while (last != at);

			scc.push_back(comp);
		}
	}	

	void main() {
		ll n, m;
		ll test = 1;
		while (in(n, m), n || m) {
			if (test != 1) cout << endl;

			time = 1;
			scc.clear();

			VVLL E(n);
			map<string, ll> ids;
			map<ll, string> names;
			ll id = 1;
			REP(i,0,m) {
				string a, b;
				in(a, b);

				if (ids[a] == 0) {
					ids[a] = id;
					names[id] = a;
					id++;
					
				}
				if (ids[b] == 0) {
					ids[b] = id;
					names[id] = b;
					id++;
				}

				E[ids[a] - 1].push_back(ids[b] - 1);
			}

			VLL first(n, -1);
			VLL low(n, -1);
			stack<ll> stack;
			VLL onstack(n);

			REP(i,0,n) {
				if (first[i] == -1) {
					dfs(i, E, first, low, stack, onstack);
				}
			}

			printf("Calling circles for data set %lld:", test++);
			if (m) cout << endl;
			debug(scc.size());
			for (VLL comp : scc) {
				REP(i,0,comp.size()) {
					cout << names[comp[i] + 1];
					if (i == comp.size() - 1) cout << endl;
					else cout << ", ";
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
