#ifdef SAM
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL; 
typedef vector<VLL> VVLL;
typedef vector<VVLL> VVVLL;
typedef pair<ll,ll> PLL;
typedef map<ll,ll> MLL;
typedef set<ll> SLL;
typedef queue<ll> QLL;

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
	string f(db x) { return to_string(x); }
	string f(const char* a) { return a; }
	template <typename A, typename B> string f(pair<A,B> p) { return open + f(p.first) + sep + f(p.second) + close; }
	template <typename A> string f(A v) { string s = open; for (auto a : v) { if (s != open) { s += sep; } s += f(a); } s += close; return s; } 

	void show() {cout << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cout << " " << f(H); show(T...); }
};

#ifdef SAM
#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)
#else
#define debug(...) do {} while (false)
#endif

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};

void readstr(string & s, const ll len=400005) { char buf[len]; ll a = scanf("%s", buf); a++; s = buf; }
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }
void makemod(ll & x, ll m) { x %= m; x += m; x %= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;	ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
bool isvowel(char ch) { return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'); }
ll sign(ll x) {	return x > 0 ? 1 : x < 0 ? -1 : 0; }

template<typename A, typename B> void upmin(A & x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A & x, B v) { x = max(x, (A)v); }

const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;
const string nl = "\n";

void yes() {
	cout << "YES" << endl;
	exit(0);
}

void no() {
	cout << "NO" << endl;
	exit(0);
}

vector<uset<ll>> E;

ll dfs1(ll at, ll prev, ll target1, ll target2, ll & ans_at, ll & ans_prev, ll & which) {
	ll total = 1;
	fe(to, E[at]) {
		if (to == prev) continue;
		total += dfs1(to, at, target1, target2, ans_at, ans_prev, which);
	}
	if (total == target1 || total == target2) {
		ans_at = at;
		ans_prev = prev;
		if (total == target1) {
			which = 1;
		} else {
			which = 2;
		}
	}
	return total;
}

VLL fibs;
void check_tree(ll v, ll fibind) {
	if (fibs[fibind] == 1) return; // gone all the way to the end
	ll n = sz(E);

	ll ans_at = -1, ans_prev = -1, which = -1;
	dfs1(v, -1, fibs[fibind-1], fibs[fibind-2], ans_at, ans_prev, which);
	
	if (ans_at == -1) no();
	E[ans_at].erase(ans_prev);
	E[ans_prev].erase(ans_at);

	if (which == 1) {
		check_tree(ans_at, fibind-1);
		check_tree(ans_prev, fibind-2);
	} else {
		check_tree(ans_at, fibind-2);
		check_tree(ans_prev, fibind-1);
	}
}

void solve() {
	ll n;
	cin >> n;
	fibs = {1,1};
	while (fibs.back() < n) {
		ll fsize = fibs.size();
		fibs.push_back(fibs[fsize - 1] + fibs[fsize - 2]);
	}
	if (fibs.back() != n) no();

	E.resize(n);
	rep(i,0,n-1) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		E[a].insert(b);
		E[b].insert(a);
	}

	check_tree(0, fibs.size() - 1);
	yes();
}

signed main() {
	ll t = 1;
	// cin >> t;
	rep(i,0,t) solve();
	return 0;
}