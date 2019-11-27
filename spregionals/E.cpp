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

	// diff is no of ( - no of )
	// count is no of ( or )
	ll get(ll ind, string mask, ll diff, ll count) {
		if (ind == n * m && count == 0) return 0; // at the end, there must be no brackets
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
		ans = max(ans, get(ind+1, mask, diff, count));

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
						ans = max(ans, get(x*m+yy+1, newmask, diff, count - 2) + 1);
						break;
					}
				}
			}
			// 3. i can put in a open and a close!
			if (mask[y] == ' ') {
				REP(yy,y+1,m) {
					if (A[x][yy] || mask[yy] != ' ') break;
					string newmask = mask;
					newmask[y] = '(';
					newmask[yy] = ')';
					ans = max(ans, get(x*m+yy+1, newmask, diff, count + 2));
				}
			} 
		} 

		dp[{ind,mask}] = ans;
		done[{ind,mask}] = 1;
		return ans;
	}

	VVLL ansA;
	ll id;
	void build(ll ind, string mask, ll diff, ll count) {
		if (ind == n * m) return; 

		ll x = ind / m;
		ll y = ind % m;

		VLL ans(m+2);
		vector<string> nextmask(m+2);
		VLL nextdiff(m+2);
		VLL nextind(m+2);
		VLL nextcount(m+2);
		// 3 transitions:
		// 1. do nothing: "continuing the rectangle/continuing the empty"
		ans[0] = get(ind+1, mask, diff, count);
		nextmask[0] = mask;
		nextdiff[0] = diff;
		nextind[0] = ind+1;
		nextcount[0] = count;

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
						ans[1] = get(x*m+yy+1, newmask, diff, count - 2) + 1;
						nextmask[1] = newmask;
						nextdiff[1] = diff;
						nextind[1] = x*m+yy+1;
						nextcount[1] = count - 2;
						break;
					}
				}
			}
			// 3. i can put in a open and a close!
			if (mask[y] == ' ') {
				REP(yy,y+1,m) {
					if (A[x][yy] || mask[yy] != ' ') break;
					string newmask = mask;
					newmask[y] = '(';
					newmask[yy] = ')';
					ans[2+yy] = get(x*m+yy+1, newmask, diff, count + 2);
					nextmask[2+yy] = newmask;
					nextdiff[2+yy] = diff;
					nextind[2+yy] = x*m+yy+1;
					nextcount[2+yy] = count + 2;
				}
			} 
		}
		
		ll besti;
		ll bestans = -inf;
		REP(i,0,m+2) {
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
			// close existing
			REP(yy, y, m) {
				ansA[x][yy] = ansA[x-1][y];
				if (mask[yy] == ')') break;
			}
		} else {
			// open new one
			REP(yy,y,besti-1) {
				ansA[x][yy] = id;
			}
			id++;
			
		}
		build(nextind[besti], nextmask[besti], nextdiff[besti], nextcount[besti]);
	}


	void main() {
		scanf("%lld%lld", &n, &m);
		A.resize(n, VLL(m));
		ansA.resize(n, VLL(m, -2));
		id = 1;

		REP(i,0,n) {
			char buf[105];
			scanf("%104s", buf);
			string s = buf;
			REP(j,0,m) {
				A[i][j] = s[j] == '.' ? 0 : 1;
			}
		}

		string emptymask = "";
		REP(i,0,m) emptymask += " ";
		ll ans = get(0,emptymask,0,0);
		build(0, emptymask, 0, 0);

		printf("%lld\n", ans);
		REP(i,0,n) {
			REP(j,0,m) {
				printf("%lld ", ansA[i][j]);
			} 
			printf("\n");
		}
	}
}


signed main() {	
	int t;
	t = 1;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
