#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string mul(const string& a, int b) {
  string ans;
  ll carry{};
  ll n(a.size());
  for (ll i{}; i < n || carry; ++i) {
    if (i < n) {
      carry += (a[i] - '0') * b;
    }
    ans.push_back(carry % 10 + '0');
    carry /= 10;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll ans{};
  for (ll a{1}; a < 100; ++a) {
    string str{"1"};
    for (ll b{}; b < 100; ++b) {
      ll sum{};
      for (ll c : str) {
        sum += c - '0';
      }
      ans = max(ans, sum);
      str = mul(str, a);
    }
  }
  cout << ans << '\n';
}
