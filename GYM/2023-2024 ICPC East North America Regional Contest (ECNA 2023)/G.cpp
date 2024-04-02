#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int sx[] = {1, 1, -1, -1};
int sy[] = {1, -1, -1, 1};

struct point{
    int x, y;
    point(){};
    point(int x, int y):x(x),y(y){}
    bool operator<(const point& other) const{
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

struct st{
    point p;
    int t;
    st(point p, int t):p(p),t(t){}
    bool operator<(const st& other) const{
        if (t != other.t) {
            return t < other.t;
        }
        return p < other.p;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    vector<point> mp(n);
    set<point> trees;
    for (int i = 0; i < n; i++) {
        cin >> mp[i].x >> mp[i].y;
        trees.insert({mp[i].x, mp[i].y});
    }

    vector<point> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].x >> b[i].y;
    }
    vector<vector<point>> a(4, vector<point>(m));
    vector<set<point>> robTree(4);

    set<st> done;

    for (int t = 0; t < 4; t++) {
        for (int j = 0; j < m; j++) {
            a[t][j] = {b[j].x * sx[t], b[j].y * sy[t]};
            if (sx[t] * sy[t] == -1) swap(a[t][j].x, a[t][j].y);
            robTree[t].insert(a[t][j]);
        }
    }

    point ans = {INF, INF};
    for (int i = 0; i < n; i++) {
        point ori = mp[i];

        for (int t = 0; t < 4; t++) {
            int ox = ori.x - a[t][0].x, oy = ori.y - a[t][0].y;
            point rob = {ox, oy};

            if (trees.count(rob)) continue;

            if (done.count({rob, t})) continue;
            done.insert({rob, t});

            bool match = true;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                point tt = {mp[j].x - rob.x, mp[j].y - rob.y};
                if (abs(tt.x) + abs(tt.y) <= r && !robTree[t].count(tt)) {
                    match = false;
                    break;
                }
                if (abs(tt.x) + abs(tt.y) <= r) cnt++;
            }
            if (cnt != robTree[t].size()) {
                match = false;
            }
            if (match && ans.x == INF && ans.y == INF) {
                ans = rob;
            } else if (match && ans.x != INF && ans.y != INF){
                cout << "Ambiguous\n";
                return 0;
            }
        }
    }
    if (ans.x == INF && ans.y == INF) {
        cout << "Impossible\n";
    } else {
        cout << ans.x << " " << ans.y << '\n';
    }
}
