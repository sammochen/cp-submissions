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

struct FASTINPUT {
	void f(string & s) { char buf[400005]; ll a = scanf("%s", buf); a++; s = buf; }
	void f(ll & x) { ll a = scanf("%lld", &x); a++; }
	void f(int & x) { ll a = scanf("%d", &x); a++; }
	void f(double & x) { ll a = scanf("%lf", &x); a++; }
	template <typename A, typename B> void f(pair<A,B> & p) { f(p.first); f(p.second); }
	template <typename A> void f(vector<A> & x) { for (auto & y : x) f(y); }
	
	void read() {}
	template <typename Head, typename... Tail> void read(Head & H, Tail & ... T) { f(H); read(T...); }
};

struct FASTOUTPUT {
	void f(string s) { printf("%s", s.c_str()); }
	void f(ll x) { printf("%lld", x); }
	void f(int x) { printf("%d", x); }
	void f(double x) { printf("%.20f", x); }
	void f(char x) { printf("%c", x); }
	void f(const char* a) { printf("%s", a); }
	template <typename A> void f(vector<A> & x) { for (auto & y : x) { f(y); f(" ");}  }


	void print() {}
	template <typename Head, typename... Tail> void print(Head H, Tail ... T) { f(H); print(T...); }
};

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

#define fin(...) do { FASTINPUT inp; inp.read(__VA_ARGS__); } while (false)
#define fout(...) do { FASTOUTPUT out; out.print(__VA_ARGS__); } while (false)
#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
template <typename A, typename B> ll exist(A a, B b) { return a.find(b) != a.end(); }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }
void makemod(ll & x, ll m) { x %= m; x += m; x %= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;	ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
bool isvowel(char ch) { return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'); }
ll sign(ll x) {	return x > 0 ? 1 : x < 0 ? -1 : 0; }

void upmin(ll & x, ll v) { x = min(x, v); }
void upmax(ll & x, ll v) { x = max(x, v); }

const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;
const string nl = "\n";

// careful = par is the edge index not the par vertex
ll dfs(ll at, ll par, ll cost, ll & sum, VLL & leaves, VVVLL & E) {
	ll l = 0;
	fe(to, E[at]) {
		if (to[2] == par) continue; // if the index matches
		l += dfs(to[0], to[2], cost + to[1], sum, leaves, E);
	}
	
	if (par == -1) return l;

	if (l == 0) {
		sum += cost;
		leaves[par] += 1;
		return 1;
	} else {
		leaves[par] += l;
		return l;
	}
}

void buildpre(ll ind, VLL & pre, VLL & leaves, VLL & A, VVVLL & E) {
	pre = {0};
	set<PLL> S; // {influence, ind}

	rep(at,0,sz(E)) {
		fe(to, E[at]) {
			ll i = to[2];
			if (to[3] == ind+1) {
				S.insert({(A[i] - A[i]/2) * leaves[i], i});
			}
		}
	}

	while (S.size()) {
		PLL top = *S.rbegin();
		S.erase(top);
		if (top.fi == 0) continue;
		
		pre.pb(pre.back() + top.fi);

		A[top.se] /= 2;

		S.insert({(A[top.se] - A[top.se]/2) * leaves[top.se], top.se});
	}
}

void solve() {
	ll n, k;
	fin(n, k);
	VVVLL E(n);
	VLL A(n-1);
	rep(i,0,n-1) {
		ll a, b, w, t;
		fin(a, b, w, t);
		a--; b--;
		E[a].pb({b,w,i,t});
		E[b].pb({a,w,i,t});
		A[i] = w;
	}

	ll sum = 0;
	VLL leaves(n-1);
	dfs(0, -1, 0, sum, leaves, E); 
	ll target = sum - k;
	
	VVLL pre(2);
	buildpre(0, pre[0], leaves, A, E);
	buildpre(1, pre[1], leaves, A, E);

	ll ans = inf;
	rep(i,0,pre[0].size()) {
		ll j = lower_bound(all(pre[1]), target - pre[0][i]) - pre[1].begin();
		if (j == sz(pre[1])) continue;
		upmin(ans, i + j*2);
	}

	fout(ans, nl);
}

signed main() {
	ll t = 1;
	fin(t);
	rep(i,0,t) solve();
	return 0;
}