#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 1000
#define MAX_NODES 1000

typedef struct Edge
{
    int u, v;   // 两个端点
    int weight; // 权重
} Edge;

// 全局变量
Edge edges[MAX_EDGES]; // 边列表
int parent[MAX_NODES]; // 并查集父节点
int rank[MAX_NODES];   // 并查集秩
int numEdges = 0;      // 边的总数
int numNodes = 0;      // 节点总数

// 并查集相关操作
void initUnionFind(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]); // 路径压缩
    }
    return parent[x];
}

void unionSets(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
    {
        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// 比较函数，用于对边按权重排序
int compareEdges(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// Kruskal's Algorithm
void kruskal()
{
    // 排序边
    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    // 初始化并查集
    initUnionFind(numNodes);

    int mstWeight = 0;
    int mstEdges = 0;

    printf("Edges in the MST:\n");
    for (int i = 0; i < numEdges && mstEdges < numNodes - 1; i++)
    {
        Edge e = edges[i];
        if (find(e.u) != find(e.v))
        {
            unionSets(e.u, e.v);
            mstWeight += e.weight;
            mstEdges++;
            printf("Edge (%d, %d) with weight %d\n", e.u, e.v, e.weight);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

// 主函数
int main()
{
    // 输入图
    printf("Enter the number of nodes and edges:\n");
    scanf("%d %d", &numNodes, &numEdges);

    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < numEdges; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // 运行 Kruskal's Algorithm
    kruskal();

    return 0;
}
