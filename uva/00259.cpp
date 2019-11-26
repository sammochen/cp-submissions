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

const ll source = 36;
const ll sink = 37;
const ll nax = 38;
const ll inf = 1e9+7;

namespace SOLVE {
	void solve(VVLL adjmatrix, ll source, ll sink, ll target) {
		if (target == 0) return;
		
		ll totalflow = 0;
		while (1) {
			// bfs look for a flow
			VLL visited(nax, 0);
			VLL parent(nax, -1);

			queue<ll> Q;
			Q.push(source);
			visited[source] = 1;

			while (Q.size()) {
				ll at = Q.front();
				Q.pop();

				REP(to,0,38) {
					if (!visited[to] && adjmatrix[at][to] > 0) {
						Q.push(to);
						visited[to] = 1;
						parent[to] = at;
					}
				}
			}

			if (!visited[sink]) break;

			ll thisflow = inf;
			for (ll i = sink; i != source; i = parent[i]) {
				ll p = parent[i];
				thisflow = min(thisflow, adjmatrix[p][i]);
			}

			for (ll i = sink; i != source; i = parent[i]) {
				ll p = parent[i];
				adjmatrix[p][i] -= thisflow;
				adjmatrix[i][p] += thisflow;
			}

			totalflow += thisflow;
		}

		if (totalflow != target) {
			cout << '!' << endl;
		} else {
			REP(i,0,10) {
				ll ok = 0;
				for (char c = 'A'; c <= 'Z'; c++) {
					if (adjmatrix[i + 26][c - 'A'] > 0) {
						cout << c;
						ok = 1;
						break;
					}
				}
				if (!ok) cout << "_";
			}
			cout << endl;
		}


	}	

	void init(VVLL & adjmatrix, ll & target) {
		target = 0;
		REP(i,0,nax) {
			REP(j,0,nax) {
				adjmatrix[i][j] = 0;
			}
		}

		REP(i,0,10) {
			adjmatrix[i+26][sink] = 1; // number to sink is 1
		}
	}

	void main() {
		// 0-25 is letters, 26-35 is numbers
		ll target;
		VVLL adjmatrix(nax, VLL(nax)); // adjmatrix[i][j] gives the residual flow
		
		init(adjmatrix, target);
		
		string s;
		while (getline(cin, s)) {
			if (s == "" || s == " ") {
				solve(adjmatrix, source, sink, target);
				init(adjmatrix, target);
			} else {
				adjmatrix[source][s[0]-'A'] = s[1] - '0'; // source -> letter is number 
				target += s[1] - '0';

				REP(i,3,s.length() - 1) {
					if (s[i] >= '0' && s[i] <= '9') adjmatrix[s[0] - 'A'][s[i] - '0' + 26] = inf; // letter -> number is infinite
				}
			}
		}

		solve(adjmatrix, source, sink, target);
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
