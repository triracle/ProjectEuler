#include <bits/stdc++.h>

using namespace std;

const int maxS = 3001;
const long long val = 2000000ll;

int main() {
  int found = -1;
  long long dif = 1e18;
  for (int s = 1; s < maxS; s++) {
    for (int i = 1; i <= s; i++) {
      if (s % i == 0) {
	int j = s / i;
	long long a1 = j * (j + 1) / 2;
	long long total = (long long) i * (2ll * a1 + a1 * (i - 1)) / 2;
	if (abs(total - val) < dif) {
	  dif = abs(total - val);
	  found = s;
	}
      }
    }
  }

  cout << found << ' ' << dif << '\n';

  return 0;
}
