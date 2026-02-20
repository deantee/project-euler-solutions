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
  const ll N(1e7);
  vector<bool> is_prime(N);
  is_prime[2] = true;
  for (ll i{3}; i < N; i += 2) {
    is_prime[i] = true;
  }
  for (ll i{3}; i < N; i += 2) {
    if (!is_prime[i]) {
      continue;
    }
    for (ll j{i * i}; j < N; j += i * 2) {
      is_prime[j] = false;
    }
  }
  for (ll d{2}; d < 7; ++d) {
    for (ll i{fastpow(10, d - 1)}; i < fastpow(10, d); ++i) {
      string str{to_string(i)};
      for (ll j{1}; j < 1LL << (d - 1); ++j) {
        string cpy{str};
        vector<ll> pos;
        for (ll k{}; k < d - 1; ++k) {
          if (j >> k & 1) {
            pos.emplace_back(k);
          }
        }
        vector<ll> vec;
        for (ll i{1}; i < 10; ++i) {
          for (ll p : pos) {
            cpy[p] = i + '0';
          }
          ll x{stoll(cpy)};
          if (is_prime[x]) {
            vec.emplace_back(x);
          }
        }
        if (ll(vec.size()) == 8) {
          cout << vec[0] << '\n';
          return 0;
        }
      }
    }
  }
}
