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
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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

const ll inf = 1e9+7;
const ll nax = 305;
const ll inv = 1e9+7;
const ll nothing = -1;

namespace SOLVE {	
	VVLL dp(nax, VLL(nax, nothing));
	vector<PLL> coins;

	ll get(ll a, ll b, ll ind) {
		if (a == 0 && b == 0 && ind == -1) return 0;
		if (a < 0 || b < 0 || ind < 0) return inv;
		if (dp[a][b] != nothing) return dp[a][b];
		
		
		ll ans = inf;
		ans = min(get(a,b,ind-1), get(a-coins[ind].first, b-coins[ind].second, ind) + 1);

		dp[a][b] = ans;
		return ans;
	}

	ll sq(ll x) {
		if (x < 0) return -1;
		ll s = sqrt(x);
		return s * s == x ? s : -1;
	}

	void main() {
		ll n, k;
		cin >> n >> k;

		coins.clear();
		coins.resize(n);
		dp.clear();
		dp.resize(nax, VLL(nax, nothing));
		
		REP(i,0,n) {
			ll a, b;
			cin >> a >> b;
			coins[i] = {a,b};
		}

		ll ans = inv;

		REP(i,0,k+1) {
			REP(j,0,k+1) {
				if (i*i + j*j == k*k) {
					ans = min(ans, get(i,j,n-1));
				}
			}
		}
		if (ans == inv) cout << "not possible" << endl;
		else cout <<  ans << endl;
	}
}


signed main() {
	int t;
	// t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
