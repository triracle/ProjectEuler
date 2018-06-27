#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

const int maxLen = 1500001;

int has[maxLen];

int gcd(int a, int b) {
  int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void brute_force() {
  int tar = 49;
  int has[tar];
  for (int i = 0; i < tar; i++) has[i] = 0;
  for (int i = 1; i < tar; i++) {
    for (int j = 1; j < i; j++) {
      for (int k = 1; k < tar; k++) {
	if (i + j + k >= tar) continue;
	if (i * i + j * j == k * k) has[i + j + k]++;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < tar; i++) {
    if (has[i] == 1) cout << i << endl;
    ans += (has[i] == 1);
  }
  cout << ans << endl;
}

int main() {
  for (int i = 1; i <= 5000; i++) {
    for (int j = 1; j < i; j++) {
      if (gcd(i, j) == 1) {
	int a = i * i - j * j;
	int b = 2 * i * j;
	int c = i * i + j * j;
	int cur = a + b + c;
	if (gcd(a, b) != 1) continue;
	while (cur < maxLen) {
	  has[cur]++;
	  cur += (a + b + c);
	}
      }
    }
  }

  int ans = 0;
  for (int i = 1; i < maxLen; i++) {
    ans = (has[i] == 1 ? 1 : 0) + ans;
  }

  cout << ans << endl;

  return 0;
}
