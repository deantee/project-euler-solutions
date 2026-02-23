#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static ll rv(char c) {
  return string("23456789TJQKA").find(c) + 2;
}

static vector<ll> score(const array<string, 5>& h) {
  array<ll, 15> cnt{};
  vector<ll> r;
  r.reserve(5);
  bool flush{true};
  char s0{h[0][1]};
  for (const string& c : h) {
    r.emplace_back(rv(c[0]));
    ++cnt[r.back()];
    flush &= (c[1] == s0);
  }
  vector<ll> desc{r};
  sort(desc.rbegin(), desc.rend());
  vector<ll> u{r};
  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());
  bool wheel{u == vector<ll>{2, 3, 4, 5, 14}};
  bool straight{u.size() == 5};
  if (straight) {
    for (ll i{1}; i < 5; ++i) {
      straight &= (u[i] == u[0] + i);
    }
    straight |= wheel;
  }
  ll shigh{wheel ? 5 : (u.size() == 5 ? u.back() : 0)};
  vector<pair<ll, ll>> g;
  for (ll v{2}; v <= 14; ++v) {
    if (cnt[v]) {
      g.emplace_back(cnt[v], v);
    }
  }
  sort(g.begin(), g.end(), [](auto a, auto b) {
    if (a.first != b.first) {
      return a.first > b.first;
    }
    return a.second > b.second;
  });
  if (straight && flush) {
    return {8, shigh};
  }
  if (g[0].first == 4) {
    return {7, g[0].second, g[1].second};
  }
  if (g[0].first == 3 && g[1].first == 2) {
    return {6, g[0].second, g[1].second};
  }
  if (flush) {
    return {5, desc[0], desc[1], desc[2], desc[3], desc[4]};
  }
  if (straight) {
    return {4, shigh};
  }
  if (g[0].first == 3) {
    vector<ll> k;
    for (const auto& [c, v] : g) {
      if (c == 1) {
        k.emplace_back(v);
      }
    }
    sort(k.rbegin(), k.rend());
    return {3, g[0].second, k[0], k[1]};
  }
  if (g[0].first == 2 && g[1].first == 2) {
    ll p1{max(g[0].second, g[1].second)};
    ll p2{min(g[0].second, g[1].second)};
    return {2, p1, p2, g[2].second};
  }
  if (g[0].first == 2) {
    vector<ll> k;
    for (const auto& [c, v] : g) {
      if (c == 1) {
        k.emplace_back(v);
      }
    }
    sort(k.rbegin(), k.rend());
    return {1, g[0].second, k[0], k[1], k[2]};
  }
  return {0, desc[0], desc[1], desc[2], desc[3], desc[4]};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ifstream is("0054_poker.txt");
  ll ans{};
  string c[10];
  while (is >> c[0]) {
    for (ll i{1}; i < 10; ++i) {
      is >> c[i];
    }
    array<string, 5> a, b;
    for (ll i{}; i < 5; ++i) {
      a[i] = c[i];
    }
    for (ll i{}; i < 5; ++i) {
      b[i] = c[i + 5];
    }
    ans += score(a) > score(b);
  }
  is.close();
  cout << ans << '\n';
}
