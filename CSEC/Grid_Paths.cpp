#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'D', 'U', 'L', 'R'};
int ans = 0;
void dfs(int x , int y , string &s , string target) {
    for (int i = 0; i < 4; i++) {
        if (x+dx[i] < 7 || x+dx[i] >= 0 || y+dy[i] < 7 || y+dy[i] >= 0) {
            if 
            dfs(x+dx[i] , x+dx[i] >= 0 , s , target);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string target[48] , s[48];
    cin >> target;

    dfs(0 , 0 , s , target);
    return 0;
}
