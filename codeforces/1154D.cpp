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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) { ll a = scanf("%lld", &x); }

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

void solve() {
	VLL A(3);
	rep(i,0,3) cin >> A[i];
	//         1 2 3 4 5 6 7
	VLL eat = {0,1,2,0,2,1,0};

	ll ans = 0;
	rep(i,0,7) {
		VLL B = A;
		ll cur = 0;
		
		ll x = B[0] / 3;
		upmin(x, B[1] / 2);
		upmin(x, B[2] / 2);

		B[0] -= 3*x;
		B[1] -= 2*x;
		B[2] -= 2*x;
		cur += 7*x;

		rep(j,i,inf) {
			if (B[eat[j%7]] == 0) break;
			B[eat[j%7]]--;
			cur++;
		}
		upmax(ans, cur);
	}

	cout << ans << endl;
}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}