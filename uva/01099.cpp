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
	VLL A;
	ll k;

	VLL countdp;
	VLL sumdp;
	VVLL dp;

	ll count(ll mask) {
		if (countdp[mask] != -1) return countdp[mask];
		ll ans = 0;
		REP(ind,0,k) {
			if ((1LL << ind) & mask) ans += 1;
		}
		countdp[mask] = ans;
		return ans;
	}

	ll sum(ll mask) {
		if (sumdp[mask] != -1) return sumdp[mask];

		ll ans = 0;
		REP(ind,0,k) {
			if ((1LL << ind) & mask) ans += A[ind];
		}
		sumdp[mask] = ans;
		return ans;
	}
	
	// if it is possible to get all inside the mask with some x 
	ll get(ll x, ll y, ll mask) {
		// small optimisation
		if (x > y) {
			ll temp = x;
			x = y;
			y = temp;
		}

		if (sum(mask) != x*y) return 0; // cautionary check
		if (dp[x][mask] != -1) return dp[x][mask];

		// if there is exactly one, thats good!
		if (count(mask) == 1) return 1; 

		for (ll sub = mask; sub; sub = (sub - 1) & mask) {
			if (sub == mask) continue; // ignore case of full

			ll othersub = mask ^ sub;
			if (othersub > sub) break;

			if (sum(sub) % x == 0) {
				ll yy = sum(sub) / x;
				if (get(x,yy,sub) && get(x,y-yy,othersub)) {
					dp[x][mask] = 1;
					return 1;
				}
			}

			if (sum(sub) % y == 0) {
				ll xx = sum(sub) / y;
				if (get(xx,y,sub) && get(x-xx,y,othersub)) {
					dp[x][mask] = 1;
					return 1;
				}
			}
		}

		dp[x][mask] = 0;
		return 0;
	}	

	ll test = 1;
	void main() {
		while (cin >> k, k != 0) {
			A.clear();
			sumdp.clear();
			countdp.clear();
			dp.clear();

			ll n, m;
			cin >> n >> m;

			A.resize(k);
			sumdp.resize(1LL << k, -1);
			countdp.resize(1LL << k, -1);
			dp.resize(105, VLL(1LL << k, -1));

			REP(i,0,k) {
				cin >> A[i];
			}

			ll ans = get(n, m, (1LL << k) - 1);

			if (ans) printf("Case %lld: Yes\n", test++);
			else printf("Case %lld: No\n", test++);
			
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
