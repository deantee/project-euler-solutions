#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll ans{};
  for (ll i{}; i <= 100; ++i) {
    for (ll j{}; j <= i; ++j) {
      ll j0{min(j, i - j)};
      ll fact{1};
      for (ll k{1}; k <= j0; ++k) {
        fact *= i - k + 1;
        fact /= k;
        if (fact > 1000000) {
          ++ans;
          break;
        }
      }
    }
  }
  cout << ans << '\n';
}
