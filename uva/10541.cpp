#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
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
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

class big {
	public:

	string to_string() {
		string s;
		RREP(i,A.size()-1,0) s.push_back(A[i] + '0');
		return s;
	}

	big() {

	}
	
	big(ll x) {
		*this = x;
	}

	big(VLL x) {
		*this = x;
	}

	big(string s) {
		*this = 0;
		for (char c : s) {
			*this = *this * 10;
			*this = *this + (c - '0');
		}
	}

	big& operator=(const ll & x) {
		A = {abs(x)};
		sign = x == 0 ? 0 : x > 0 ? 1 : -1;
		make_proper();
		return *this;
	}

	big& operator=(const VLL &B) {
		A = B;
		sign = 1;
		make_proper();
		return *this;
	}

	big& operator=(const big &b) {
		A = b.A;
		sign = b.sign;
		make_proper();
		return *this;
	}


	big operator+(const big & other) {
		ll n = max(A.size(), other.A.size());
		VLL ans(n);
		REP(i,0,n) {
			if (i < A.size()) ans[i] += A[i];
			if (i < other.A.size()) ans[i] += other.A[i];
		}
		big res;
		res = ans;
		return res;
	}

	bool operator==(const ll & other) {
		big o = other;
		return *this == o;
	}

	bool operator==(big & other) {
		if (to_string() == "0" && other.to_string() == "0") return true;
		return to_string() == other.to_string() && sign == other.sign;
	}

	big operator*(const big & other) {
		return mult(*this, other);
	}
	
	big operator/(const big & other) {
		return division(other).first;
	}

	big operator%(const big & other) {
		return division(other).second;
	}

	big operator^(const big & other) {
		return pow(*this, other);
	}

	ll to_ll() {
		return stoll(to_string());
	}

	ll size() {
		return A.size();
	}

	private:
	VLL A;
	int sign = 1;
	int base = 10; 
	
	void make_proper() {
		REP(i,0,A.size()) {
			if (A[i] >= base) {
				if (i == A.size() - 1) {
					A.push_back(0);
				} 
				A[i+1] += A[i] / base;
				A[i] %= base;
			}
		}

		ll index = 0;
		REP(i,0,A.size()) {
			if (A[i] != 0) index = i;
		}
		A.resize(index+1);
	}

	big mult(big a, big b) {
		if (b == 0LL) return 0LL;
		big half = mult(a, b/2);
		big whole = half + half;
		if ((b/2) + (b/2) == b) a = a;
		else whole = whole + a;
		return whole;
	}

	pair<big,big> division(big b) {
		ll divisor = b.to_ll();
		big copy = (*this).A;
		big mod;

		RREP(i,copy.size()-1,0) {
			if (i != 0) copy.A[i-1] += (copy.A[i] % divisor) * base;
			else mod = copy.A[i] % base;
			copy.A[i] = copy.A[i] / divisor;
		}

		copy.make_proper();
		mod.make_proper();
		return {copy, mod};		
	}

	big pow(big a, big b) {
		if (b == 0LL) return 1LL;
		big half = pow(a, b/2);
		big whole = half * half;
		if ((b/2) + (b/2) == b) a = a;
		else whole = whole * a;
		return whole;

	}
};
std::ostream & operator<<(ostream &os, big obj) {
	os << obj.to_string();
	return os;
}

string to_string(big a) {
	return a.to_string();
}


vector<vector<big>> dp;

big get(ll n, ll ind, VLL & A) {
	if (n < 0) return 0;
	if (ind == A.size() && n >= 0) return 1;
	if (!(dp[n][ind] == -1)) return dp[n][ind];

	big ans = get(n - A[ind] - 1, ind+1, A) + get(n-1, ind, A);
	dp[n][ind] = ans;
	return ans;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	dp.clear();
	dp.resize(n+2, vector<big>(k+1, -1));

	VLL A(k);
	REP(i,0,k) cin >> A[i];

	big ans = get(n+1, 0, A);
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}