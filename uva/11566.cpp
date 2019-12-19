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
typedef vector<VVLL> VVVLL;

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
template <typename A, typename B, typename C, typename D> void in(A & a, B & b, C & c, D & d) { in(a); in(b); in(c); in(d);}

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	
	// returns max value
	ll get(ll ind, ll money, ll amount, VVVLL & dp, VLL & cost, VLL & value) {
		if (amount < 0) return -inf;
		if (money < 0) return -inf;
		if (amount == 0) return 0;
		if (money == 0) return 0;
		if (ind < 0) return 0;
		if (dp[ind][money][amount] != -1) return dp[ind][money][amount];
		
		// take or dont!
		ll ans = 0;
		// dont
		ans = max(ans, get(ind - 1, money, amount, dp, cost, value));
		// take
		ans = max(ans, value[ind] + get(ind - 1, money - cost[ind], amount - 1, dp, cost, value));
		dp[ind][money][amount] = ans;
		return ans;
	}

	void main() {
		ll n, x, t, k;
		while (in(n,x,t,k), n || x || t || k) {
			n++; // stupid n

			// x is the total amount of money
			// divide x by 1.1, round down and then subtract tea money
			ll money = floor(((double)x * n / 1.1 + 1e-6) - t*n);

			VLL cost(2*k); // i can choose each dimsum max twice
			VLL value(2*k);

			REP(i,0,k) {
				in(cost[i]);
				ll a, b, c, d;
				REP(j,0,n) {
					ll x;
					in(x);
					value[i] += x;
				}

				cost[i+k] = cost[i];
				value[i+k] = value[i];
			}

			// get the best value with only 2*n!!
			// dp[money][index][amount] returns value
			// O(1000 * 100 * 10) - reasonable

			VVVLL dp(2*k, VVLL(money + 1, VLL(2*n + 1, -1)));

			ll ans = get(2*k - 1, money, 2*n, dp, cost, value);
			
			double d = ans / (double)n;
			printf("%.2f\n", d);
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
