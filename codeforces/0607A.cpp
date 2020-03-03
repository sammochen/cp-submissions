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

namespace SOLVE {	
	vector<PLL> A;

	ll bs(ll num) { // returns the position strictly less than 
		ll L = 0, R = A.size() - 1;
		
		while (L < R) {
			ll M = (L+R)/2;
			if (A[M].first < num) {
				L = M+1;
			} else {
				R = M;
			}
		}
		return L-1;
	}

	void main() {
		ll n;
		cin >> n;
		A.resize(n);

		REP(i,0,n) {
			ll a, b;
			cin >> a >> b;
			A[i] = {a,b};
		}

		sort(A.begin(), A.end());

		VLL dp(n); // how many beacons are destroyed if beacon[i] is to be detonated
		dp[0] = 0;
		REP(i,1,n) {
			ll next = bs(A[i].first - A[i].second);
			if (next == -1) dp[i] = i;
			else dp[i] = dp[next] + (i - next - 1);
		}

		ll ans = inf;
		REP(i,0,n) {
			ans = min(ans, n - 1 - i + dp[i]);
		}
		cout << ans << endl;


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
