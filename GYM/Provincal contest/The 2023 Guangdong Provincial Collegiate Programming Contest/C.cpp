#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    cnt += a[i].second;
  }
  cnt = cnt / 2;
  sort(a.begin(), a.end());
  int ans = 0;
  int p = 0, add = 0;
  while (p < n && add < cnt) {
    if (add + a[p].second <= cnt) {
      add += a[p].second;
      ans -= a[p].first * a[p].second;
    } else {
      ans -= a[p].first * (cnt - add);
      add = cnt;
    }
    p++;
  }
  p = n - 1, add = 0;
  while (p >= 0 && add < cnt) {
    if (add + a[p].second <= cnt) {
      add += a[p].second;
      ans += a[p].first * a[p].second;
    } else {
      ans += a[p].first * (cnt - add);
      add = cnt;
    }
    p--;
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