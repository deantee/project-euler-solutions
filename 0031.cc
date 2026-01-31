#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<ll> opts{1, 2, 5, 10, 20, 50, 100, 200};
  vector<ll> dp(200 + 1);
  dp[0] = 1;
  for (ll opt : opts) {
    for (ll i{opt}; i <= 200; ++i) {
      dp[i] += dp[i - opt];
    }
  }
  cout << dp[200] << '\n';
}
