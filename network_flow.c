#include <stdio.h>
int min(int a, int b) {
return (a < b) ? a : b;
}
int main() {
int n, i, j, s, t;
int cap[10][10], flow = 0;
printf("Enter number of vertices: ");
scanf("%d", &n);
printf("Enter capacity matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
scanf("%d", &cap[i][j]);
printf("Enter source and sink: ");
scanf("%d %d", &s, &t);
for (i = 0; i < n; i++) {
int f = min(cap[s][i], cap[i][t]);
flow += f;
}
printf("Maximum flow: %d\n", flow);
return 0;
}