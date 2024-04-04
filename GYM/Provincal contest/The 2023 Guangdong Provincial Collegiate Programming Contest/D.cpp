#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int m, n;
  cin >> n >> m;
  vector<int> improve(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    sum += a;
    improve[i] = b - a; // 没有邻居的幸福指数提升
  }
  sort(improve.begin(), improve.end(), greater<int>());
  vector<int> pre(n + 1);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + improve[i];
  }
  if (n == 1) {
    cout << sum + improve[0] << '\n';
    return;
  }
  int maxn = min(m, 2 * n - 1) - n;
  int ans = sum;
  for (int i = 0; i <= maxn; i++) {
    if (i != n - 1) {
      ans = max(ans, sum + pre[i]);
    } else {
      ans = max(ans, sum + pre[i + 1]);
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}