/* 
https://www.acmicpc.net
Problem ID : 11441
Prefix Sum
*/
#include <stdio.h>
int main(void)
{
	int n,T;
	int data[100005]={0};
	int sum[100005];
	
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&data[i]);
		sum[i] = data[i] + sum[i-1];
	}
	
	scanf("%d",&T);
	while(T--)
	{
		int x, y;
		scanf("%d %d",&x,&y);
		
		printf("%d\n",sum[y]-sum[x-1]);
	}
}
	
