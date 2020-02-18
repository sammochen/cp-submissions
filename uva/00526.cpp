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
string to_string(char c) {string s = string(1, c);return s;}
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
	string a, b;

	map<PLL,ll> dp, done;

	ll dist(ll i, ll j) {
		if (i == -1) return (j+1);
		if (j == -1) return (i+1);
		if (done[{i,j}]) return dp[{i,j}];

		ll ans = inf;

		if (a[i] == b[j]) {
			ans = min(ans, dist(i-1, j-1)); // no cost
		}

		// replace
		ans = min(ans, 1 + dist(i-1, j-1));
		// delete one 
		ans = min(ans, 1 + dist(i-1, j));
		// add one
		ans = min(ans, 1 + dist(i, j-1));

		done[{i,j}] = 1;
		dp[{i,j}] = ans;

		return ans;
	}

	ll cnt;
	void bt(ll i, ll j) {
		if (i == -1 && j == -1) return;
		if (i == -1) {
			printf("%lld Insert %lld,%c\n", cnt++, i+2, b[j]);
			bt(i, j-1);
			
		} else if (j == -1) {
			printf("%lld Delete %lld\n", cnt++, i+1);
			bt(i-1, j);
			
		} else if (a[i] == b[j]) {
			bt(i-1, j-1);

		} else if (1 + dist(i-1, j-1) == dist(i, j)) {
			printf("%lld Replace %lld,%c\n", cnt++, i+1, b[j]);
			bt(i-1, j-1);
			
		} else if (1 + dist(i-1, j) == dist(i, j)) {
			printf("%lld Delete %lld\n", cnt++, i+1);
			bt(i-1, j);
			
		} else if (1 + dist(i, j-1) == dist(i, j)) {
			printf("%lld Insert %lld,%c\n", cnt++, i+2, b[j]);
			bt(i, j-1);
		}
	}

	ll first = 1;
	void main() {
		while (getline(cin, a) && getline(cin, b)) {
			if (!first) cout << endl;
			first = 0;
			done.clear();

			cout << dist(a.length() - 1, b.length() - 1) << endl;
			cnt = 1;
			bt(a.length() - 1, b.length() - 1);
			
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
