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

#define lsb(i) ((i)&-(i))

const ll nax = 2e5 + 5;

struct fenwick {
	ll arr[nax] = {0};

	void add(ll i, ll k) {
		while (i < nax) {
			arr[i] += k;
			i += lsb(i);
		}
	}

	ll sum(ll i) {
		ll total = 0;
		while (i > 0) {
			total += arr[i];
			i -= lsb(i);
		}
		return total;
	}
};

ll test = 1;
void solve() {
	fenwick big, pre;
	ll n, q;
	cin >> n >> q;
	VLL A(n);
	rep(i,0,n) {
		cin >> A[i];
		pre.add(i+1, (i%2 ? 1 : -1) * A[i]);
		big.add(i+1, (i%2 ? 1 : -1) * (i+1) * A[i]); // 1-indexed, 1 is positive
	}

	ll x = 0;
	rep(i,0,q) {
		string s;
		ll a, b;
		cin >> s >> a >> b;

		if (s == "Q") {
			ll ans = big.sum(b) - big.sum(a-1);
			ans -= (pre.sum(b) - pre.sum(a-1)) * (a-1);
			if (a % 2 == 1) ans *= -1;
			x += ans;
		} else {
			ll diff = b - A[a-1];
			pre.add(a, (a%2 ? -1 : 1) * diff);
			big.add(a, (a%2 ? -1 : 1) * a * diff);
			A[a-1] = b;
		}
	}

	printf("Case #%lld: %lld\n", test++, x);
}

signed main() {
	ll t = 1;
	cin >> t;
	rep(i,0,t) solve();
	return 0;
}