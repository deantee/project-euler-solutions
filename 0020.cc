#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto add = [](const string& s, const string& t) -> string {
    int n(s.size()), m(t.size());
    string res;
    for (int i{}, carry{}; i < n || i < m || carry > 0; ++i, carry /= 10) {
      carry += (i < n ? s[i] - '0' : 0) + (i < m ? t[i] - '0' : 0);
      res.push_back(carry % 10 + '0');
    }
    return res;
  };
  auto mult = [add](const string& s, const string& t) -> string {
    auto helper = [](const string& s, ll c, ll offset) -> string {
      int n(s.size());
      string res(offset, '0');
      for (int i{}, carry{}; i < n || carry > 0; ++i, carry /= 10) {
        carry += i < n ? (s[i] - '0') * c : 0;
        res.push_back(carry % 10 + '0');
      }
      return res;
    };
    int n(s.size());
    string res;
    for (ll i{}; i < n; ++i) {
      res = add(res, helper(t, s[i] - '0', i));
    }
    return res;
  };
  string s{"1"};
  for (ll i{2}; i <= 100; ++i) {
    string t{to_string(i)};
    reverse(t.begin(), t.end());
    s = mult(s, t);
  }
  ll ans{};
  for (char ch : s) {
    ans += ch - '0';
  }
  cout << ans << '\n';
}
