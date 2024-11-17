#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

// Simple array stack
int stack[MAX_NODES];
int top = -1;

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Push operation
void push(int value) {
    if (top == MAX_NODES - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Depth-First Search (DFS) on graph using adjacency matrix
void dfs(int graph[MAX_NODES][MAX_NODES], int n, int start) {
    bool visited[MAX_NODES] = {false};

    push(start);
    visited[start] = true;

    while (!isEmpty()) {
        int current = pop();
        printf("%d ", current);

        for (int i = n - 1; i >= 0; i--) {
            if (graph[current][i] && !visited[i]) {
                push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n, e;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    int graph[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (format: u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Assuming undirected graph
    }

    int start;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal starting from node %d: ", start);
    dfs(graph, n, start);
    printf("\n");

    return 0;
}
