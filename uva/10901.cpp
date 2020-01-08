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
	ll first = 1;
	void main() {
		if (!first) cout << endl;
		first = 0;

		ll n, t, m;
		cin >> n >> t >> m;
		vector<queue<PLL>> sides(2); // sides[0] is L, [1] is R
		VLL ans(m);

		REP(i,0,m) {
			ll x;
			string s;
			cin >> x >> s;
			if (s == "left") sides[0].push({x,i});
			else sides[1].push({x,i});
		}

		ll time = -inf;
		ll side = 0; // 0-L, 1-R
		while (sides[0].size() || sides[1].size()) {
			// if there are no cars, it waits until a car arrives on either end
			ll firstcar = inf;
			if (sides[0].size()) firstcar = min(firstcar, sides[0].front().first);
			if (sides[1].size()) firstcar = min(firstcar, sides[1].front().first);
			time = max(time, firstcar);

			// load all the cars that are there, and load it
			ll count = 0;
			while (sides[side].size() && sides[side].front().first <= time && count < n) {
				ans[sides[side].front().second] = time+t;
				sides[side].pop();
				count++;
			}

			time += t;
			side = !side;
		}

		REP(i,0,m) {
			cout << ans[i] << endl;
		}
	}
}


signed main() {
	ll t;
	t = 1;
	cin >> t;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
