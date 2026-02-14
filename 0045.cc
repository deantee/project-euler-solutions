#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto t = [](ll n) -> ll { return n * (n + 1) / 2; };
  auto p = [](ll n) -> ll { return n * (n * 3 - 1) / 2; };
  auto h = [](ll n) -> ll { return n * (n * 2 - 1); };
  ll i, j, k;
  i = j = k = 1;
  while (true) {
    ll a{t(i)}, b{p(j)}, c{h(k)};
    if (a == b && b == c && a > 40755) {
      cout << a << '\n';
      return 0;
    } else if (a < b) {
      if (a < c) {
        ++i;
      } else {
        ++k;
      }
    } else if (a < c) {
      if (a < b) {
        ++i;
      } else {
        ++j;
      }
    } else if (a < b) {
      ++i;
    } else {
      ++j;
    }
  }
}
