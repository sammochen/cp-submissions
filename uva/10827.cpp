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
	void main() {
		ll n;
		cin >> n;
		VVLL A(2*n, VLL(2*n));
		
		// 2D kadane
		REP(i,0,n) REP(j,0,n) {
			cin >> A[i][j];
			A[i+n][j] = A[i][j];
			A[i][j+n] = A[i][j];
			A[i+n][j+n] = A[i][j];
		}

		ll ans = -inf;

		// Currently a O(n^4) solution
		REP(i,0,n) {
			VLL temprow(2*n);
			REP(j,i,i+n) {
				// update row - this is the sum from i to j, inclusive
				REP(k,0,2*n) {
					temprow[k] += A[j][k];
				}
				
				// do 1D kadane, but with a n size limit (O(n^2))

				REP(start,0,n) {
					ll cur = -inf;
					REP(end,start,start+n) {
						cur = max(temprow[end], temprow[end] + cur);
						ans = max(ans, cur);
					}
				}
			}
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