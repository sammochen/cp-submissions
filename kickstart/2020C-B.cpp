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

ll test = 1;
void solve() {
	ll n, m;
	cin >> n >> m;
	VS A(n);
	rep(i,0,n) cin >> A[i];

	VLL used(26);
	rep(i,0,n) rep(j,0,m) used[A[i][j] - 'A'] = 1;

	ll cnt = 0;
	rep(i,0,sz(used)) cnt += used[i];

	vector<SLL> E(26);
	rrep(i,n-2,0) {
		rep(j,0,m) {
			if (A[i][j] == A[i+1][j]) continue;
			E[A[i+1][j] - 'A'].insert(A[i][j] - 'A');
		}
	}

	VLL indeg(26);
	rep(i,0,26) {
		fe(e, E[i]) {
			indeg[e]++;
		}
	}

	queue<ll> q;
	rep(i,0,26) {
		if (used[i] && indeg[i] == 0) {
			q.push(i);
		}
	}

	string ans;
	while (q.size()) {
		ll at = q.front(); q.pop();
		ans.pb(at + 'A');
		fe(e, E[at]) {
			indeg[e]--;
			if (indeg[e] == 0) {
				q.push(e);
			}
		}
	}

	if (cnt != lg(ans)) ans = "-1";

	printf("Case #%lld: %s\n", test++, ans.c_str());
}

signed main() {
	ll t = 1;
	cin >> t;
	rep(i,0,t) solve();
	return 0;
}