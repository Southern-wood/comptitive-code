#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int begin, end;
  cin >> begin;
  int n;
  cin >> n;
  set<int> st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert(x);
  }
  cin >> end;
  int ans = 0;
  for (int i = begin; i <= end; i++) {
    if (!st.count(i)) {
      ans++;
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