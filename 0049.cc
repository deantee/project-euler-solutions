#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<bool> is_prime(1e5);
  is_prime[2] = true;
  for (ll i{3}; i < ll(is_prime.size()); i += 2) {
    is_prime[i] = true;
  }
  for (ll i{3}; i < ll(is_prime.size()); i += 2) {
    if (!is_prime[i]) {
      continue;
    }
    for (ll j{i * i}; j < ll(is_prime.size()); j += i * 2) {
      is_prime[j] = false;
    }
  }
  for (ll i{1001}; i + 3330 + 3330 < 10000; i += 2) {
    if (i == 1487) {
      continue;
    }
    ll j{i + 3330}, k{j + 3330};
    if (!is_prime[i] || !is_prime[j] || !is_prime[k]) {
      continue;
    }
    string t0{to_string(i)};
    string t1{to_string(j)};
    string t2{to_string(k)};
    sort(t0.begin(), t0.end());
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if (t0 == t1 && t0 == t2) {
      cout << i << j << k << '\n';
      return 0;
    }
  }
}
