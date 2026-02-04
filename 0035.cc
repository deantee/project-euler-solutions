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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll ans{};
  for (ll i{2}; i < fastpow(10, 6); ++i) {
    ll digit(to_string(i).size());
    ll t{i};
    bool flag{true};
    for (ll j{}; j < digit; ++j) {
      t = t / 10 + t % 10 * fastpow(10, digit - 1);
      if (!is_prime(t)) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << i << '\n';
      ++ans;
    }
  }
  cout << ans << '\n';
}
