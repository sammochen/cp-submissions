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
	ll bitcount(ll x) {
		ll ans = 0;
		REP(bit,0,60) {
			ans += (1LL << bit) & x ? 1 : 0;
		}
		return ans;
	}

	void main() {
		ll t, w;
		ll first = 1;
		while (cin >> t >> w) {
			if (!first) cout << endl;
			first = 0;
			
			ll n;
			cin >> n;

			vector<PLL> T(n);
			REP(i,0,n) {
				cin >> T[i].first;
				cin >> T[i].second;
			}

			VLL dp(t+1); // dp[i] is max treasures after t time
			VLL memo(t+1); // memo[i] keeps a bitset of added indices
			REP(i,0,n) {
				ll time = 3 * w * T[i].first;
				ll gold = T[i].second;
			
				RREP(j,t,0) {
					if (j + time <= t) {
						if (dp[j] + gold > dp[j + time]) {
							dp[j + time] = dp[j] + gold;
							memo[j + time] = memo[j] | (1LL << i);
						}
					}
				}
			}

			cout << dp[t] << endl;
			cout << bitcount(memo[t]) << endl;;
			REP(bit,0,n) {
				if ((1LL << bit) & memo[t]) {
					cout << T[bit].first << ' ' << T[bit].second << endl;
				}
			}

		}
	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
