#include<stdio.h>
int main()
{
int w[10], p[10],n, i, j,cap,temp1;
float up[10], temp,pri=0.0;
printf("Enter the no of items");
scanf("%d",&n);
printf("Enter the weight of each items");
for(i=0;i<n;i++){scanf("%d",&w[i]);}
printf("Enter the price of each packets in a packed items");
for(i=0;i<n;i++){scanf("%d",&p[i]);}
printf("Enter the capacity of bin");
scanf("%d",&cap);
for(i=0;i<n;i++){up[i]=(1.0*p[i])/w[i]; }
for(i=0;i<n;i++)
{
for(j=i;j<n;j++)
{
if(up[i]<up[j])
{
temp=up[i];
up[i]=up[j];
up[j]=temp;
temp1=w[i];
w[i]=w[j];
w[j]=temp1;
}
}
}
for(i=0;i<n;i++)
{
if(w[i]<=cap)
{
cap=cap-w[i];
pri=w[i]*up[i]+pri;
}
else
{
pri=((1.0*cap)/w[i])*up[i] +pri;
cap=0;
}
}
printf("%f", pri);
return 0;}