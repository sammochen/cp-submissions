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
typedef unordered_map<ll,ll> MLL;
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

const ll nax = 10 * 1000 * 1000 + 11;
ll minp[nax] = {0};
ll og[nax];
PLL A[nax];
ll one[nax] = {0}, two[nax] = {0};

void init() {
	minp[0] = minp[1] = 1;
	VLL pr;

	for (ll x = 2; x < nax; x++) {
		if (minp[x] == 0) {
			pr.pb(x);
			minp[x] = x;
		}
		
		// for every prime
		for (ll j = 0; j < sz(pr) && pr[j] <= minp[x] && x * pr[j] < nax; j++) {
			minp[x * pr[j]] = pr[j];
		}
	}
}

void fac(ll x, MLL & ans) {
	if (x <= 1) return;
	ans[minp[x]]++;
	fac(x / minp[x], ans);
}

// runs through all the possible divisors
void recur(ll ind, ll cur, vector<PLL> & A, ll & val) {
	if (ind == sz(A)) {
		if (one[cur] == 0) one[cur] = val;
		else if (two[cur] == 0) two[cur] = val;
		return;
	}

	rep(i,0,A[ind].second + 1) {
		recur(ind+1, cur, A, val);
		cur *= A[ind].first;
	}
}

void update(MLL & M, ll val) {
	vector<PLL> pairs(M.begin(), M.end());
	recur(0, 1, pairs, val);
}

void solve() {
	init();

	ll n;
	in(n);
	rep(i,0,n) {
		in(og[i]);
		A[i].fi = og[i];
		A[i].se = i;
	}

	sort(A, A+n);

	rep(i,0,n) {
		if (i >= 2 && A[i].fi == A[i-2].fi) continue; // odd optimisation

		MLL M;
		fac(A[i].fi, M);

		update(M, A[i].se + 1);
	}

	ll x = inf;
	PLL ans;
	rep(i,0,nax) {
		if (two[i] != 0) {
			ll a = og[one[i] - 1];
			ll b = og[two[i] - 1];

			ll g = __gcd(a,b);
			ll cur = a*b/g;

			if (cur < x) {
				x = cur;
				ans = {one[i], two[i]};
			}
		}
	}
	if (ans.fi > ans.se) swap(ans.fi, ans.se);
	
	cout << ans.fi << ' ' << ans.se << endl;
}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}