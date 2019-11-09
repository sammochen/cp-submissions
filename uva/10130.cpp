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

namespace SOLVE {	
	void main() {
		ll n;
		cin >> n;
		vector<PLL> items(n);
		REP(i,0,n) {
			cin >> items[i].first; // price
			cin >> items[i].second; // weight
		}

		ll m;
		cin >> m;
		VLL people(m);
		REP(i,0,m) cin >> people[i];

		ll nax = 30001; // max weight
		VLL dp(nax); // dp[i] gives max value for some weight
		REP(i,0,n) {
			RREP(j,nax-1,0) {
				if (j + items[i].second < nax) dp[j + items[i].second] = max(dp[j + items[i].second], dp[j] + items[i].first);
			}
		}
		ll ans = 0;
		REP(i,0,m) {
			ans += dp[people[i]];
		}
		cout << ans << endl;
	}
}


signed main() {
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
