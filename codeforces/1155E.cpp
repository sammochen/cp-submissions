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
void makemod(ll & x, ll m) { x %= m; x += m; x %= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;	ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
bool isvowel(char ch) { ch = tolower(ch); return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'); }
ll sign(ll x) {	return x > 0 ? 1 : x < 0 ? -1 : 0; }

void upmin(ll & x, ll v) { x = min(x, v); }
void upmax(ll & x, ll v) { x = max(x, v); }

const ll inf = (ll)1e18 + 5;
const ll mod = 1e6+3;
const ll mod2 = 998244353;
const db eps = 1e-10;
const db pi = acos(0) * 2;
const string nl = "\n";

ll flip(ll x) {
	makemod(x, mod);
	return powmod(x, mod-2, mod);
}

void rowflip(VVLL & A, ll i, ll j) {
	VLL temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void rowmult(VVLL & A, ll i, ll k) {
	makemod(k, mod);
	rep(j,0,A.size()) {
		A[i][j] *= k;
		makemod(A[i][j], mod);
	}
}

void rowaddmult(VVLL & A, ll i, ll j, ll k) {
	makemod(k, mod);
	rep(x,0,A.size()) {
		A[i][x] += k * A[j][x];
		makemod(A[i][x], mod);
	}
}

VVLL identity(ll n) {
	VVLL A(n, VLL(n));
	rep(i,0,n) {
		A[i][i] = 1;
	}
	return A;
}

VVLL inverse(VVLL A) {
	ll n = A.size();
	VVLL I = identity(n);

	rep(p,0,n) {
		rep(x,p,n) {
			if (A[x][p] != 0) {
				rowflip(I, x, p);
				rowflip(A, x, p);
				break;
			}
		}

		rowmult(I, p, flip(A[p][p]));
		rowmult(A, p, flip(A[p][p]));

		rep(r,0,n) {
			if (r == p) continue;

			rowaddmult(I, r, p, -A[r][p]);
			rowaddmult(A, r, p, -A[r][p]);
		}
		
	}
	return I;
}

VVLL operator*(VVLL a, VVLL b) {
	VVLL c(a.size(), VLL(b[0].size()));
	
	rep(i,0,a.size()) {
		rep(j,0,a[0].size()) {
			rep(k,0,b[0].size()) {
				c[i][k] += a[i][j] * b[j][k] % mod;
				makemod(c[i][k], mod);
			}
		}
	}
	
	return c;			
}

ll query(ll x) {
	printf("? %lld\n", x);
	fflush(stdout);
	fin(x);
	return x;
}

void solve() {
	ll k = 11;
	VVLL A(k, VLL(k));
	VVLL x(k, VLL(1));

	rep(i,0,k) {
		rep(j,0,k) {
			A[i][j] = (j == 0) ? 1 : A[i][j-1] * (i+1) % mod;
		}
		x[i][0] = query(i+1);
	}

	VVLL inv = inverse(A);
	VVLL ans = inv * x;

	// brute force
	rep(i,0,mod) {
		ll v = 0;
		ll p = 1;
		rep(j,0,k) {
			v += ans[j][0] * p;
			makemod(v, mod);

			p *= i;
			makemod(p, mod);
		}
		if (v == 0) {
			fout("! ", i, nl);
			exit(0);
		}
	}
	fout("! -1\n");
}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}