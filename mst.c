#include <stdio.h>
#include <limits.h>
int main() {
int n, i, j, min, u, v;
int cost[10][10], visited[10] = {0};
printf("Enter number of vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
scanf("%d", &cost[i][j]);
visited[0] = 1;
printf("Edges in MST:\n");
for (i = 0; i < n-1; i++) {
min = INT_MAX;
for (u = 0; u < n; u++) {
if (visited[u]) {

for (v = 0; v < n; v++) {
if (!visited[v] && cost[u][v] < min) {
min = cost[u][v];
j = v;
}
}
}
}
printf("Edge cost: %d\n", min);
visited[j] = 1;
}
return 0;
}