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

template <typename A> string to_string(vector<A> v);
template <typename A, typename B> string to_string(pair<A,B> p);

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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
	vector<PLL> A;
	map<PLL, ll> done;
	map<PLL, pair<db,VLL>> memo;

	db dist(PLL a, PLL b) {
		db dx = a.first - b.first;
		db dy = a.second - b.second;
		return sqrt(dx*dx + dy*dy);
	}

	pair<db,VLL> get(ll start, ll mask) {
		if ((1LL << start) == mask) return {0, {start}};

		if (done[{start,mask}]) return memo[{start,mask}];
		
		db bestdist = 1e18;
		VLL bestorder;

		REP(bit,0,A.size()) {
			if (mask & (1LL << bit)) {
				pair<db,VLL> temp = get(bit, mask & ~(1LL << start));
				temp.first += dist(A[start], A[bit]) + 16;

				if (temp.first < bestdist) {
					bestdist = temp.first;
					bestorder = temp.second;
				}
			}
		}

		VLL finalorder(bestorder.size() + 1);
		REP(i,0,finalorder.size() - 1) {
			finalorder[i+1] = bestorder[i];
		}
		finalorder[0] = start;

		pair<db, VLL> ans = {bestdist, finalorder};
		done[{start,mask}] = 1;
		memo[{start,mask}] = ans;
		return ans;
	}

	pair<db, VLL> get() {
		pair<db, VLL> ans = {1e18, {0}};

		REP(start, 0, A.size()) {
			pair<db, VLL> temp = get(start, (1LL << A.size()) - 1);
			if (temp.first < ans.first) {
				ans = temp;
			}
		}

		return ans;
	}

	string bracket(PLL x) {
		return "(" + to_string(x.first) + "," + to_string(x.second) + ")";
	}

	void main(ll t) {
		ll n;
		cin >> n;
		if (n == 0) exit(0);

		A.resize(n);
		memo.clear();
		done.clear();

		REP(i,0,n) {
			cin >> A[i].first >> A[i].second;
		}
	
		pair<db, VLL> ans = get();
		db ansdist = ans.first;
		VLL ansorder = ans.second;

		printf("**********************************************************\n");
		printf("Network #%lld\n", t);
		REP(i,0,n-1) {
			PLL a = A[ansorder[i]], b = A[ansorder[i+1]];
			printf("Cable requirement to connect %s to %s is %.2lf feet.\n", bracket(a).c_str(), bracket(b).c_str(), dist(a, b) + 16);
		}
		printf("Number of feet of cable required is %.2lf.\n", ansdist);
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 0;
	// cin >> t;
	while (1) {
		SOLVE::main(++t);
	}

	return 0;
}
