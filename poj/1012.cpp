#include <stdio.h> 
#include<stdlib.h>
main() 
{ 
int n, m, i, s=0; 
printf("N="); scanf("%d", &n); 
printf("M="); scanf("%d", &m); 
for(i=2; i<=n; i++) s=(s+m)%i; 
printf("The winner is %d\n", s+1); 
system("pause");
} 

