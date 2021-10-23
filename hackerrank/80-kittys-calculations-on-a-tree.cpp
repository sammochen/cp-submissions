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
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }
void makemod(ll & x, ll m) { 
    x %= m; 
    if (x < 0) x += m;
}
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
const string nl = "\n";

// clang-format on

namespace LCA {
ll n, k;
VVLL E;

VVLL par;  // par[i][k] gives the 2^k parent, or -1 if too high
VLL depth;
VLL tin, tout;
ll cur_time = 0;

void dfs(const ll& at, const ll& from, const ll& d) {
    par[at][0] = from;
    depth[at] = d;
    tin[at] = cur_time++;

    fe(to, E[at]) {
        if (to == from) continue;
        dfs(to, at, d + 1);
    }

    tout[at] = cur_time++;
}

// checks if i is j's parent
ll is_par(ll i, ll j) {
    return tin[i] <= tin[j] && tout[i] >= tout[j];
}

ll dist_par(ll i, ll j) {
    assert(is_par(i, j));

    // try raise j until it is i

    ll ans = 0;
    rrep(d, k - 1, 0) {
        ll nextj = par[j][d];

        // if j goes too far, don't do it
        if (nextj == -1) continue;
        if (is_par(nextj, i)) continue;

        ans += tp(d);
        j = nextj;
    }
    ans += 1;
    return ans;
}

ll lca(ll i, ll j) {
    if (i == j) return i;
    if (is_par(i, j)) return i;
    if (is_par(j, i)) return j;

    // try increase i as high as possible without being j's parent
    rrep(d, k - 1, 0) {
        ll nexti = par[i][d];
        if (nexti == -1 || is_par(nexti, j)) continue;
        i = nexti;
    }
    return par[i][0];
}

void build(ll n, const VVLL& E) {
    LCA::n = n;
    LCA::E = E;
    LCA::k = log2(n) + 2;

    par.resize(n, VLL(k));
    depth.resize(n);
    tin.resize(n);
    tout.resize(n);
    cur_time = 1;
    dfs(0, -1, 0);

    rep(d, 1, k) {
        rep(i, 0, n) {
            if (par[i][d - 1] == -1) {
                par[i][d] = -1;
            } else {
                par[i][d] = par[par[i][d - 1]][d - 1];
            }
        }
    }
}

}  // namespace LCA

// maps values to 0-based id
struct Mapper {
    ll cur = 0;
    umap<ll, ll> to;

    ll get(ll x) {
        if (to.find(x) == to.end()) {
            to[x] = cur;
            cur++;
        }

        const auto& it = to.find(x);
        assert(it != to.end());
        return it->second;
    }
};

// returns value, value * distance
void dfs2(ll at, const vector<vector<PLL>>& E, const VLL& values, VLL& sum1,
          VLL& sum2) {
    ll value = values[at];
    ll valueDistance = 0;
    fe(e, E[at]) {
        ll to = e.first;
        ll dist = e.second;

        dfs2(to, E, values, sum1, sum2);

        value += sum1[to];  // value increases this much
        valueDistance += sum2[to] + (sum1[to]) * dist;

        value %= mod;
        valueDistance %= mod;
    }
    sum1[at] = value;
    sum2[at] = valueDistance;
}

ll subproblem(const ll n, const ll root, const vector<vector<PLL>>& E,
              const VLL& values) {
    VLL sum1(n);  // sum of (value)
    VLL sum2(n);  // sum of (value * distance)

    dfs2(root, E, values, sum1, sum2);

    ll ans = 0;
    rep(at, 0, n) {
        fe(e, E[at]) {
            ll to = e.first;
            ll dist = e.second;
            // Consider starting from each child
            // I want to consider its value distance, and times it by the sum of
            // values of everything else

            ll cur =
                (sum2[to] + (sum1[to] * dist)) % mod * (sum1[at] - sum1[to]);
            ans += cur;
            makemod(ans, mod);
        }
    }

    return ans;
}

void solve() {
    ll n, q;
    cin >> n >> q;

    VVLL E(n);

    rep(i, 0, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        E[a].pb(b);
        E[b].pb(a);
    }

    LCA::build(n, E);

    // preprocess
    rep(_, 0, q) {
        ll m;
        cin >> m;
        VLL Q(m);
        rep(j, 0, m) {
            cin >> Q[j];
            Q[j]--;
        }

        // build a subtree!
        // we start from the leaves/necessary nodes
        // and we go layer by layer up finding lcas between adj nodes

        Mapper mapper;  // for mapping old indices to new indices

        uset<ll> vis;    // all vis nodes
        set<PLL> layer;  // {tin[i], i}
        fe(a, Q) {
            layer.insert({LCA::tin[a], a});
            vis.insert(a);
        }

        ll prev = -1;
        fe(l, layer) {
            if (prev != -1) {
                vis.insert(LCA::lca(prev, l.second));
            }
            prev = l.second;
        }

        VLL nodes(all(vis));
        sort(all(nodes), [](const auto& a, const auto& b) {
            return LCA::tin[a] < LCA::tin[b];
        });

        // ok i have all the nodes here, I am going to map into a new tree
        ll n2 = sz(nodes);
        vector<vector<PLL>> E2(n2);  // edges have distances
        VLL values(n2);              // nodes have weights

        stack<ll> st;  // this stack will help build the new tree
        ll root = -1;
        fe(x, nodes) {
            if (sz(st) == 0) {
                st.push(x);
                root = mapper.get(x);
                continue;
            }

            while (!LCA::is_par(st.top(), x)) {
                st.pop();
            }

            ll par = st.top();
            ll child = x;
            ll dist = LCA::dist_par(par, child);

            E2[mapper.get(par)].pb({mapper.get(child), dist});

            st.push(x);
        }

        fe(a, Q) {
            values[mapper.get(a)] = a + 1;
        }

        // now i have a subproblem to solve
        ll ans = subproblem(n2, root, E2, values);
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    rep(i, 0, t) solve();
    return 0;
}