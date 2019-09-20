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
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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
	// returns every non-zero splitting of VLL A
	vector<pair<VLL, VLL>> split(VLL A) {
		ll n = A.size();
		vector<pair<VLL, VLL>> ans;
		
		REP(i,1,1<<(n-1)) {
			VLL a, b;
			REP(j,0,n) {
				if (i & (1 << j)) {
					a.push_back(A[j]);
				} else {
					b.push_back(A[j]);
				}
			}
			
			ans.push_back(MP(a,b));
		}
		return ans;	
	}

	// dp[vector][ans] = string
	map<VLL, map<double, string>> M; // M[VLL][x] returns the string to make it if possible
	map<VLL, vector<double>> memo; // memo[VLL] returns the possible numbers 
	
	// returns all the numbers that can be made with VLL A
	// stores M[A][i] as a string 
	// uses memoisation
	vector<double> poss(VLL A) {
		if (memo[A].size() != 0) {
			return memo[A];
		}
		
		vector<double> ans;
		
		if (A.size() == 1) {
			M[A][A[0]] = to_string(A[0]);
			ans.push_back(A[0]);
			
			memo[A] = ans;
			return ans;
		}
		
		vector<pair<VLL,VLL>> splittings = split(A);
		
		for (pair<VLL, VLL> one : splittings) {
			VLL X = one.first;
			VLL Y = one.second;
			
			vector<double> Xposs = poss(X);
			vector<double> Yposs = poss(Y);		
			
			for (double x : Xposs) {
				for (double y : Yposs) {
					vector<double> next = {x+y, x-y, x*y, y-x};
					vector<string> sign = {"+", "-", "*", "-"};
					VLL wayround = {0,0,0,1};
					
					if (y != 0) {
						next.push_back(x/y);
						sign.push_back("/");
						wayround.push_back(0);
					}
					
					if (x != 0) {
						next.push_back(y/x);
						sign.push_back("/");
						wayround.push_back(1);
					}
					
					string b1 = A.size() == 2 ? "" : "(";
					string b2 = A.size() == 2 ? "" : ")";
					
					REP(j,0,next.size()) {
					
						string first = wayround[j] == 0 ? M[X][x] : M[Y][y];
						string second = wayround[j] == 0 ? M[Y][y] : M[X][x];
					
						M[A][next[j]] = b1 + first + b2 + " " + sign[j] + " " + b1 + second + b2;
						ans.push_back(next[j]);
					}	
				}
			}
		}
		
		memo[A] = ans;
		return ans;	
	}

	
	void main() {
		ll most = 0;
		string ans;
	
		REP(a,0,10) {
			REP(b,a+1,10) {
				REP(c,b+1,10) {
					REP(d,c+1,10) {
						VLL A = {a,b,c,d};
						poss(A);
						
						REP(x,1,1000000000) {
							string s = M[A][x];
							if (s == "") {
								if (x > most) {
									most = x;
									ans = to_string(a) + to_string(b) + to_string(c) + to_string(d);
								}
								break;
							}
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
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
