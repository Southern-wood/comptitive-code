#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

struct st{
    pair<string, string> pss;
    int begin, n;
    bool operator<(const st& other) const {
        if (pss != other.pss) {
            return pss < other.pss;
        }
        if (begin != other.begin) {
            return begin < other.begin;
        }
        return n < other.n;
    }
    st(string s1, string s2, int begin, int n):pss({s1, s2}),begin(begin), n(n){}
};


map<st, int> cnt;

signed main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].size() != a[j].size()) continue;
            vector<int> diffIndex;
            for (int k = 0; k < a[i].size(); k++) {
                if (a[i][k] != a[j][k]) {
                    diffIndex.push_back(k);
                }
            }
            if (diffIndex.size() == 2 && diffIndex[0] + 1 == diffIndex[1]) {
                string s1 = "", s2 = "";
                s1 += a[i][diffIndex[0]], s1 += a[i][diffIndex[1]];
                s2 += a[j][diffIndex[0]], s2 += a[j][diffIndex[1]];
                if (s1 < s2) swap(s1, s2);
                cnt[st(s1, s2, diffIndex[0], a[i].size())]++;
            }
        }
    }

    int ans = 0;
    for (auto it : cnt) {
        if (it.second == 1) {
            ans++;
        }
    }
    cout << ans << '\n';


    return 0;
}