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

struct point {
	ll x, y, z;
};
bool operator<(const point & a, const point & b) {
	return (pow(a.x, 2) + pow(a.y, 2)) < (pow(b.x, 2) + pow(b.y, 2));
}
string to_string(point a) {
	return "(" + to_string(a.x) + ", " + to_string(a.y) + ", " + to_string(a.z) + ")";
}

void solve() {
	ll n;
	ll test = 1;
	while (cin >> n, n) {
		vector<point> A(n);
		REP(i,0,n) {
			cin >> A[i].x >> A[i].y >> A[i].z;
			A[i].z++; // add one to not let anything be 0
		}
		sort(A.begin(), A.end());
		
		// point to height
		map<PLL,ll> height;
		vector<PLL> ans;
		REP(i,0,n) {
			ll g = abs(__gcd(A[i].x, A[i].y));
			PLL line = {A[i].x / g, A[i].y / g};
			if (height[line] >= A[i].z) ans.push_back({A[i].x, A[i].y});
			else height[line] = A[i].z;
		}
		sort(ans.begin(), ans.end());

		printf("Data set %lld:\n", test++);
		if (ans.size() == 0) {
			printf("All the lights are visible.\n");
		} else {
			printf("Some lights are not visible:\n");
			REP(i,0,ans.size()) {
				printf("x = %lld, y = %lld", ans[i].first, ans[i].second);
				if (i == ans.size() - 1) printf(".\n");
				else printf(";\n");
			}
		}
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}