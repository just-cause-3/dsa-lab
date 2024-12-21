#include <stdio.h>
#include <stdlib.h>

void createGraph(int n, int a[10][10]) {
    printf("Enter the adjacency matrix (only 0s and 1s):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0 && a[i][j] != 1) {
                printf("Invalid input! Only 0s and 1s are allowed.\n");
                exit(1);
            }
        }
    }
}

void bfs(int a[10][10], int n, int source) {
    int visited[10] = {0}, queue[10], front = 0, rear = 0;
    printf("Reachable nodes from %d: ", source);
    
    visited[source] = 1; // Mark the source as visited
    queue[rear++] = source; // Enqueue the source

    while (front < rear) {
        int u = queue[front++]; // Dequeue
        printf("%d ", u); // Print the current node
        
        // Check all adjacent nodes
        for (int v = 0; v < n; v++) {
            if (a[u][v] == 1 && visited[v] == 0) { // If there's an edge and not visited
                visited[v] = 1; // Mark as visited
                queue[rear++] = v; // Enqueue
            }
        }
    }
    printf("\n");
}

void dfs(int a[10][10], int n, int visited[10], int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (a[v][i] && !visited[i]) {
            dfs(a, n, visited, i);
        }
    }
}

int main() {
    int a[10][10] = {0}, n = 0, choice, source;

    while (1) {
        printf("\n1: Create Graph\n2: BFS Reachability\n3: DFS Traversal\n4: Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes (max 10): ");
            scanf("%d", &n);
            if (n <= 0 || n > 10) {
                printf("Invalid number of nodes. Please enter a value between 1 and 10.\n");
                break;
            }
            createGraph(n, a);
            break;

        case 2:
            if (n == 0) {
                printf("Graph not created yet. Please create a graph first.\n");
                break;
            }
            printf("Enter source node (0 - %d): ", n - 1);
            scanf("%d", &source);
            if (source < 0 || source >= n) {
                printf("Invalid source node. Please enter a value between 0 and %d.\n", n - 1);
                break;
            }
            bfs(a, n, source);
            break;

        case 3:
            if (n == 0) {
                printf("Graph not created yet. Please create a graph first.\n");
                break;
            }
            int visited[10] = {0}; // Reset visited array for DFS
            printf("DFS Traversal starting from node 0:\n");
            dfs(a, n, visited, 0);
            printf("\n");
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
