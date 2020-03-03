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
	vector<vector<vector<db>>> memo;

	// returns probability of turn winning
	// turn = 0 is princess, turn = 1 is dragon
	db get(ll w, ll b, ll turn) { 
		if (w <= 0) return turn; // dragon wins if empty
		if (b == 0) return 1; // winner will always take a white
		if (b < 0) return 0; // not sure what will happen here
		if (memo[w][b][turn] != -1) return memo[w][b][turn];

		//debug(w,b,turn);

		// white probability
		db wp = ((db)w) / (w+b);
		db ans;

		if (turn == 0) { // princess
			// p(white) + p(not white) * (we win after)
			ans = wp + (1.0 - wp) * (1.0 - get(w, b-1, 1-turn));
		} else { // dragon
			double we = ((db)w) / (w+b-1); // chance white escapes, AFTER black already leaves

			// p(white) + p(not white) * ( p(another white escapes) * p(we win) + p(another black escapes) * p(we win) )
			ans = wp + (1.0 - wp) * ((we) * (1.0 - get(w-1,b-1,1-turn)) + (1.0 - we) * (1.0 - get(w,b-2,1-turn)));
		}

		memo[w][b][turn] = ans;
		return ans;
	}

	void main() {
		ll w, b;
		cin >> w >> b;
		memo.resize(w+1, vector<vector<db>>(b+1, vector<db>(2, -1)));

		db ans = get(w,b,0);
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
