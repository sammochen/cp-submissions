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



namespace SOLVE {	

	void main() {
		// because of negatives, i will add a +100 buffer
		const ll B = 100;

		vector<double> dp(B*2);
		dp[0+B] = 1;

		// 9 times, add 4-die
		REP(i,0,9) {
			vector<double> next(B*2);
			REP(j,B-50,B+50) {
				REP(k,1,5) {
					next[j+k] += dp[j] / 4;
				}
			}

			dp = next;
		}

		// 6 times, subtract 6-die
		REP(i,0,6) {
			vector<double> next(B*2);
			REP(j,B-50,B+50) {
				REP(k,1,7) {
					next[j-k] += dp[j] / 6;
				}
			}

			dp = next;
		}

		// ans is sum of all positive values
		double ans = 0; 
		REP(i,B+1,B*2) {
			ans += dp[i];
		}
		cout << setprecision(15) <<  ans << endl;

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
