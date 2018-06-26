#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

const int d = 1000000;
int sol[d + 1], p[d + 1], vs[d + 1];

int main() {
  rep(i, 1, d + 1) p[i] = i;
  vs[1] = 1;
  rep(i, 1, d + 1) {
    if (vs[i]) continue;
    for (int j = i; j <= d; j+=i) {
      p[j] = p[j] / i * (i - 1);
      if (j != i) vs[j] = 1;
    }
  }

  long long ans = 0;
  rep(i, 1, d + 1) ans += p[i];

  cout << ans - 1;

  return 0;
}
