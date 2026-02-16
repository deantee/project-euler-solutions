#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto cnt = [](ll n) -> ll {
    ll ans{};
    if (n % 2 == 0) {
      ++ans;
      while (n % 2 == 0) {
        n /= 2;
      }
    }
    for (ll i{3}; i * i <= n; i += 2) {
      if (n % i == 0) {
        ++ans;
        while (n % i == 0) {
          n /= i;
        }
      }
    }
    if (n > 1) {
      ++ans;
    }
    return ans;
  };
  ll first{};
  for (ll i{1};; ++i) {
    if (cnt(i) == 4) {
      if (first == 0) {
        first = i;
      } else if (i - first == 3) {
        cout << first << '\n';
        return 0;
      }
    } else {
      first = 0;
    }
  }
}
