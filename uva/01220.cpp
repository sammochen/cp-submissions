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
	map<PLL, PLL> dp;
	map<PLL, ll> done;

	// return max, unique
	PLL get(ll at, ll prev, ll on, VVLL & E) {
		if (done[{at,on}]) return dp[{at,on}];

		ll ans = on;
		ll unique = 1;
		for (ll to : E[at]) {
			if (prev == to) continue;

			if (on) {
				PLL pos = get(to, at, 0, E);
				ans += pos.first;
				unique &= pos.second;
			} else {
				PLL pos1 = get(to, at, 0, E);
				PLL pos2 = get(to, at, 1, E);
				if (pos1.first == pos2.first) {
					ans += pos1.first;
					unique = 0;
				} else if (pos1.first > pos2.first) {
					ans += pos1.first;
					unique &= pos1.second;
				} else {
					ans += pos2.first;
					unique &= pos2.second;
				}
			}
		}
		done[{at,on}] = 1;
		dp[{at,on}] = {ans, unique};
		return {ans, unique};
	}
	void main() {
		ll n;
		while (in(n), n) {
			done.clear();
			
			ll id = 1;
			map<string, ll> ids;
			VVLL E(n);

			string s;
			in(s);

			ids[s] = id++;

			REP(i,0,n-1) {
				string a, b;
				in(a,b);
				if (ids[a] == 0) {
					ids[a] = id++;
				} 
				if (ids[b] == 0) {
					ids[b] = id++;
				}
				E[ids[a] - 1].push_back(ids[b] - 1);
				E[ids[b] - 1].push_back(ids[a] - 1);

			}

			PLL pos1 = get(0, 0, 0, E);
			PLL pos2 = get(0, 0, 1, E);
			ll ans = 0;
			ll unique = 1;
			if (pos1.first == pos2.first) {
				ans += pos1.first;
				unique = 0;
			} else if (pos1.first > pos2.first) {
				ans += pos1.first;
				unique &= pos1.second;
			} else {
				ans += pos2.first;
				unique &= pos2.second;
			}
			string sans = unique ? "Yes" : "No";
			cout << ans << ' ' << sans << endl;
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
