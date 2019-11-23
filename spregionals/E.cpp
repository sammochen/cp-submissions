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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll n, m;
	VVLL A;
	map<pair<ll,string>, ll> dp;
	map<pair<ll,string>, ll> done;

	ll isempty(string mask) {
		for (char c : mask) {
			if (c != ' ') {
				return 0;
			}
		}
		return 1;
	}

	ll get(ll ind, string mask, ll diff) {
		if (ind == n * m && isempty(mask)) return 0; // at the end, there must be no brackets
		if (ind == n * m) return -inf; 
		if (ind % m == 0 && diff != 0) return -inf; // on a new row, brackets must be the same
		if (diff < 0) return -inf;

		if (done[{ind, mask}]) return dp[{ind,mask}];
	
		ll x = ind / m;
		ll y = ind % m;

		ll ans = -inf;

		// cannot happen 
		if (A[x][y] && mask[y] != ' ') return -inf;

		// 3 transitions:
		// 1. do nothing: "continuing the rectangle/continuing the empty"
		ans = max(ans, get(ind+1, mask, diff));

		if (!A[x][y]) {
			// 2. if i am at an open bracket and i want to remove it, i must also close the respective bracket
			if (mask[y] == '(') {
				REP(yy,y,m) {
					// while looking for the ')', everything else must be empty
					if (A[x][yy]) break;
					if (mask[yy] == ')') {
						string newmask = mask;
						newmask[y] = ' ';
						newmask[yy] = ' ';
						ans = max(ans, get(x*m+yy+1, newmask, diff) + 1);
						break;
					}
				}
			}
			// 3. i can put in open OR closed
			if (mask[y] == ' ') {
				string openmask = mask;
				openmask[y] = '(';
				ans = max(ans, get(ind+1, openmask, diff + 1));

				// can only put in closed if there is an open!! (that is not blocked!)
				ll ok = 0;
				ll d = 1; // amount of )
				RREP(yy,y,0) {
					if (A[x][yy]) break;
					if (mask[yy] == ')') d++;
					else if (mask[yy] == '(') d--;
					if (d == 0) {
						ok = 1;
						break;
					}
				}
				if (ok) {
					string closemask = mask;
					closemask[y] = ')';
					ans = max(ans, get(ind+1, closemask, diff - 1));
				}
			}
		} 

		dp[{ind,mask}] = ans;
		done[{ind,mask}] = 1;
		return ans;
	}

	VVLL ansA;
	ll id;
	void build(ll ind, string mask, ll diff) {
		if (ind == n * m) return; 

		ll x = ind / m;
		ll y = ind % m;

		VLL ans(4);
		vector<string> nextmask(4);
		VLL nextdiff(4);
		VLL nextind(4);
		// 4 transitions:
		// 1. do nothing: "continuing the rectangle/continuing the empty"
		ans[0] = get(ind+1, mask, diff);
		nextmask[0] = mask;
		nextdiff[0] = diff;
		nextind[0] = ind+1;

		if (!A[x][y]) {
			// 2. if i am at an open bracket and i want to remove it, i must also close the respective bracket
			if (mask[y] == '(') {
				REP(yy,y,m) {
					// while looking for the ')', everything else must be empty
					if (A[x][yy]) break;
					if (mask[yy] == ')') {
						string newmask = mask;
						newmask[y] = ' ';
						newmask[yy] = ' ';
						ans[1] = get(x*m+yy+1, newmask, diff) + 1;
						nextmask[1] = newmask;
						nextdiff[1] = diff;
						nextind[1] = x*m+yy+1;
						break;
					}
				}
			}
			// 3. i can put in open OR closed
			if (mask[y] == ' ') {
				string openmask = mask;
				openmask[y] = '(';
				ans[2] = get(ind+1, openmask, diff + 1);
				nextmask[2] = openmask;
				nextdiff[2] = diff + 1;
				nextind[2] = ind+1;

				// can only put in closed if there is an open!! (that is not blocked!)
				ll ok = 0;
				ll d = 1; // amount of )
				RREP(yy,y,0) {
					if (A[x][yy]) break;
					if (mask[yy] == ')') d++;
					else if (mask[yy] == '(') d--;
					if (d == 0) {
						ok = 1;
						break;
					}
				}
				if (ok) {
					string closemask = mask;
					closemask[y] = ')';
					ans[3] = get(ind+1, closemask, diff - 1);
					nextmask[3] = closemask;
					nextdiff[3] = diff - 1;
					nextind[3] = ind+1;
				}
			}
		}
		
		ll besti;
		ll bestans = -inf;
		REP(i,0,4) {
			if (ans[i] > bestans) {
				bestans = ans[i];
				besti = i;
			}
		}
	
		if (besti == 0) {
			// do nothing
			if (A[x][y]) {
				ansA[x][y] = -1;
			} else if (mask[y] == '(' || mask[y] == ')') {
				ansA[x][y] = ansA[x-1][y];
			} else {
				ansA[x][y] = 0;
			}
		} else if (besti == 1) {
			// close
			REP(yy, y, m) {
				ansA[x][yy] = ansA[x-1][y];
				if (mask[yy] == ')') break;
			}
		} else if (besti == 2) {
			// new open 
		} else if (besti == 3) {
			// new close
			RREP(yy,y,0) {
				ansA[x][yy] = id;
				if (mask[yy] == '(') break;
			}
			id++;
			
		}
		build(nextind[besti], nextmask[besti], nextdiff[besti]);
	}


	void main() {
		cin >> n >> m;
		A.resize(n, VLL(m));
		ansA.resize(n, VLL(m));
		id = 1;

		REP(i,0,n) {
			string s;
			cin >> s;
			REP(j,0,m) {
				A[i][j] = s[j] == '.' ? 0 : 1;
			}
		}

		string emptymask = "";
		REP(i,0,m) emptymask += " ";
		ll ans = get(0,emptymask,0);
		cout << ans << endl;
		build(0, emptymask, 0);
		REP(i,0,n) {
			REP(j,0,m) {
				cout << ansA[i][j] << ' ';
			} 
			cout << endl;
		}
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
