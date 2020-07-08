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
ll makemod(ll & x, ll m) { x %= m; x += m; x %= m; return x; }
ll powmod(ll a, ll b, ll m) {
	if (b == 0) return 1;
	ll h = powmod(a, b/2, m);
	ll ans = h*h%m;
	return b%2 ? ans*a%m : ans;
}

void upmin(ll & x, ll v) { x = min(x, v); }
void upmax(ll & x, ll v) { x = max(x, v); }

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const db eps = 1e-10;
const db pi = acos(0) * 2;
const string nl = "\n";

VLL A;
ll n;

ll h() {
	ll ans = 0;
	rep(i,1,n) {
		if (A[i] - A[i-1] != 1) ans++;
	}
	if (A[0] != 1) ans++;
	return ans;
}

ll sorted() {
	return h() == 0;
}

void addto(VLL & A, VLL & B, ll i, ll j) {
	rep(x,i,j+1) A.pb(B[x]);
}

ll dfs(ll dep, ll limit) {
	// h() is how many things are wrong with it. you can fix up to 3 things in one step.
	if (3 * dep + h() > 3 * limit) return 0;
	if (sorted()) return 1;

	rep(i,0,n) {
		rep(j,i,n) {
			// cut i->j, inclusive
			VLL B;
			addto(B, A, 0, i-1);
			addto(B, A, j+1, n-1);

			// paste i->j somewhere inside
			rep(k,0,sz(B) + 1) {
				VLL copy = A;
				A.clear();

				addto(A, B, 0, k-1);
				addto(A, copy, i, j);
				addto(A, B, k, sz(B)-1);

				if (dfs(dep+1, limit)) return 1;

				A = copy;
			}
		}
	}
	return 0;
}

ll ida() {
	rep(i,0,inf) {
		if (dfs(0, i)) return i;
	}
}

void solve() {
	ll test = 1;
	while (scanf(" %lld", &n), n) {
		A.clear();
		A.resize(n);
		fin(A);

		fout("Case ", test++, ": ", ida(), nl);

	}
}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}