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
	// returns the id of first element <= x
	ll bs(ll x, VLL & A) {
		if (x >= A[A.size() - 1]) return A[A.size() - 1];

		ll L = 0, R = A.size() - 1;
		while (L < R) {
			ll M = (L+R) / 2;
			if (A[M] <= x) L = M + 1;
			else R = M;
		}
		return A[L-1];
	}

	void main() {
		// read all the inputs
		ll n;
		in(n);
		VLL citypop(n), cityloc(n);
		REP(i,0,n) in(citypop[i]);
		REP(i,0,n) in(cityloc[i]);
		ll m;
		in(m);
		VLL cloudloc(m), cloudrange(m);
		REP(i,0,m) in(cloudloc[i]);
		REP(i,0,m) in(cloudrange[i]);

		// note all the points of interest, such as start of cloud, end of cloud
		set<ll> S;
		map<ll,ll> value;
		S.insert(-inf);
		REP(i,0,m) {
			ll a = cloudloc[i], b = cloudrange[i];
			
			S.insert(a-b);
			S.insert(a-b-1);
			S.insert(a+b+1);
			S.insert(a+b);
			value[a-b]++;
			value[a+b+1]--;
		}

		// change it to an array for easier access
		VLL A;
		for (ll s : S) A.push_back(s);

		// prefix sum for all the values
		REP(i,1,A.size()) {
			value[A[i]] = value[A[i-1]] + value[A[i]];
		}

		ll ans = 0; // holds all the cities that are already sunny
		map<ll,ll> pre; // prefix sum of populations of cities that are covered by 1 cloud

		// identify cities that are covered by 0 or 1 clouds
		REP(i,0,n) {
			ll cityA = bs(cityloc[i], A);
			if (value[cityA] == 0) ans += citypop[i];
			else if (value[cityA] == 1) {
				pre[cityA] += citypop[i];
			}
		}

		// work out prefix sums, then for each cloud see how many population it covers
		REP(i,1,A.size()) {
			pre[A[i]] = pre[A[i-1]] + pre[A[i]];
		}
		
		ll best = 0;
		REP(i,0,m) {
			ll score = pre[cloudloc[i] + cloudrange[i]] - pre[cloudloc[i] - cloudrange[i] - 1];
			best = max(best, score);
		}

		cout << ans + best << endl;
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
