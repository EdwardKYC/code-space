#include <stdio.h>
#include <stdlib.h>
int adj[100][100];        
int visit[100];        
int queue[100];           
int i = 0, q_idx = -1;
void bfs(int star, int n)
{
    
    visit[star] = 1;
    queue[++q_idx] = star;
    while (i <= q_idx)
    {
        int idx = queue[i++];
        printf("%d ", idx + 1);

        for (int j = 0; j < n; j++)
        {
            if (adj[idx][j] == 1 && !visit[j])
            {
                visit[j] = 1;
                queue[++q_idx] = j;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    bfs(0, n);
    return 0;
}
