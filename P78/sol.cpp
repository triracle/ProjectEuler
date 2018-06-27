#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mod = 1e5;

int main() {
  vector<int> p;
  p.pb(1);
  int n = 1;
  while (true) {
    int x = 1;
    int i = 0;
    int j = 1;
    p.pb(0);
    while (x <= n) {
      int sign = (i % 4 < 2 ? 1 : -1);
      (p[n] += sign * p[n - x]) %= 1000000;
      j *= -1;
      if (i % 2) j++;
      i++;
      x = j * (3 * j - 1) / 2;
    }
    if (p[n] == 0) {
      cout << n;
      return 0;
    }
    n++;
  }

  return 0;
}
