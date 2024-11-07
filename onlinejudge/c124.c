#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
ll L , R , C;
typedef struct point { 
    int i;
    int j;
    int k;
    int path;
}p;
int bfs(char ***maze, p start, p end) {
    int f = 0, r = 0;
    p queue[50000];
    queue[r++] = start;

    int di[] = {1, -1, 0, 0, 0, 0};  
    int dj[] = {0, 0, 1, -1, 0, 0};  
    int dk[] = {0, 0, 0, 0, 1, -1};  

    while (r > f) {
        p nowpoint = queue[f++];
        
        if (nowpoint.i == end.i && nowpoint.j == end.j && nowpoint.k == end.k)
            return nowpoint.path;

        for (int d = 0; d < 6; d++) {
            int ni = nowpoint.i + di[d];
            int nj = nowpoint.j + dj[d];
            int nk = nowpoint.k + dk[d];

            if (ni >= 0 && ni < L && nj >= 0 && nj < R && nk >= 0 && nk < C && maze[ni][nj][nk] != '#') {
                maze[ni][nj][nk] = '#'; 
                p nextpoint = {ni, nj, nk, nowpoint.path + 1};
                queue[r++] = nextpoint;
            }
        }
    }
    return -1;
}

int main() {

    p start , end;
    while (scanf("%lld %lld %lld" , &L , &R , &C)) {
        if (L == 0 && R == 0 && C == 0) break;
        char ***maze = (char ***)malloc(L * sizeof(char **));
        for (int i = 0; i < L; i++) {
            maze[i] = (char **)malloc(R * sizeof(char *));
            for (int j = 0; j < R; j++) {
                maze[i][j] = (char *)malloc(C * sizeof(char));
            }
        }
        char c[C+1];
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                scanf("%s" , c);
                for (int k = 0; k < C; k++) {
                    if (c[k] == 'S') {
                        start.i = i;
                        start.j = j;
                        start.k = k;
                        start.path = 0;
                    }
                    if (c[k] == 'E') {
                        end.i = i;
                        end.j = j;
                        end.k = k;
                    }
                    maze[i][j][k] = c[k];
                }
            }
        }
        int ans = bfs(maze, start, end);
        if (ans != -1) {
            printf("Escaped in %d minute(s).\n" , ans);
        }
        else printf("Trapped!\n");
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                free(maze[i][j]);
            }
            free(maze[i]);
        }
        free(maze);
    }
    return 0;
}   
