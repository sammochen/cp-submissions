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
    string f(const char* a) { return a; }
	template <typename A, typename B> string f(pair<A,B> p) { return open + f(p.first) + sep + f(p.second) + close; }
	template <typename A> string f(A v) { string s = open; for (auto a : v) { if (s != open) { s += sep; } s += f(a); } s += close; return s; } 

	void show() {cout << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cout << " " << f(H); show(T...); }
};

#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)

struct FASTINPUT {
	void f(string & s) { char buf[100005]; ll a = scanf("%s", buf); a++; s = buf; }
	void f(ll & x) { ll a = scanf("%lld", &x); a++; }
	void f(int & x) { ll a = scanf("%d", &x); a++; }
	template <typename A, typename B> void f(pair<A,B> p) { f(p.first); f(p.second); }
	template <typename A> void f(vector<A> & x) { for (auto & y : x) f(y); }
	
	void read() {}
	template <typename Head, typename... Tail> void read(Head & H, Tail & ... T) { f(H); read(T...); }
};

#define fin(...) do { FASTINPUT inp; inp.read(__VA_ARGS__); } while (false)

struct FASTOUTPUT {
	void f(string s) { printf("%s", s.c_str()); }
	void f(ll x) { printf("%lld", x); }
    void f(int x) { printf("%d", x); }
    void f(char x) { printf("%c", x); }
    void f(const char* a) { printf("%s", a); }
	
	void print() {}
	template <typename Head, typename... Tail> void print(Head H, Tail ... T) { f(H); print(T...); }
};

#define fout(...) do { FASTOUTPUT out; out.print(__VA_ARGS__); } while (false)

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
template <typename A, typename B> ll exist(A a, B b) { return a.find(b) != a.end(); }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }

void upmin(ll & x, ll v) { x = min(x, v); }
void upmax(ll & x, ll v) { x = max(x, v); }

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const db eps = 1e-10;


struct edge {
    ll at, to, d, ind;
};

struct todo {
    ll v, d, prev;
};

bool operator<(const todo & a, const todo & b) {
    return a.d > b.d;
}

VLL ans;

VLL dijkstra(vector<vector<edge>> & E, ll s) {
    VLL d(E.size(), inf);
    VLL vis(E.size());
    d[s] = 0;
    
    priority_queue<todo> pq;

    pq.push({s, 0, -1});
    while (pq.size()) {
        todo t = pq.top();
        pq.pop();

        if (!vis[t.v]) {
            if (t.prev != -1) ans.pb(t.prev);

            vis[t.v] = 1;
        } else {
            continue;
        }

        for (edge e : E[t.v]) {
            if (d[t.v] + e.d < d[e.to]) {
                pq.push({e.to, d[t.v] + e.d, e.ind});
                d[e.to] = d[t.v] + e.d;
            } 
        }
    }

    return d;
}

void solve() {
	ll n, m, k;
    fin(n, m, k);

    vector<vector<edge>> E(n);
    rep(i,0,m) {
        ll a, b, w;
        fin(a, b, w);
        a--; b--;
        E[a].pb({a,b,w,i+1});
        E[b].pb({b,a,w,i+1});
    }

    dijkstra(E, 0);

    ll cnt = min(k, n-1);
    fout(cnt, "\n");
    rep(i,0,cnt) fout(ans[i], " ");  
    fout("\n");  

}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}