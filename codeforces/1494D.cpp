#ifdef SAM
#include "stdc++.h"
#else
#include <bits/stdc++.h>
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

#ifdef SAM
#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)
#else
#define debug(...) do {} while (false)
#endif

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};

void readstr(string & s, const ll len=400005) { char buf[len]; ll a = scanf("%s", buf); a++; s = buf; }
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }
void makemod(ll & x, ll m) { x %= m; x += m; x %= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;	ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
bool isvowel(char ch) { return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'); }
ll sign(ll x) {	return x > 0 ? 1 : x < 0 ? -1 : 0; }

template<typename A, typename B> void upmin(A & x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A & x, B v) { x = max(x, (A)v); }

const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;
const string nl = "\n";

VLL parent;
VLL salary;
ll ids = 0;

void bigger(VLL & A, ll s, ll v = -1) {
	while (s >= A.size()) A.pb(v);
}

// return the id
ll dfs(VVLL & matrix, uset<ll> people) {
	if (people.size() == 1) {
		ll cur = *people.begin();
		salary[cur] = matrix[cur][cur];
		return cur;
	}

	// find the largest element, and make a new node of this salary.
	ll n = matrix.size();
	ll biggest_salary = -inf;
	fe(p, people) {
		fe(q, people) {
			upmax(biggest_salary, matrix[p][q]);
		}
	}

	// cool so there is exactly one person who has this salary, and they are everyone's boss.
	// if two people dont have this, they are on the same subtree
	vector<uset<ll>> subtrees;
	fe(p, people) {
		ll ok = 0;
		for (auto &subtree : subtrees) {
			ll q = *subtree.begin();
			if (matrix[p][q] != biggest_salary) {
				subtree.insert(p);
				ok = 1;
				break;
			}
		}
		if (ok == 0) {
			subtrees.pb({p});
		}
	}

	ll cur = ids++;
	bigger(salary, cur);
	bigger(parent, cur);
	
	salary[cur] = biggest_salary;
	for (auto &subtree : subtrees) {
		ll child = dfs(matrix, subtree);
		parent[child] = cur;
	}
	return cur;
}

void solve() {
	ll n;
	cin >> n;
	VVLL matrix(n, VLL(n));
	rep(i,0,n) rep(j,0,n) cin >> matrix[i][j];

	ids = n;

	uset<ll> people;
	rep(i,0,n) people.insert(i);
	dfs(matrix, people);

	ll k = sz(parent);
	cout << k << endl;
	rep(i,0,k) cout << salary[i] << ' ';
	cout << endl;

	ll boss = -1;
	rep(i,0,k) {
		if (parent[i] == -1) boss = i;
	}
	cout << boss+1 << endl;
	rep(i,0,k) {
		if (parent[i] == -1) continue;
		cout << i+1 << ' ' << parent[i]+1 << endl;
	}
}

signed main() {
	ll t = 1;
	// cin >> t;
	rep(i,0,t) solve();
	return 0;
}