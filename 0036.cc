#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static bool is_palindrome(const string& s) {
  ll n(s.size());
  ll l{}, r{n - 1};
  while (l < r) {
    if (s[l] != s[r]) {
      return false;
    }
    ++l;
    --r;
  }
  return true;
}

static string to_binary_str(ll n) {
  string s;
  while (n) {
    s.push_back(n % 2 + '0');
    n /= 2;
  }
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll ans{};
  for (ll i{1}; i < 1000000; ++i) {
    if (is_palindrome(to_string(i)) && is_palindrome(to_binary_str(i))) {
      ans += i;
    }
  }
  cout << ans << '\n';
}
