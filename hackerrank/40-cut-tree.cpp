// clang-format off

#include <bits/stdc++.h>

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

	void show() {cerr << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cerr << " " << f(H); show(T...); }
};

#ifdef SAM
#define debug(...) do { DEBUG deb; cerr << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)
#else
#define debug(...) do {} while (false)
#endif

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};

void readstr(string & s, const ll len=400005) { char buf[len]; ll a = scanf("%s", buf); a++; s = buf; }
ll ob(ll i, ll n) { return i < 0 || i >= n; }
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
vector<string> ssplit(const string & from) { vector<string> ans; stringstream ss(from); string s; while (ss >> s) {ans.pb(s);} return ans; }
void makemod(ll & x, ll m) { x %= m; x += m; x %= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;	ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
bool isvowel(char ch) { return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'); }
ll sign(ll x) {	return x > 0 ? 1 : x < 0 ? -1 : 0; }
template<typename A> A reversed(const A & a) { A b = a; reverse(all(b)); return b; }

template<typename A, typename B> void upmin(A & x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A & x, B v) { x = max(x, (A)v); }

const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5, 1000000207};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;

// clang-format on

ll chooseAll(ll at, ll from, ll cuts);

VVLL E;

const ll nax = 55;
ll dp1[nax][nax][nax][nax];
ll dp2[nax][nax];

/**
 * The number of ways to choose `numChildren` children from `at,ind` with
 * exactly `cuts` cuts
 *
 *
 */
ll choose(ll at, ll ind, ll from, ll numChildren, ll cuts) {
    ll atChilds = sz(E[at]) - (at != 0);

    if (ind == sz(E[at])) {
        if (numChildren == 0 && cuts == 0) return 1;
        return 0;
    }

    ll& ans = dp1[at][ind][numChildren][cuts];
    if (ans != -1) return ans;

    ll ignore = choose(at, ind + 1, from, numChildren, cuts);
    if (E[at][ind] == from) return ans = ignore;

    ll keep = 0;
    rep(i, 0, cuts + 1) {
        // you can send `i` cuts down this child
        keep += chooseAll(E[at][ind], at, i) *
                // and you are left with `cuts - i` cuts to do
                choose(at, ind + 1, from, numChildren - 1, cuts - i);
    }
    return ans = ignore + keep;
}

/**
 * Number of subtrees with head at `at` and going to cut exactly `cuts` times
 */
ll chooseAll(ll at, ll from, ll cuts) {
    ll atChilds = sz(E[at]) - (at != 0);

    ll& ans = dp2[at][cuts];
    if (ans != -1) return ans;

    ans = 0;
    rep(keep, 0, sz(E[at]) + 1) {
        // if we keep this many children, we need how many cuts?
        ll curCuts = atChilds - keep;
        ll leftCuts = cuts - curCuts;

        // I need to decide how many children I am keeping
        ans += choose(at, 0, from, keep, leftCuts);
    }
    return ans;
}

// O(n) every call
ll ans(ll at, ll from, ll cuts) {
    ll cur =
        from == -1 ? chooseAll(at, from, cuts) : chooseAll(at, from, cuts - 1);
    fe(to, E[at]) {
        if (to == from) continue;
        cur += ans(to, at, cuts);
    }
    return cur;
}

void solve() {
    mst(dp1, -1);
    mst(dp2, -1);
    ll n, k;
    cin >> n >> k;
    E.resize(n);
    rep(i, 0, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        E[a].pb(b);
        E[b].pb(a);
    }

    ll total = 0;
    rep(i, 0, k + 1) {
        total += ans(0, -1, i);
    }
    // +1 for empty tree
    cout << total + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    rep(i, 0, t) solve();
    return 0;
}