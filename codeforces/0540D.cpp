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

const ll nax = 100;

namespace SOLVE {	
	// incredibly long way of saying memo[a][b][c] -> vector<db>
	vector<vector<vector<vector<db>>>> memo(nax+1, vector<vector<vector<db>>>(nax+1, vector<vector<db>>(nax+1, vector<db>(3,-1))));

	vector<db> operator*(vector<db> a, db b) {
		REP(i,0,a.size()) {
			a[i] *= b;
		}
		return a;
	}

	vector<db> operator+(vector<db> a, vector<db> b) {
		REP(i,0,a.size()) {
			a[i] += b[i];
		}
		return a;
	}

	// return ans[i] for prob of who surviving
	vector<db> get(ll a, ll b, ll c) {
		if (a == 0 && b == 0) return {0,0,1};
		if (b == 0 && c == 0) return {1,0,0};
		if (c == 0 && a == 0) return {0,1,0};

		if (a == 0) return {0,1,0};
		if (b == 0) return {0,0,1};
		if (c == 0) return {1,0,0};

		if (memo[a][b][c][0] != -1) return memo[a][b][c];

		// what is the chance of choosing two, a, b, and what is the win rate now
		ll same = a * (a-1) + b * (b-1) + c * (c-1);
		ll total = a*b + b*c + c*a;
		
		vector<db> ans(3);

		ans = ans + get(a, b-1, c) * ((a*b) / (db)total);
		ans = ans + get(a, b, c-1) * ((b*c) / (db)total);
		ans = ans + get(a-1, b, c) * ((c*a) / (db)total);

		memo[a][b][c] = ans;
		return ans;
	}


	void main() {
		ll a, b, c;
		cin >> a >> b >> c;
		vector<db> ans = get(a,b,c);
		REP(i,0,3) {
			cout << setprecision(20) << ans[i] << ' ';
		}
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
