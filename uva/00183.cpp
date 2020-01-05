/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {
	VVLL merge(VVLL A, VVLL B, VVLL C, VVLL D) {
		ll N = A.size() + C.size();
		ll M = B.size() == 0 ? A[0].size() : A[0].size() + B[0].size();
		ll n = A.size();
		ll m = A[0].size();

		VVLL X(N, VLL(M));
		REP(i,0,N) {
			REP(j,0,M) {
				if (i < n && j < m) X[i][j] = A[i][j];
				else if (i < n) X[i][j] = B[i][j-m];
				else if (i >= n && j < m) X[i][j] = C[i-n][j];
				else X[i][j] = D[i-n][j-m];
			}
		}
	
		return X;
	}

	VVLL getB(string D, ll i, ll j, ll & ind) {
		if (i == 0 || j == 0) {
			VVLL A;
			return A;
		};

		if (D[ind] == '1') {
			ind++;
			VVLL A(i, VLL(j, 1));
			return A;
		} else if (D[ind] == '0') {
			ind++;
			VVLL A(i, VLL(j, 0));
			return A;
		} else {
			ind++;
			VVLL topleft = getB(D, i - i/2, j - j/2, ind);
			VVLL topright = getB(D, i - i/2, j/2, ind);
			VVLL botleft = getB(D, i/2, j - j/2, ind);
			VVLL botright = getB(D, i/2, j/2, ind);
			return merge(topleft, topright, botleft, botright);
		}
	}	

	string getD(VVLL & B, ll i, ll j, ll r, ll w) {
		if (r == 0 || w == 0) return "";
		if (r == 1 && w == 1) {
			if (B[i][j] == 1) return "1";
			else return "0";
		}
		string topleft = getD(B, i, j, r - r/2, w - w/2);
		string topright = getD(B, i, j + w - w/2, r - r/2, w/2);
		string botleft = getD(B, i + r - r/2, j, r/2, w - w/2);
		string botright = getD(B, i + r - r/2, j + w - w/2, r/2, w/2);

		string compact = topleft + topright + botleft + botright;
		VLL freq(2);
		for (char c : compact) {
			if (c == 'D') {
				freq[0] = 1;
				freq[1] = 1;
				break;
			}
			freq[c - '0'] = 1;
		}
		
		if (freq[0] && freq[1]) return "D" + compact;
		else if (freq[0]) return "0";
		else return "1";
	}

	void process(string type, ll n, ll m, string s) {
		string ans;
		if (type == "B") {
			VVLL matrix(n, VLL(m));
			REP(i,0,n) {
				REP(j,0,m) {
					matrix[i][j] = s[i*m+j] - '0';
				}
			}
			ans = getD(matrix, 0, 0, n, m);
			
		} else {
			ll ind = 0;
			VVLL matrix = getB(s, n, m, ind);
			ans = "";
			REP(i,0,n) {
				REP(j,0,m) {
					if (matrix[i][j] == 0) ans += "0";
					else ans += "1";
				}
			}
		}

		string newtype = type == "B" ? "D" : "B";
		printf("%s%4lld%4lld\n", newtype.c_str(), n, m);
		
		REP(i,0,ans.length()) {
			cout << ans[i];
			if (i % 50 == 49 || i == ans.length() - 1) printf("\n");
		}
	}

	void main() {
		string type, ans;
		ll n, m;
		cin >> type;

		while (type != "#") {
			cin >> n >> m;
		
			string s, temp;
			while (cin >> temp) {
				// if finish reading the string
				if (s.length() == n*m || temp == "D" || temp == "B" || temp == "#") {
					process(type, n, m, s);
					type = temp;
					break;
				} else {
					s += temp;
				}
			}
	
			
		}
		
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
