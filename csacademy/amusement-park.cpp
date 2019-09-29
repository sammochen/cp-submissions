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
template <typename A, typename B> string to_string(pair<A,B> v) {
	return "(" + to_string(v.first) + ", " + to_string(v.second) + ")";
}

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
typedef pair<db,db> PDB;

namespace SOLVE {	
	PDB operator+(PDB a, PDB b) {
		return {a.first + b.first, a.second + b.second};
	}

	PDB operator*(db a, PDB b) {
		return {a * b.first, a * b.second};
	}

	void main() {

		ll T, A;
		cin >> T >> A;

		vector<vector<db>> p(T, vector<db>(A));
		vector<vector<db>> ans(T, vector<db>(A));

		REP(i,0,T) REP(j,0,A) {
			cin >> p[i][j];
			p[i][j] /= 100;
		}


		REP(t,0,T) { // every token
			// first find ans[t][0] 
			PDB x = {0, 1};
			// i then need to iterate over all A and work it out forward until i get 0 again
			RREP(a, A-1, 0) {
				x = MP(1 + (t == 0 ? 0 : ans[t-1][(a+1)%A] * (1 - p[t][a])), 0) + p[t][a] * x;
				debug(t,a,x);
			}

			// found ans[t][0] : now need to find all other ans[t][a]
			ans[t][0] = x.first / (1 - x.second);

			RREP(a, A-1, 1) {
				ans[t][a] = 1 + (t == 0 ? 0 : ans[t-1][(a+1)%A] * (1 - p[t][a])) + p[t][a] * ans[t][(a+1)%A];
			}
		}
		printf("%.20lf\n", ans[T-1][0]);
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
