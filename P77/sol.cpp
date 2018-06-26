#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define sz(a) ((int)a.size())

const int maxn = 72;

vector<int> pr;
int p[maxn], dp[maxn];

int main() {
  p[1] = 1;
  rep(i, 1, maxn) {
    if (p[i]) continue;
    pr.pb(i);
    for (int j = i * 2; j < maxn; j += i) p[j] = 1;
  }

  dp[0] = 1;
  rep(i, 0, sz(pr)) {
    rep(j, pr[i], maxn) {
      dp[j] += dp[j - pr[i]];
    }
  }

  int ans = -1;
  rep(i, 1, maxn) {
    if (!~ans || dp[ans] < dp[i]) {
      ans = i;
    }
  }

  cout << ans << ' ' << dp[ans];

  return 0;
}
