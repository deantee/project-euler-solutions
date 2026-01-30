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
  ll digit{2};
  ll ans{};
  while (fastpow(9, 5) * digit >= fastpow(10, digit - 1)) {
    for (ll i{fastpow(10, digit - 1)}; i < fastpow(10, digit); ++i) {
      ll t{i};
      ll sum{};
      while (t) {
        sum += fastpow(t % 10, 5);
        t /= 10;
      }
      if (i == sum) {
        ans += sum;
      }
    }
    ++digit;
  }
  cout << ans << '\n';
}
