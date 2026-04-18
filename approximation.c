#include <stdio.h>
int main() {
int n, i, j;
int graph[10][10], visited[10] = {0};
printf("Enter number of vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
scanf("%d", &graph[i][j]);
printf("Vertex Cover:\n");
for (i = 0; i < n; i++) {
for (j = i+1; j < n; j++) {
if (graph[i][j] && !visited[i] && !visited[j]) {
visited[i] = visited[j] = 1;
printf("%d %d\n", i, j);
}
}
}
return 0;
}