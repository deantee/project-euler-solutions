#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static ll get_digit(ll i) {
  --i;
  ll digit{1};
  ll base{1};
  while (true) {
    ll t{9 * digit * base};
    if (i < t) {
      break;
    }
    i -= t;
    ++digit;
    base *= 10;
  }
  return to_string(base + i / digit)[i % digit] - '0';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll ans{1};
  ll x{1};
  for (ll i{}; i < 7; ++i) {
    ans *= get_digit(x);
    x *= 10;
  }
  cout << ans << '\n';
}
