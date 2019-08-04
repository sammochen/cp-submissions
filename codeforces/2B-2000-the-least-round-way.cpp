/*
Original problem: https://codeforces.com/problemset/problem/2/B
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define MP make_pair
#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const int inf = 1e9 + 7;

namespace SOLVE {
	// returns how many times f goes into x
	int fs(int x, int f) {
		if (x == 0) {
			return inf;
		}
		int ans = 0;
		while (x % f == 0) {
			ans++;
			x /= f;
		}
		return ans;
	}

	// supports pair<int,int> addition
	PII operator+ (PII a, PII b) {
		return MP(a.first + b.first, a.second + b.second);
	}

	// placed outside main because memory
	PII dp[1001][1001][2];

	string inv = "-";

	void main() {
		const int TWO = 0, FIVE = 1;
		// the answer will be one of: choose the path with least 2s or least 5s
		// special case: if there is a 0, choose it UNLESS there is a path with no 0s at all

		int n, temp;
		cin >> n;
		vector<vector<PII>> grid(n, vector<PII>(n)); // grid[i][j] is a pair: (2s, 5s) since that's all that matters
		string zeropath = inv;

		REP(i, 0, n) {
			REP(j, 0, n) {
				cin >> temp;
				if (temp == 0 && zeropath == inv) {
					zeropath = string(i, 'D') + string(j, 'R') + string(n - 1 - i, 'D') + string(n - 1 - j, 'R');
				}
				grid[i][j] = MP(fs(temp, 2), fs(temp, 5));
			}
		}

		// base cases: no choice when i or j is 0
		dp[0][0][TWO] = grid[0][0];
		dp[0][0][FIVE] = grid[0][0];

		REP(i, 1, n) {
			dp[0][i][TWO] = dp[0][i - 1][TWO] + grid[0][i];
			dp[i][0][TWO] = dp[i - 1][0][TWO] + grid[i][0];

			dp[0][i][FIVE] = dp[0][i - 1][FIVE] + grid[0][i];
			dp[i][0][FIVE] = dp[i - 1][0][FIVE] + grid[i][0];
		}

		REP(i, 1, n) {
			REP(j, 1, n) {
				// dp2
				PII opt1 = dp[i - 1][j][TWO];
				PII opt2 = dp[i][j - 1][TWO];
				if (opt1.first < opt2.first) {
					dp[i][j][TWO] = opt1 + grid[i][j];
				}
				else if (opt1.first > opt2.first) {
					dp[i][j][TWO] = opt2 + grid[i][j];
				}
				else {
					dp[i][j][TWO] = opt1.second > opt2.second ? opt2 + grid[i][j] : opt1 + grid[i][j];
				}

				// dp5
				opt1 = dp[i - 1][j][FIVE];
				opt2 = dp[i][j - 1][FIVE];
				if (opt1.second < opt2.second) {
					dp[i][j][FIVE] = opt1 + grid[i][j];
				}
				else if (opt1.second > opt2.second) {
					dp[i][j][FIVE] = opt2 + grid[i][j];
				}
				else {
					dp[i][j][FIVE] = opt1.first > opt2.first ? opt2 + grid[i][j] : opt1 + grid[i][j];
				}
			}
		}

		PII ans2 = dp[n - 1][n - 1][TWO];
		PII ans5 = dp[n - 1][n - 1][FIVE];
		int zeros2 = min(ans2.first, ans2.second);
		int zeros5 = min(ans5.first, ans5.second);
		int ans = -1;

		// if the zeropath is the best option
		if (min(zeros2, zeros5) >= 1 && zeropath != inv) {
			cout << 1 << endl;
			cout << zeropath << endl;
			return;
		}

		// otherwise: find better choice between 2 and 5
		if (zeros2 < zeros5) {
			cout << zeros2 << endl;
			ans = TWO;			
		}
		else {
			cout << zeros5 << endl;
			ans = FIVE;
		}

		// backtracking to find the path
		stack<char> S;
		int i = n - 1, j = n - 1;
		while (i != 0 && j != 0) {
			if (dp[i - 1][j][ans] + grid[i][j] == dp[i][j][ans]) {
				S.push('D');
				i--;
			}
			else {
				S.push('R');
				j--;
			}
		}
		while (i != 0) {
			S.push('D');
			i--;
		}
		while (j != 0) {
			S.push('R');
			j--;
		}

		while (S.size()) {
			cout << S.top();
			S.pop();
		}
		cout << endl;
	}
}

signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}