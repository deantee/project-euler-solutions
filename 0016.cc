#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto double_string = [](string x) -> string {
    ll n(x.size());
    string res;
    for (ll i{}, carry{}; i < n || carry; ++i, carry /= 10) {
      carry += (i < n ? x[i] - '0' : 0) * 2;
      res.push_back(carry % 10 + '0');
    }
    return res;
  };
  string x = "1";
  for (ll i{}; i < 1000; ++i) {
    x = double_string(x);
  }
  ll ans{};
  for (char ch : x) {
    ans += ch - '0';
  }
  cout << ans << '\n';
}
