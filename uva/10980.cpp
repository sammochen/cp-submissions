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

const ll inf = 1e9+7;

namespace SOLVE {	

	vector<double> read() {
		vector<double> A;
		string s;
		getline(cin, s);
		s.erase(remove(s.begin(), s.end(), '.'), s.end());
		stringstream ss;
		ss << s;
		ll x;
		while (ss >> x) A.push_back(x);
		if (A.size() == 0) exit(0);
		return A;
	}

	void main() {
		ll t = 1;
		while (1) {
			vector<double> A;
			A = read();
			ll unit = A[0];
			ll M = A[1];
			vector<PLL> deals(M);
			REP(i,0,M) {
				A = read();
				deals[i].first = A[0];
				deals[i].second = A[1];
			}

			deals.push_back({1,unit});

			ll nax = 205;
			VLL dp(nax, inf);
			dp[0] = 0;
			REP(i,0,nax) {
				for (PLL deal : deals) {
					if (i+deal.first < nax) dp[i+deal.first] = min(dp[i+deal.first], dp[i] + deal.second);
				}
			}

			RREP(i,nax-2,0) {
				dp[i] = min(dp[i], dp[i+1]);
			}

			printf("Case %lld:\n", t);
			t++;

			A = read();
			REP(i,0,A.size()) {
				ll x = A[i];
				printf("Buy %lld for $%.2f\n", x, dp[x] / 100.0);
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
