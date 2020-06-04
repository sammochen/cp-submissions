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
const ll mod = 998244353;

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
template <typename A, typename B> ll exist(A a, B b) { return a.find(b) != a.end(); }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }

void upmin(ll & x, ll v) { x = min(x, v); }
void upmax(ll & x, ll v) { x = max(x, v); }

ll nax = 500005;

VLL F(nax, -1);
VLL INVF(nax, -1);

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	ll h = pow(a, b/2);
	ll ans = b % 2 ? h * h % mod * a : h * h;
	ans %= mod;
	return ans;
}

ll f(ll x) {
	if (F[x] != -1) return F[x];
	if (x == 0) return 1;
	F[x] = f(x-1) * x % mod;
	return F[x];
}

ll invf(ll x) {
	if (INVF[x] != -1) return INVF[x];
	INVF[x] = pow(f(x), mod-2);
	return INVF[x];
}

ll ncr(ll n, ll r) {
	// n! / r! / (n-r)!
	ll ans = f(n);
	ans *= invf(r);
	ans %= mod;
	ans *= invf(n-r);
	ans %= mod;
	return ans;
}

void solve() {
	rep(i,0,nax) f(i);
	
	ll n, k;
	cin >> n >> k;
	// size k, each value is 1<=v<=n
	// so for every random value x, mod all of them in any order gives the same result
	
	ll ans = 0;
	rep(i,1,n+1) {
		// for the rest of k, i need to choose k-1 items from 
		ll choices = n/i;
		if (choices < k) continue;

		ans += ncr(choices - 1, k-1);
		ans %= mod;
	}
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}