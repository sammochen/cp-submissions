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
	char buf[100000]; // note the 100 limit
	ll a = scanf("%99999s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

namespace SOLVE {	
	ll main() {
		ll n, m, k;
		in(n,m,k);
		if (n == 0 && m == 0 && k == 0) return 0;

		vector<string> A(n);
		REP(i,0,n) {
			in(A[i]);
		}
		
		ll x, y, d; 
		//        E,S,W,N
		VLL dx = {0,1,0,-1};
		VLL dy = {1,0,-1,0};
		

		REP(i,0,n) {
			REP(j,0,m) {
				if (A[i][j] == 'L') {
					x = i, y = j, d = 0;
				} else if (A[i][j] == 'S') {
					x = i, y = j, d = 1;
				} else if (A[i][j] == 'O') {
					x = i, y = j, d = 2;
				} else if (A[i][j] == 'N') {
					x = i, y = j, d = 3;
				} 
			}
		}

		string cmd;
		in(cmd);
		ll ans = 0;

		for (char c : cmd) {
			if (c == 'D') {
				d = (d+1)%4;
			}
			if (c == 'E') {
				d = (d+3)%4;
			}
			if (c == 'F') {
				ll xx = x + dx[d];
				ll yy = y + dy[d];
				if (xx >= 0 && xx < n && yy >= 0 && yy < m && A[xx][yy] != '#') {
					if (A[xx][yy] == '*') {
						A[xx][yy] = '.';
						ans++;
					}
					x = xx;
					y = yy;
				}
			}
		}

		cout << ans << endl;
		return 1;
	}
}


signed main() {
	while(SOLVE::main()) {

	}

	return 0;
}
