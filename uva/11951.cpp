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
	PLL main() {
		ll n, m, k;
		cin >> n >> m >> k;
		VVLL A(n, VLL(m));
		
		
		// 2D kadane
		REP(i,0,n) REP(j,0,m) cin >> A[i][j];

		ll ansarea = -1; // area
		ll anscost = -1;
		
		REP(i,0,n) {
			VLL temprow(m);
			REP(j,i,n) {
				// update row - this is the sum from i to j, inclusive
				REP(k,0,m) {
					temprow[k] += A[j][k];
				}

				// 2-ptr approach to find max area that is less than price
				// inc L, not inc R
				ll L = 0, R = 0;
				ll price = 0;
				while (L != m) {
					if (price <= k) {
						ll area = (R - L) * (j - i + 1);
						if (area > ansarea) {
							ansarea = area;
							anscost = price;
						}
						if (area == ansarea) {
							anscost = min(anscost, price);
						}
					}	

					// Move R up
					if (price <= k && R != m) {
						price += temprow[R];
						R++;
					} else {
						price -= temprow[L];
						L++;
					}
				}
			}
		}

		return {ansarea, anscost};

	}
}


signed main() {
	int t;
	t = 1;
	cin >> t;
	REP(i,1,t+1) {
		PLL ans = SOLVE::main();
		cout << "Case #"  << i << ": " << ans.first << ' ' << ans.second << endl;
	}

	return 0;
}