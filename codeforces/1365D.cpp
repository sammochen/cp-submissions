#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL; 
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;
typedef map<ll,ll> MLL;
typedef set<ll> SLL;

#define rep(x,l,u) for(ll x = l; x < u; x++)
#define rrep(x,l,u) for(ll x = l; x >= u; x--)
#define fe(x,a) for (auto x : a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()
#define lg(x) (ll)x.length()
#define fi first
#define se second
#define pb push_back

#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define pqueue priority_queue

struct DEBUG {
	string open = "[", close = "]", sep = ", ";

	string f(string s) { return s; }
	string f(char c) { return string(1, c); }
	string f(int x) { return to_string(x); }
	string f(ll x) { return to_string(x); }
	template <typename A, typename B> string f(pair<A,B> p) { return open + f(p.first) + sep + f(p.second) + close; }
	template <typename A> string f(A v) { string s = open; for (auto a : v) { if (s != open) { s += sep; } s += f(a); } s += close; return s; } 

	void show() {cout << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cout << " " << f(H); show(T...); }
};

#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
template <typename A, typename B> ll exist(A a, B b) { return a.find(b) != a.end(); }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }

void upmin(ll & x, ll v) { x = min(x, v); }
void upmax(ll & x, ll v) { x = max(x, v); }

ll n, m;
ll cnt = 0;
VVLL vis;
VS A;

void dfs(ll i, ll j) {
	if (vis[i][j]) return;
	if (A[i][j] == '#') return;

	vis[i][j] = 1;
	if (A[i][j] == 'G') cnt++;
	
	rep(x,0,4) {
		ll ii = i + di[x];
		ll jj = j + dj[x];
		if (ob(ii, n) || ob(jj, m)) continue;

		dfs(ii, jj);
	}
}

void solve() {
	cin >> n >> m;
	A.resize(n);

	rep(i,0,n) cin >> A[i];
	vis.assign(n, VLL(m, 0));

	ll total = 0;
	rep(i,0,n) {
		rep(j,0,m) {
			total += A[i][j] == 'G';

			if (A[i][j] == 'B') {
				rep(x,0,4) {
					ll ii = i + di[x];
					ll jj = j + dj[x];
					if (ob(ii, n) || ob(jj, m)) continue;
					if (A[ii][jj] == 'G') {
						cout << "No" << endl;
						return;
					} 
					if (A[ii][jj] == '.') A[ii][jj] = '#';
				}
			}
		}
	}

	cnt = 0;
	dfs(n-1, m-1);
	if (total == cnt) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

signed main() {
	ll t = 1;
	cin >> t;
	rep(i,0,t) solve();
	return 0;
}