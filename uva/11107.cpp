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

VLL seedpow = {1};
VLL invseedpow;

void update(ll n, ll seed, ll mod) {
	while (sz(seedpow) < n) {
		seedpow.pb(seedpow.back() * seed % mod);
	}
	while (sz(invseedpow) < n) {
		invseedpow.pb(powmod(seedpow[sz(invseedpow)], mod-2, mod));
	}
}

struct hasher {
	string s;
	ll mod;
	ll seed = 31;
	VLL val;

	ll toll(char c) {
		return c - 'a' + 1;
	}
	hasher(string str, ll m = 1000000207) {
		s = str;
		mod = m;

		update(lg(s) + 5, seed, mod);

		val.resize(s.length() + 1);
		rep(i,0,s.length()) {
			val[i+1] = (val[i] + toll(s[i]) * seedpow[i] % mod) % mod;
		}
	}

	ll f(ll i, ll j) {
		ll diff = (val[j+1] - val[i] + mod) % mod;
		// times this by how far away i is! 
		diff *= invseedpow[i];
		diff %= mod;
		return diff;
	}
};

MLL get(VS & A, vector<hasher*> & hashes, ll & n, ll & M) {
	MLL freq;
	// look for substrings size M in all 
	rep(i,0,n) {
		set<ll> subs;
		// abcdef
		rep(j,0,lg(A[i]) - M + 1) {
			subs.insert(hashes[i]->f(j, j+M-1));
		}
		fe(x, subs) freq[x]++;
	}
	return freq;
}

void solve() {
	ll first = 1;
	string temp;

	while (getline(cin, temp), temp != "0") {
		ll n = stoll(temp);
		if (first == 0) {
			fout(nl);
		}
		first = 0;

		VS A(n);
		vector<hasher*> hashes(n);

		rep(i,0,n) {
			getline(cin, A[i]);
			hashes[i] = new hasher(A[i]);
		}

		ll L = 0, R = 1005;
		while (L<R) {
			ll M = (L+R)/2;
			
			MLL freq = get(A, hashes, n, M);

			ll ok = 0;
			fe(p, freq) {
				if (p.second * 2 > n) {
					ok++;
				} 
			}
			if (ok) L = M+1;
			else R = M;
		}
		L--;

		if (L <= 0) {
			fout("?", nl);
			continue;
		}

		MLL freq = get(A, hashes, n, L);
		SLL goods;
		fe(p, freq) {
			if (p.second * 2 > n) goods.insert(p.first);
		}

		VS ans;
		rep(i,0,n) {
			rep(j,0,lg(A[i]) - L + 1) {
				ll h = hashes[i]->f(j, j+L-1);
				if (goods.find(h) != goods.end()) {
					ans.pb(A[i].substr(j, L));
					goods.erase(h);
				}
			}
		}

		sort(all(ans));
		fe(x, ans) fout(x, nl);
	}
}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}