#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static bool is_prime(ll n) {
  if (n < 5) {
    return n == 2 || n == 3;
  }
  if (n % 2 == 0) {
    return false;
  }
  for (ll i{3}; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

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

// i = 0: 2, 3, 5, 7
// i = 1~(n - 1): 1, 3, 7, 9
// i = n - 1: 3, 7

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<ll> first{2, 3, 5, 7}, mid{1, 3, 7, 9}, last{3, 7};
  ll ans{}, cnt{};
  auto dfs = [&](auto&& self, ll i, ll n, ll x) -> void {
    if (i == n) {
      if (!is_prime(x)) {
        return;
      }
      string t{to_string(x)};
      ll m(t.size());
      for (ll i{1}; i < m; ++i) {
        if (!is_prime(stoll(t.substr(i)))) {
          return;
        }
        if (!is_prime(stoll(t.substr(0, i)))) {
          return;
        }
      }
      ans += x;
      ++cnt;
      return;
    }
    if (i == 0) {
      for (ll y : first) {
        self(self, 1, n, y);
      }
      return;
    }
    if (i == n - 1) {
      for (ll y : last) {
        self(self, n, n, x * 10 + y);
      }
      return;
    }
    for (ll y : mid) {
      self(self, i + 1, n, x * 10 + y);
    }
  };
  for (ll i{2};; ++i) {
    if (cnt >= 11) {
      break;
    }
    dfs(dfs, 0, i, 0);
  }
  cout << ans << '\n';
}
