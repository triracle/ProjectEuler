#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

const int maxn = 1e4 + 1;

int main() {
  int ans = 0;
  rep(i, 1, maxn) {
    int x = (int)floor(sqrt(i));
    if (x * x == i) continue;
    int m0 = 0;
    int d0 = 1;
    int a0 = x;
    int mn = m0, dn = d0, an = a0;
    int cnt = 0;
    do {
      mn = dn * an - mn;
      dn = (i - mn * mn) / dn;
      an = (int)floor((double)(a0 + mn) / dn);
      cnt++;
    } while (an != 2 * a0);
    ans += (cnt % 2);
  }

  cout << ans;

  return 0;
}
