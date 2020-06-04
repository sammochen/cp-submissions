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

VVLL E;
VLL col, cnt;
VVLL child;

void dfs(ll at, ll r) {
	child[r].pb(at);
	cnt[col[at]-1]++;
	fe(to, E[at]) {
		if (!col[to]) {
			col[to] = 3 - col[at];
			dfs(to, r);
		} else if (col[to] == col[at]) {
			cout << "NO" << endl;
			exit(0);
		}
	}
}

ll dp[5005][5005] = {0};

void solve() {
	ll n, m;
	cin >> n >> m;
	VLL color(3);
	rep(i,0,3) cin >> color[i];

	E.resize(n);
	rep(i,0,m) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		E[a].pb(b);
		E[b].pb(a);
	}


	// check all the components are bipartite
	col.assign(n, 0);
	child.resize(n);
	VVLL choice;
	ll r = 0;
	rep(i,0,n) {
		if (!col[i]) {
			cnt = VLL(2);
			col[i] = 1;
			dfs(i, r++);

			choice.pb(cnt);
		}
	}

	
	dp[0][0] = 1;
	rep(i,0,sz(choice)) {
		rep(j,0,5005) {
			if (dp[i][j]) {
				dp[i+1][j+choice[i][0]] = 1;
				dp[i+1][j+choice[i][1]] = 1;
			}
		}
	}

	if (dp[sz(choice)][color[1]] == 0) {
		cout << "NO" << endl;
		return;
	}

	string ans(n, '?');
	ll y = color[1];
	rrep(i,sz(choice)-1,0) {
		if (y - choice[i][0] >= 0 && dp[i][y - choice[i][0]]) {
			// chose 0
			fe(c, child[i]) {
				if (col[c] == 1) {
					ans[c] = '2';
				} else {
					ans[c] = '1';
				}
			}
			
			y -= choice[i][0];
		} else {
			// chose 1
			fe(c, child[i]) {
				if (col[c] == 1) {
					ans[c] = '1';
				} else {
					ans[c] = '2';
				}
			}

			y -= choice[i][1];
		}
	}

	ll i = 0;
	rep(j,0,color[2]) {
		while (ans[i] == '2') i++;
		ans[i] = '3';
		i++;
	}

	cout << "YES" << endl;
	cout << ans << endl;

}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}