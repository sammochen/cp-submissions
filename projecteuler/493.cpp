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
	map<VLL,map<ll,double>> memo;
	map<VLL,map<ll,ll>> done;

	double get(VLL f, ll turn) {
		if (turn == 0) {
			double ans = 0;
			REP(i,1,f.size()) {
				ans += f[i];
			}
			return ans;
		}

		if (done[f][turn]) {
			return memo[f][turn];
		}


		double total = 0;
		REP(i,1,f.size()) {
			total += f[i] * i;
		}

		double ans = 0;
		REP(i,1,f.size()) {
			if (f[i]) {
				VLL next = f;
				next[i]--;
				next[i-1]++;
				ans += (double)(f[i] * i) / total * get(next, turn-1);
			}
		}

		done[f][turn] = 1;
		memo[f][turn] = ans;

		return ans;
	}

	
	void main() {
		// A very roundabout way of doing this - choosing 50 balls
		ll colours = 7, amount = 10, turns = 20;
		
		VLL f(amount+1);
		f[amount] = colours;
		double ans = get(f, colours * amount - turns);
		cout << setprecision(20) << ans << endl;
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
