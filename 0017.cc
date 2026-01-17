#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll a[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
  ll b[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
  auto solve = [&](auto&& self, ll n) -> ll {
    if (n < 20) {
      return a[n];
    }
    if (n < 100) {
      return b[n / 10] + a[n % 10];
    }
    if (n < 1000) {
      ll res = a[n / 100] + 7;
      if (n % 100 != 0) {
        res += 3 + self(self, n % 100);
      }
      return res;
    }
    return 11;
  };
  ll ans{};
  for (ll i{1}; i <= 1000; ++i) {
    ans += solve(solve, i);
  }
  cout << ans << "\n";
  return 0;
}
