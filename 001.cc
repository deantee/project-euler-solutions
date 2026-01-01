#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto f = [](ll n, ll d) -> ll {
    ll m{n / d};
    return m * (m + 1) / 2 * d;
  };
  cout << f(1000, 3) + f(1000, 5) - f(1000, 3 * 5) << '\n';
}
