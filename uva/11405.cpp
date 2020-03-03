#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
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
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

void solve() {
	ll n;
	cin >> n;
	vector<string> A(8);
	REP(i,0,8) cin >> A[i];

	ll king = -1, knight = -1, pawns = 0;
	REP(i,0,8) {
		REP(j,0,8) {
			if (A[i][j] == 'P') pawns++;
			if (A[i][j] == 'K') king = i*8+j;
			if (A[i][j] == 'k') knight = i*8+j;
		}
	} 


	// do a bfs, limited at n steps
	// there are up to 2^8 * 64 * 64 states
	ll good = 0;
	queue<pair<vector<string>,VLL>> Q; // {grid, {enemy pawns, king pos, knight pos}}
	map<vector<string>,ll> time; 
	Q.push({A,{pawns,king,knight}});
	time[A] = 1;
	while (Q.size()) {
		// try move the king and knight
		pair<vector<string>, VLL> at = Q.front(); Q.pop();
		vector<string> grid = at.first;
		ll pawns = at.second[0];
		ll kingi = at.second[1] / 8, kingj = at.second[1] % 8;
		ll knighti = at.second[2] / 8, knightj = at.second[2] % 8;
		//if (time[grid] > n) continue;
		if (pawns == 0) {
			good = 1;
			break;
		}

		if (time[grid] == n+1) continue;
			
		VLL di = {1,2,2,1,-1,-2,-2,-1};
		VLL dj = {2,1,-1,-2,-2,-1,1,2};

		REP(x,0,8) {
			ll ii = knighti + di[x];
			ll jj = knightj + dj[x];
			if (ii < 0 || ii >= 8 || jj < 0 || jj >= 8) continue;
			if (grid[ii][jj] == 'p') continue;
			if (grid[ii][jj] == 'K') continue;
			ll ate = 0;
			if (grid[ii][jj] == 'P') ate = 1;

			vector<string> nextgrid = grid;
			nextgrid[knighti][knightj] = '.';
			nextgrid[ii][jj] = 'k';

			pair<vector<string>, VLL> to = {nextgrid, {pawns - ate, kingi*8+kingj, ii*8+jj}};

			if (time[nextgrid] == 0) {
				time[nextgrid] = time[grid] + 1;
				Q.push(to);
			}
		}		
	}

	if (good) cout << "Yes" << endl;
	else cout << "No" << endl;



}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}