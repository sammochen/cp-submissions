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
	scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	scanf("%lld", &x);
}

namespace SOLVE {	
	ll n;
	vector<vector<db>> A;
	map<VLL, pair<db,VLL>> dp;
	map<VLL, ll> done;
	
	pair<db, VLL> get(ll at, ll to, ll length) {
		if (length == 0) {
			if (at == to) return {1.0, {at}};
			else return {0.0, {}};
		}

		if (done[{at,to,length}]) return dp[{at,to,length}];


		db bestrate = 0;
		ll bestind;
		VLL bestseq;
		REP(i,0,n) {
			pair<db, VLL> ans = get(i,to,length-1);
			if (A[at][i] * ans.first > bestrate) {
				bestrate = A[at][i] * ans.first;
				bestind = i;
				bestseq = ans.second;
			}
		}

		bestseq.push_back(at);
		dp[{at,to,length}] = {bestrate, bestseq};
		done[{at,to,length}] = 1;
		return {bestrate, bestseq};
	}

	void main() {
		while (cin >> n) {
			A.clear();
			A.resize(n, vector<db>(n));

			done.clear();

			REP(i,0,n) {
				REP(j,0,n) {
					if (i == j) A[i][j] = 1;
					else {
						cin >> A[i][j];
					}
				}
			}
		
			ll ok = 0;

			REP(i,1,n+2) {
				REP(start,0,n) {
					pair<db, VLL> ans = get(start,start,i);
					if (ans.first > 1.01) {
						ok = 1;
						RREP(x, ans.second.size() - 1, 0) {
							cout << ans.second[x] + 1;
							if (x == 0) cout << endl;
							else cout << ' ';
						}
					}
					if (ok) break;
				}
				if (ok) break;
			}
			if (!ok) {
				cout << "no arbitrage sequence exists" << endl;
			}
		}


	}
}


signed main() {
	ll t;
	t = 1;
	// in(t);
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
