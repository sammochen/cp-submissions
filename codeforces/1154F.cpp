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

struct INPUT {
	void f(string & s) { char buf[105]; ll a = scanf("%100s", buf); a++; s = buf; }
	void f(ll & x) { ll a = scanf("%lld", &x); a++; }
	void f(int & x) { ll a = scanf("%d", &x); a++; }
	
	void read() {}
	template <typename Head, typename... Tail> void read(Head & H, Tail & ... T) { f(H); read(T...); }
};

#define in(...) do { INPUT inp; inp.read(__VA_ARGS__); } while (false)

ll n, m, k;
vector<PLL> deals; // of 1, you get the cheapest 0 free
VLL pre;

ll dp[2005];

ll get(ll ind) {
	if (ind == k) return 0;
	if (ind > k) return inf;
	if (dp[ind] != -1) return dp[ind];

	ll ans = inf;
	fe(deal, deals) {
		ll cur = get(ind + deal.fi) + pre[ind + deal.fi] - pre[ind + deal.se];
		upmin(ans, cur);
	}

	dp[ind] = ans;
	return ans;
}

void solve() {
	mst(dp, -1);
	in(n, m, k);

	VLL A(n);
	rep(i,0,n) in(A[i]);

	sort(all(A));

	pre.resize(n+1);
	rep(i,0,n) pre[i+1] = pre[i] + A[i];

	VLL best(k+1);
	rep(i,0,m) {
		ll a, b;
		in(a,b);
		if (a > k) continue;

		upmax(best[a], b);
	}

	rep(i,1,k+1) deals.pb({i, best[i]});
	
	cout << get(0) << endl;
}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}