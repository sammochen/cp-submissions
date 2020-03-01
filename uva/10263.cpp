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

struct line {
	db x, y, c;
};

line findline(db x1, db y1, db x2, db y2) {
	return {y2-y1, x1-x2, (y2-y1)*x1 + (x1-x2)*y1};
}

void mult(line & l, db k) {
	l.x *= k;
	l.y *= k;
	l.c *= k;
}

pair<db,db> closest(line l, db x, db y) {
	// if l is horizontal or vertical
	if (l.x == 0) return {x, l.c/l.y};
	if (l.y == 0) return {l.c/l.x, y};
	
	// find perpendicular line
	line perp = {l.y, -l.x, l.y * x - l.x * y};
	
	mult(perp, -l.x/perp.x);
	db ansy = (perp.c + l.c) / (perp.y + l.y);
	db ansx = (l.c - l.y * ansy) / l.x;
	
	return {ansx, ansy};
}

db dist(pair<db,db> a, pair<db,db> b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void solve() {
	db x, y;
	while (cin >> x >> y) {
		ll n;
		cin >> n;
		vector<pair<db,db>> A(n+1);
		REP(i,0,n+1) {
			cin >> A[i].first >> A[i].second;
		}

		db bestdist = inf;
		pair<db,db> ans;

		REP(i,0,n) {
			line l = findline(A[i].first, A[i].second, A[i+1].first, A[i+1].second);
			pair<db,db> intersect = closest(l, x, y);
			
			// if intersect is within the line, check it
			if (min(A[i].first, A[i+1].first) <= intersect.first && intersect.first <= max(A[i].first, A[i+1].first)) {
				if (min(A[i].second, A[i+1].second) <= intersect.second && intersect.second <= max(A[i].second, A[i+1].second)) {
					if (dist(intersect, {x,y}) < bestdist) {
						bestdist = dist(intersect, {x,y});
						ans = intersect;
					}
				}
			}

			// check the end points
			if (dist(A[i], {x,y}) < bestdist) {
				bestdist = dist(A[i], {x,y});
				ans = A[i];
			}
			if (dist(A[i+1], {x,y}) < bestdist) {
				bestdist = dist(A[i+1], {x,y});
				ans = A[i+1];
			}
		}

		if (abs(ans.first - 0) < 1e-6) ans.first = 0;
		if (abs(ans.second - 0) < 1e-6) ans.second = 0;
		printf("%.4f\n%.4f\n", ans.first, ans.second);
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}