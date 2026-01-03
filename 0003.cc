#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n{600851475143};
  ll ans{1};
  for (ll i{3}; i * i <= n; i += 2) {
    if (n % i) {
      continue;
    }
    ans = i;
    while (n % i == 0) {
      n /= i;
    }
  }
  cout << max(ans, n) << '\n';
}
