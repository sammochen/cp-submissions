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

const ll inf = (ll)1e18+5;

namespace SOLVE {	
	VLL operator+(const VLL & A, const VLL & B) {
		VLL C(A.size());
		REP(i,0,A.size()) C[i] = A[i] + B[i];
		return C;
	}

	VLL operator-(const VLL & A, const VLL & B) {
		VLL C(A.size());
		REP(i,0,A.size()) C[i] = A[i] - B[i];
		return C;
	}


	void main() {
		ll a, b, c;
		cin >> a >> b >> c;
		VVVLL A(a, VVLL(b, VLL(c)));

		REP(i,0,a) {
			REP(j,0,b) {
				REP(k,0,c) {
					cin >> A[i][j][k];
				}
			}
		}

		ll ans = -inf;


		// 3d kadane (i think) - i will try squish the cuboid into 1 dimension
		// O(a * b * a * b * c) = O(n ^ 5)
		
		// first, preprocess some prefix sums
		VVVLL pre(a+1, VVLL(b+1, VLL(c+1))); // dp[i][j] gives the sum of all 'c's 
		REP(i,1,a+1) {
			REP(j,1,b+1) {
				pre[i][j] = A[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
			}
		}

		REP(starti,1,a+1) { 
			REP(startj,1,b+1) {
				// starting with starti, startj, i will draw a rectangle
				REP(endi, starti, a+1) {
					REP(endj, startj, b+1) {
						VLL temp = pre[endi][endj] - pre[starti-1][endj] - pre[endi][startj - 1] + pre[starti-1][startj-1];

						// now do kadanes with temp
						ll cur = -inf;
						REP(k,0,c) {
							cur = max(temp[k] + cur, temp[k]);
							ans = max(ans, cur);
						}
					}
				}
			}
		}

		cout << ans << endl;
	}
}


signed main() {
	int t;
	// t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
		if (t != 0) cout << endl;
	}

	return 0;
}
