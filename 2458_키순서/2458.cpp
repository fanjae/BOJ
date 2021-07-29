#include <stdio.h>
#define INF 5000000
int data[505][505];
int main(void)
{
	int value[505]={0};
	int n;
	int m;
	int cnt = 0;
	scanf("%d %d",&n,&m);
	
	for(int i=1; i<=m; i++)
	{
		int start, end;
		scanf("%d %d",&start,&end);
		data[start][end] = 1;
		
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(data[i][j] == 0)
			{
				data[i][j] = INF;
			}
		}
	}
	
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(i == j)
				{
					data[i][j] = 0;
				}
				if(data[i][j] > data[i][k] + data[k][j])
				{
					data[i][j] = data[i][k] + data[k][j];	
				}
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(data[i][j] == INF)
			{
				data[i][j] = -1;
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i == j)
			{
				continue;
			}
			else
			{
				if(data[i][j] >= 1)
				{
					value[i]++;
					value[j]++;
				}
			}
		}
		
		if(value[i] == n)
		{
			cnt++;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(value[i] == n-1)
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
}
