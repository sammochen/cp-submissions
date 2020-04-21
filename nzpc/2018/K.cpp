#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

void in() {}
template <typename A> void in(A & x) { cin >> x; }
template <typename A, typename B> void in(pair<A,B> & x) { in(x.first); in(x.second); }
template <typename A> void in(vector<A> & x) { REP(i,0,(ll)x.size()) in(x[i]); }
template <typename Head, typename... Tail> void in(Head & H, Tail & ... T) {in(H); in(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;

struct strip {
	ll l, r, w;
};

string to_string(strip s) {
	VLL A = {s.l, s.r, s.w};
	return to_string(A);
}

vector<strip> foldleft(vector<strip> width, ll fold) {
	vector<strip> folded;
	for (strip s : width) {
		if (s.l < fold && s.r > fold) {
			folded.push_back({0, fold - s.l, s.w});
			folded.push_back({0, s.r - fold, s.w});
		} else if (s.l < fold) {
			folded.push_back({fold - s.r, fold - s.l, s.w});
		} else {
			folded.push_back({s.l - fold, s.r - fold, s.w});
		}
	}
	return folded;
}

vector<strip> flip(vector<strip> width, ll big) {
	vector<strip> folded;
	for (strip s : width) {
		folded.push_back({big-s.r, big-s.l, s.w});
	}
	return folded;
}
vector<strip> foldright(vector<strip> width, ll fold, ll big) {
	return flip(foldleft(flip(width, big), fold), big);
}

void solve() {
	ll w, h, f, p;
	while (cin >> w >> h >> f >> p, w||h||f||p) {
		vector<strip> width = {{0,w,1}};
		vector<strip> height = {{0,h,1}};

		REP(i,0,f) {
			string s;
			in(s);
			char c = s[0];
			ll d = stoll(s.substr(1));
			if (c == 'L') {
				width = foldleft(width, d);
				w = max(w-d,d);
			} else if (c == 'R') {
				width = flip(width, w);
				width = foldleft(width, d);
				
				w = max(w-d,d);
				width = flip(width, w);
			} else if (c == 'T') {
				height = foldleft(height, d);
				h = max(h-d,d);
			} else if (c == 'B') {
				height = flip(height, h);
				height = foldleft(height, d);
				
				h = max(h-d,d);
				height = flip(height, h);
			} else {
				assert(0);
			}
		}
		//debug(width, height);

		REP(i,0,p) {
			ll a, b;
			in(a,b);

			ll W = b-1;
			ll H = a-1;

			ll wm = 0;
			ll hm = 0;
			for (strip s : width) {
				if (s.l <= W && W < s.r) wm += s.w;
			}
			for (strip s : height) {
				if (s.l <= H && H < s.r) hm += s.w;
			}
			
			cout << wm * hm << endl;
		}
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}