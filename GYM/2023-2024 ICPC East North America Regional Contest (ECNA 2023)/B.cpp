#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  // k = 100 mn = 2000 2e5 的 dp
  // dp[i][j] 表示只使用 i 个基站，连接 j 个城市的最小花费
  int n, m, k;
  double s;
  cin >> n >> m >> k >> s;
  vector<double> a(n + m);
  for (int i = 0; i < n + m; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  vector<double> pre(n + m + 1), preSquare(n + m + 1);
  for (int i = 0; i < n + m; i++) {
    pre[i + 1] = pre[i] + a[i];
    preSquare[i + 1] = preSquare[i] + a[i] * a[i];
  }

  auto getCost = [&](int l, int r) {
    double sum = pre[r] - pre[l - 1];
    double sumSquare = preSquare[r] - preSquare[l - 1];
    double n = r - l + 1, x = sum / n;
    return n * x * x - 2 * x * sum + sumSquare;
  };

  vector<vector<double>> dp(k + 1, vector<double>(n + m + 1, 1e18));
  for (int i = 1; i <= n + m; i++) {
    dp[1][i] = getCost(1, i); // 初始化单基站，单基站管理到 i 个城市的花费
  }
  for (int i = 2; i <= k; i++) {             // 枚举基站
    for (int l = 1; l <= n + m; l++) {        // 管理起始点
      for (int r = l - 1; r <= n + m; r++) { // 管理终点
        dp[i][r] = min(dp[i][r], dp[i - 1][l - 1] + getCost(l, r));
      }
    }
  }
  double add = (s / 2) * (s / 2) * (n + m);
  cout << fixed << setprecision(10) << dp[k][n + m] + add << '\n';
}