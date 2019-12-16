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
	ll n, r;
	VLL A;
	db b, v, e, f;
	map<PLL,db> costdp;
	map<PLL,ll> costdone;
	vector<db> dp;

	// returns cost to go from start, distance d
	db getcost(ll start, ll d) {
		if (d == 0) return 0;
		PLL state = {start, d};
		if (costdone[state]) return costdp[state];

		ll x = d - 1; 
		db cost = x >= r ? (1.0 / (v - e * (x - r))) : (1.0 / (v - f * (r - x)));
		costdp[state] = getcost(start, d - 1) + cost;
		costdone[state] = 1;
		return costdp[state];
	}

	db get(ll ind) {
		if (dp[ind] != -1) return dp[ind];
		db ans = getcost(0, A[ind]); // max cost is just go straight there
		REP(i,0,ind) {
			ans = min(ans, get(i) + getcost(A[i], A[ind] - A[i]) + b); // find some intermediate stop
		}
		dp[ind] = ans;
		return ans;
	}

	void main() {
		
		cin >> n;
		if (n == 0) exit(0);

		A.clear();
		A.resize(n);
		costdone.clear();
		dp.clear();
		dp.resize(n, -1);

		REP(i,0,n) cin >> A[i];
		
		cin >> b >> r >> v >> e >> f;

		db ans = get(n-1);
		cout << fixed << setprecision(4) << ans << endl;

	}
}


signed main() {
	while (1) {
		SOLVE::main();
	}

	return 0;
}
