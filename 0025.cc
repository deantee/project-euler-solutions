#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string add(const string& a, const string& b) {
  string ans;
  int carry{};
  int n(a.size()), m(b.size());
  for (int i{}; i < n || i < m || carry; ++i) {
    carry += (i < n ? a[i] - '0' : 0) + (i < m ? b[i] - '0' : 0);
    ans.push_back(carry % 10 + '0');
    carry /= 10;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string a{"0"}, b{"1"};
  int idx{};
  while (a.size() < 1000) {
    string c{add(a, b)};
    a = b;
    b = c;
    ++idx;
  }
  cout << idx << '\n';
}
