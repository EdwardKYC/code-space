#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef long long ll;
int n , m;
int dx[4] = {1 , -1 , 0 , 0};
int dy[4] = {0 , 0 , 1 , -1};
char dc[4] = {'D' , 'U' , 'R' , 'L'};
typedef struct path {
    bool find;
    int x , y;
    int move;
    char *path;
}p;
p init() {
    p path;
    path.x = 0;
    path.y = 0;
    path.find = false;
    path.move = 0;
    path.path = (char *)malloc(n * m * sizeof(char));
    path.path[0] = '\0';
    return path;
}
p go(char **map , p path , p end) {
    p queue[200000];
    int f = 0 , r = 0;  
    queue[r++] = path;
    while (r > f) {
        p temp = queue[f++];
        if (temp.x == end.x && temp.y == end.y){
            temp.find = true;
            return temp;
        }
        for (int i = 0; i < 4; i++) {
            int nx = temp.x + dx[i];
            int ny = temp.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && (map[nx][ny] == '.'|| map[nx][ny] == 'B')){
                p next = temp;
                next.x = nx;
                next.y = ny;
                next.path[temp.move] = dc[i];
                next.move = temp.move + 1;
                next.path[next.move] = '\0';
                queue[r++] = next;
                map[nx][ny] = '#';
            }
        }
    }
    
    return path;
}

p bfs(char **map) {
    p ans = init();
    p end = init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'A'){
                ans.x = i; ans.y = j;
            }
            if (map[i][j] == 'B'){
                end.x = i; end.y = j;
            }
        }
    }
    
    return go(map , ans , end);
}
int main() {

    scanf("%d %d" , &n , &m);
    char **map = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        map[i] = (char *) malloc(m * sizeof(char));
    }
    char *c = (char *) malloc(m+1 * sizeof(char));
    for (int i = 0; i < n; i++) {
        scanf("%s" , c);
        for (int j = 0; j < m; j++) {
            map[i][j] = c[j];
        }
    }
    p ans = bfs(map);
    if (!ans.find) printf("NO");
    else {
        printf("YES\n%d\n%s\n" , ans.move , ans.path);
    }
    for (int i = 0; i < n; i++) {
        free(map[i]);
    }
    free(map);
    free(ans.path);
    return 0;
}