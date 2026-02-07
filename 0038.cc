#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static ll fastpow(ll base, ll exp) {
  ll ans{1};
  while (exp) {
    if (exp % 2) {
      ans *= base;
    }
    base *= base;
    exp /= 2;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll ans{};
  for (ll i{1}; i < ll(1e8); ++i) {
    array<bool, 10> used{};
    ll used_cnt{};
    ll x{};
    bool fail{};
    for (ll j{1}; j <= 9 && used_cnt < 9; ++j) {
      string t{to_string(i * j)};
      for (char c : t) {
        if (c == '0' || used[c - '0']) {
          fail = true;
          break;
        }
        used[c - '0'] = true;
        ++used_cnt;
      }
      if (fail) {
        break;
      }
      x = x * fastpow(10, t.size()) + i * j;
      if (used_cnt == 9) {
        break;
      }
    }
    if (fail || used_cnt != 9) {
      continue;
    }
    ans = max(ans, x);
  }
  cout << ans << '\n';
}
