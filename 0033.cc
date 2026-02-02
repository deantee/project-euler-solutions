#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<pair<ll, ll>> nt;
  for (ll i{1}; i < 10; ++i) {
    for (ll j{}; j < 10; ++j) {
      for (ll k{i}; k < 10; ++k) {
        for (ll l{i == k ? j + 1 : 0}; l < 10; ++l) {
          if (i != k && i != l && j != k && j != l) {
            continue;
          }
          if (j == 0 && l == 0) {
            continue;
          }
          ll a{i * 10 + j}, b{k * 10 + l}, g{gcd(a, b)}, p{a / g}, q{b / g};
          ll x{}, y{};
          if (i == k) {
            x = j;
            y = l;
          } else if (i == l) {
            x = j;
            y = k;
          } else if (j == k) {
            x = i;
            y = l;
          } else {
            x = i;
            y = k;
          }
          ll g1{gcd(x, y)};
          if (x / g1 == p && y / g1 == q) {
            nt.emplace_back(p, q);
          }
        }
      }
    }
  }
  ll p{1}, q{1};
  for (auto& [a, b] : nt) {
    p *= a;
    q *= b;
    ll g{gcd(p, q)};
    p /= g;
    q /= g;
  }
  cout << q << '\n';
}
