#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin(), x.end()
const int mod = 1e9 + 7;

struct way {
    int x, y; 
    char from;   
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char dir[] = {'D', 'U', 'R', 'L'};
    int sx, sy, ex, ey;
    vector<vector<char>> mp(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<way>> move(n, vector<way>(m, {-1, -1, 0}));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'A') {
                sx = i; sy = j;
            } else if (mp[i][j] == 'B') {
                ex = i; ey = j;
            }
        }
    }
    queue<pii> q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;

    while (!q.empty()) {
        pii current = q.front();
        q.pop();
        int x = current.first, y = current.second;
        if (x == ex && y == ey) break;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && mp[nx][ny] != '#') {
                visited[nx][ny] = true;
                move[nx][ny] = {x, y, dir[k]};
                q.push(make_pair(nx, ny));
            }
        }
    }

    if (!visited[ex][ey]) {
        cout << "NO\n";
        return 0;
    }

    vector<char> path;
    int x = ex;
    int y = ey;

    while (x != sx || y != sy) {
        path.push_back(move[x][y].from);
        int px = move[x][y].x, py = move[x][y].y;
        x = px;
        y = py;
    }

    reverse(path.begin(), path.end());
    cout << "YES\n";
    cout << path.size() << '\n';
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
    }
    cout << '\n';

    return 0;
}
