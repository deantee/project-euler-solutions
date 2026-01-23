#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  constexpr ll n{28123};
  auto s = [](ll n) -> ll {
    ll k{__builtin_ctzll(n)};
    n >>= k;
    ll res{(1LL << (k + 1)) - 1};
    for (ll i{3}; i <= n / i; i += 2) {
      ll t{1};
      while (n % i == 0) {
        n /= i;
        t = t * i + 1;
      }
      res *= t;
    }
    if (n > 1) {
      res *= n + 1;
    }
    return res;
  };
  set<ll> st;
  for (ll i{2}; i <= n; ++i) {
    if (s(i) - i > i) {
      st.insert(i);
    }
  }
  ll ans{};
  for (ll i{1}; i <= n; ++i) {
    bool bl{};
    for (ll x : st) {
      if (i - x < 2) {
        break;
      }
      if (st.find(i - x) != st.end()) {
        bl = true;
        break;
      }
    }
    if (bl) {
      continue;
    }
    ans += i;
  }
  cout << ans << '\n';
}
