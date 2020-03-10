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

db norm(pair<db,db> a, pair<db,db> b) {
	return sqrt(pow(a.first-b.first,2)+ pow(a.second-b.second,2));
}

struct line {
	db x, y, c;
};
void mult(line & l, db k) {
	l.x *= k;
	l.y *= k;
	l.c *= k;
}
pair<db,db> intersect(line a, line b) {	
	if (a.x == 0) {
		db ansy = a.c / a.y;
		db ansx = (b.c - b.y*ansy) / b.x;
		return {ansx, ansy};
	}
	mult(b, -a.x/b.x);
	db ansy = (a.c + b.c) / (a.y + b.y);
	db ansx = (a.c - a.y * ansy) / a.x;
	return {ansx, ansy};
}

void solve() {
	ll n, test = 1;
	while (cin >> n, n) {
		vector<pair<db,db>> A(3);
		REP(i,0,3) {
			cin >> A[i].first >> A[i].second;
		}
		vector<line> lines(3);

		// for each pair of points, find the middle and the norming line
		REP(i,0,3) {
			db x = A[i].first - A[(i+1)%3].first;
			db y = A[i].second - A[(i+1)%3].second;
			db midx = (A[i].first + A[(i+1)%3].first)/2;
			db midy = (A[i].second + A[(i+1)%3].second)/2;
			lines[i] = {x, y, x*midx+y*midy};
		}

		pair<db,db> mid = intersect(lines[0], lines[1]);
		db r = norm(mid, A[0]);

		db angle = atan2(A[0].first - mid.first, A[0].second - mid.second);
		db maxx = -inf, minx = inf, maxy = -inf, miny = inf;
		REP(i,0,n) {
			angle += (4 * acos(0) / n);
			if (angle > 4*acos(0)) angle -= (4*acos(0));
			db x = mid.first + r*sin(angle);
			db y = mid.second + r*cos(angle);
			maxx = max(x, maxx);
			minx = min(x, minx);
			maxy = max(y, maxy);
			miny = min(y, miny);
		}		

		db ans = (maxx - minx) * (maxy - miny);
		printf("Polygon %lld: %.3f\n", test++, ans);
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}