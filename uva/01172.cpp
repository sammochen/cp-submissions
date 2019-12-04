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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	struct city {
		ll os, v;
	};

	void main() {
		ll n, m, x, c = 1;
		char a[20], b[20];
		map<string, ll> cityid;

		x = scanf("%lld", &n);
		vector<city> A(n);
		REP(i,0,n) {
			x = scanf("%15s %15s %lld", a, b, &A[i].v);
			string s = b;
			if (cityid[s] == 0) {
				cityid[s] = c++;
			}
			A[i].os = cityid[s];
		}
		x = scanf("%lld", &m);
		vector<city> B(m);
		REP(i,0,m) {
			x = scanf("%15s %15s %lld", a, b, &B[i].v);
			string s = b;
			if (cityid[s] == 0) {
				cityid[s] = c++;
			}
			B[i].os = cityid[s];
		}

		// lets hit it bottom up

		VVLL value(n+1, VLL(m+1));
		VVLL bridge(n+1, VLL(m+1));

		REP(i,1,n+1) {
			REP(j,1,m+1) {
				VLL di = {0,-1,-1};
				VLL dj = {-1,0,-1};
				VLL db = {0,0,1};
				VLL dv = {0,0,A[i-1].v + B[j-1].v};

				ll kk = (A[i-1].os == B[j-1].os) ? 3 : 2;
				REP(k,0,kk) {
					ll ii = i + di[k];
					ll jj = j + dj[k];
					ll vv = value[ii][jj] + dv[k];
					ll bb = bridge[ii][jj] + db[k];

					if (vv > value[i][j]) {
						value[i][j] = vv;
						bridge[i][j] = bb;
					} else if (vv == value[i][j]) {
						bridge[i][j] = min(bridge[i][j], bb);
					}
				}
				
			}
		}

		printf("%lld %lld\n", value[n][m], bridge[n][m]);
	}
}


signed main() {	
	ll t, x;
	t = 1;
	x = scanf("%lld", &t);
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
