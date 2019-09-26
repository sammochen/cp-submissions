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
	map<ll,vector<double>> memo;
	map<ll,ll> done;
	
	vector<double> E(ll x) {
		if (done[x]) return memo[x];
		
		if (x == 1) return {1};
		
		vector<double> ans(x, x); // start with x
	
		vector<double> one = E(x/2); // one half
		vector<double> two = E(x - x/2); // the other half
		vector<double> pos1(x); // possibility 1
		vector<double> pos2(x); // possibility 2
		
		REP(i,0,x/2) {
			pos1[i] = one[i];
			pos2[i+(x-x/2)] = one[i];
		}
		REP(i,0,x-x/2) {
			pos1[i+x/2] = two[i];
			pos2[i] = two[i];
		}
		REP(i,0,x) {
			ans[i] += (pos1[i] + pos2[i]) / 2;
		}
			
		memo[x] = ans;
		done[x] = 1;
		return ans;	
	}
	
	void main() {
		ll n;
		cin >> n;
		vector<double> ans = E(n);
		for (double x : ans) printf("%.10lf ", x);
		cout << endl;
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
