// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
// #include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
#include <semaphore>
#include <syncstream>
#include <version>
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

struct FASTINPUT {
	void f(string & s) { char buf[2000005]; ll a = scanf("%s", buf); a++; s = buf; }
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

struct AhoCorasick {
	struct T {
		T* child[26];
		VLL ind;
		T* failure;
	};

	T* root;
	void build(VS & dictionary, VLL & B) {
		root = new T();
		root->failure = root;
		rep(i,0,sz(dictionary)) {
			string & d = dictionary[i];
			T* cur = root;
			fe(c, d) {
				T* & next = cur->child[c-'a'];
				if (!next) next = new T();
				cur = next;
			}
			cur->ind.pb(i);
		}

		queue<T*> Q;
		rep(i,0,26) {
			if (root->child[i]) {
				root->child[i]->failure = root;
				Q.push(root->child[i]);
			}
		}
		while (sz(Q)) {
			T* at = Q.front(); Q.pop();

			rep(i,0,26) {
				if (at->child[i]) {
					// look at failure state of current state, and update 
					T* failure = at->failure;
					while (!failure->child[i]) {
						failure = failure->failure;
						if (failure == root) break;
					}
					if (failure->child[i]) failure = failure->child[i];

					at->child[i]->failure = failure;
					
					Q.push(at->child[i]);
				}
			}
		}
	}

	ll search(string & s, ll x, ll y, VLL & B) {
		ll ans = 0;
		T* cur = root;
		fe(c, s) {
			while (!cur->child[c-'a']) {
				cur = cur->failure;
				if (cur == root) break;
			}
			if (cur->child[c-'a']) cur = cur->child[c-'a'];

			// while cur is not root, keep failing it
			T* t = cur;
			while (t != root) {
				fe(ind, t->ind) {
					if (x <= ind && ind <= y) ans += B[ind];
				}
				t = t->failure;
			}
		}
		return ans;
	}
};

void solve() {
	ll n;
	fin(n);
	VS A(n);
	VLL B(n);
	fin(A, B);

	AhoCorasick ac;
	ac.build(A, B);

	ll q;
	fin(q);
	ll lo = inf, hi = -inf;
	rep(_,0,q) {
		ll x, y;
		string s;
		cin >> x >> y >> s;

		ll ans = ac.search(s, x, y, B);
		upmin(lo, ans);
		upmax(hi, ans);
	}

	printf("%lld %lld\n", lo, hi);
}

signed main() {
	ll t = 1;
	// fin(t);
	rep(i,0,t) solve();
	return 0;
}