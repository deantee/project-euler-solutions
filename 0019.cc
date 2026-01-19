#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto get_days = [](ll year, ll month) -> ll {
    if (month != 2) {
      return (month & 1) != month > 7 ? 31 : 30;
    } else if (year % 400 == 0 || year % 100 != 0) {
      return 28;
    } else {
      return 29;
    }
  };
  ll offset{366};
  ll ans{};
  for (ll i{1901}; i <= 2000; ++i) {
    for (int j{1}; j <= 12; ++j) {
      if (offset % 7 == 0) {
        ++ans;
      }
      offset += get_days(i, j);
    }
  }
  cout << ans << '\n';
}
