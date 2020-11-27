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

ll q(string s, ll i, ll j) {
	fout(s, ' ', i+1, ' ', j+1, nl);
	fflush(stdout);
	ll x;
	fin(x);
	return x;
}

ll get(ll x, ll ind) {
	return tp(ind) & x;
}

void solve() {
	ll n;
	fin(n);

	VLL A(n);

	ll a = q("XOR", 1, 2);
	ll c = q("AND", 1, 2);
	ll d = q("OR", 0, 1);
	ll e = q("OR", 0, 2);
	ll f = q("AND", 0, 1);
	
	rep(i,0,20) {
		if (get(a, i) == 0) {
			// 1 and 2 have the same value at the ith bit
			if (get(c, i)) {
				// both are 1s
				A[1] |= tp(i);
				A[2] |= tp(i);
				
			} 
		} else {
			// 1 and 2 have different value at the ith bit
			if (get(d, i) && get(e, i)) { 
				if (get(f, i)) {
					// 1 is 1, 2 is 0
					A[1] |= tp(i);
				} else {
					A[2] |= tp(i);
				}
			} else if (get(d, i)) {
				A[1] |= tp(i);
			} else {
				A[2] |= tp(i);
			}
		}

		if (get(A[1], i)) {
			if (get(f, i)) {
				A[0] |= tp(i);
			}
		} else {
			if (get(d, i)) {
				A[0] |= tp(i);
			}
		}
	}

	rep(i,3,n) {
		ll x = q("XOR", 0, i);
		A[i] = A[0] ^ x; 
	}

	fout("! ", A, nl);
}

signed main() {
	ll t = 1;
	// fin(t);
	rep(i,0,t) solve();
	return 0;
}