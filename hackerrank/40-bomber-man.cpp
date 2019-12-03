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

namespace SOLVE {	
	void print_ans(VVLL A) {
		vector<string> ans(A.size());
		REP(i,0,A.size()) {
			ans[i] = "";
			REP(j,0,A[0].size()) {
				ans[i] += A[i][j] == 0 ? '.' : 'O';
			}
		}
		REP(i,0,A.size()) cout << ans[i] << endl;
	}

	void main() {
		ll n, m, k;
		cin >> n >> m >> k;
		VVLL A(n, VLL(m));
		REP(i,0,n) {
			string s;
			cin >> s;
			REP(j,0,m) {
				if (s[j] == 'O') A[i][j] = 3;
				else A[i][j] = 0;
			}
		}

		if (k == 1) {
			print_ans(A);
			return;
		}

		VLL di = {0,0,1,-1};
		VLL dj = {1,-1,0,0};

		VVVLL memo(4);

		REP(kk,1,8) { // cycle emerges after ~8 iterations - not sure how many exactly but allgood
			if (kk % 2 == 1) { // observe
				VVLL flag(n, VLL(m));
				REP(i,0,n) {
					REP(j,0,m) {
						if (A[i][j] > 0) {
							if (A[i][j] == 1) {
								flag[i][j] = 1;
							}
							A[i][j]--;
						}
					}
				}

				REP(i,0,n) {
					REP(j,0,m) {
						if (flag[i][j]) {
							REP(x,0,4) {
								ll ii = i + di[x], jj = j + dj[x];
								if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
								A[ii][jj] = 0;
							}
						}
					}
				}
			} else { 
				REP(i,0,n) {
					REP(j,0,m) {
						if (A[i][j] == 0) A[i][j] = 3;
						else A[i][j]--;
					}
				}
			}
			memo[kk%4] = A;
		}

		print_ans(memo[k%4]);
		
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
