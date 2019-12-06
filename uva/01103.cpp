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

void in(string & s) {
	cin >> s;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

namespace SOLVE {	
	string bin(char c) {
		map<char,string> m;
		m['0'] = "0000";
		m['1'] = "0001";
		m['2'] = "0010";
		m['3'] = "0011";
		m['4'] = "0100";
		m['5'] = "0101";
		m['6'] = "0110";
		m['7'] = "0111";
		m['8'] = "1000";
		m['9'] = "1001";
		m['a'] = "1010";
		m['b'] = "1011";
		m['c'] = "1100";
		m['d'] = "1101";
		m['e'] = "1110";
		m['f'] = "1111";

		return m[c];
	}

	// returns a set of all colours it has touched
	void dfs(ll i, ll j, ll id, vector<string> & A, VVLL & visited, vector<vector<set<ll>>> & S) {
		visited[i][j] = id;
		VLL dx = {0,0,1,-1};
		VLL dy = {1,-1,0,0};

		REP(x,0,4) {
			ll ii = i + dx[x];
			ll jj = j + dy[x];
			
			if (ii >= 0 && ii < A.size() && jj >= 0 && jj < A[0].length()) {
				if (A[ii][jj] == A[i][j] && !visited[ii][jj]) {
					dfs(ii,jj,id,A,visited, S);
					for (ll x : S[ii][jj]) {
						S[i][j].insert(x);
					}
				} else if (A[ii][jj] != A[i][j]) {
					S[i][j].insert(visited[ii][jj]); // sees how many colours it has
				}
			}
		}
	}

	ll test = 1;
	void main() {
		ll n, m;
		in(n,m);
		if (n == 0 && m == 0) exit(0);

		vector<string> A(n);
		REP(i,0,n) {
			in(A[i]);
		}

		// pad it with 0s on the outside
		vector<string> realA(n+2);
		REP(i,1,n+1) {
			realA[i] += "0";
			REP(j,0,m) {
				realA[i] += bin(A[i-1][j]);
			}
			realA[i] += "0";
		}
		REP(j,0,realA[1].size()) {
			realA[0] += "0";
			realA[n+1] += "0";
		}

		debug(realA.size(), realA[0].size());

		VVLL visited(realA.size(), VLL(realA[0].size()));
		vector<vector<set<ll>>> S(realA.size(), vector<set<ll>>(realA[0].size()));

		ll id = 1;
		// first, fill in all the 0s
		REP(i,0,realA.size()) {
			REP(j,0,realA[0].size()) {
				if (realA[i][j] == '0' && !visited[i][j]) {
					dfs(i,j,id++,realA,visited, S);
				}
			}
		}

		// next, all the 1s and count
		string H = "-WAKJSD";
		string ans = "";
		REP(i,0,realA.size()) {
			REP(j,0,realA[0].size()) {
				if (realA[i][j] == '1' && !visited[i][j]) {
					dfs(i,j,id++,realA,visited, S);
					ans.push_back(H[S[i][j].size()]);
				}
			}
		}

		sort(ans.begin(), ans.end());
		
		printf("Case %lld: %s\n", test++, ans.c_str());
	}
}


signed main() {
	while (1) {
		SOLVE::main();
	}

	return 0;
}
