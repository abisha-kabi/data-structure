#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX]; 
int in_degree[MAX]; 
int numVertices;   
void add_edge(int u, int v) {
    adj[u][v] = 1;
    in_degree[v]++;
}
void topological_sort() {
    int queue[MAX], front = 0, rear = 0;
    int topo_order[MAX];
    int visited_nodes = 0;
    for (int i = 0; i < numVertices; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int node = queue[front++];
        topo_order[visited_nodes++] = node;
        for (int i = 0; i < numVertices; i++) {
            if (adj[node][i]) {
                in_degree[i]--;
                if (in_degree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }
    if (visited_nodes != numVertices) {
        printf("The graph has a cycle or is invalid for topological sorting.\n");
    } else {
        printf("Topological Sort Order: ");
        for (int i = 0; i < numVertices; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int numEdges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adj[i][j] = 0;
        }
        in_degree[i] = 0;
    }
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    topological_sort();

    return 0;
}

