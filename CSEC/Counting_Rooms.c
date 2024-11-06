#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
typedef long long ll;
int n , m;
int dx[4] = {1 , -1 , 0 , 0};
int dy[4] = {0 , 0 , 1 , -1};
void filled(bool **map , int x , int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny]){
            map[nx][ny] = false;
            filled(map , nx , ny);
        }
    }
    return;
}
 
int bfs(bool **map) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j]) {
                ans++;
                filled(map , i , j);
            }
        }
    }
    return ans;
}
int main() {
    
    scanf("%d %d" , &n , &m);
    bool **map = (bool **) malloc(n * sizeof(bool *));
    for (int i = 0; i < n; i++) {
        map[i] = (bool *) malloc(m * sizeof(bool));
    }
    char *c = (char *) malloc(m+1 * sizeof(char));
    for (int i = 0; i < n; i++) {
        scanf("%s" , c);
        for (int j = 0; j < m; j++) {
            if (c[j] == '#') map[i][j] = false;
            else map[i][j] = true;
        }
    }
    int ans = bfs(map);
    printf("%d\n" , ans);
    return 0;
}