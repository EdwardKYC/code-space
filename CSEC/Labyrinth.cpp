#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

struct path
{
    int x, y;
    vector<string> p;
};

void bfs(vector<vector<string>> &mp) {
    int n = mp.size();
    int m = mp[0].size();
    queue<path> q;
    q.push({0, 0});
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty())
    {
       
        q.pop();
        int x , y;
        

        cout << "Visiting: " << mp[x][y] << " at (" << x << ", " << y << ")\n";

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<string>> mp(n, vector<string> (m));
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }
    bfs(mp);
    return 0;
}