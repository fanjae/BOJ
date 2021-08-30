/* 
https://www.acmicpc.net
Problem ID : 10823
MST (Minimum Spanning Tree)
*/

#include <stdio.h>
#include <algorithm>

using namespace std;
struct Node
{
	int x;
	int y;
	long long int value;
};

bool compare(struct Node &dat1, struct Node &dat2)
{
	return dat1.value < dat2.value;
}

int parent[1005];
Node data[1000005]; // N * N개까지 간선이 발생 

int find(int x) // 같은 부모를 가지는가 확인 
{
	if(parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);
	}
}
bool union_find(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if(x != y)
	{
		parent[y] = x;	
		return false;
	}
	else
	{
		return true;
	}	
}


int main(void)
{
	int n;
	int node_count=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		parent[i] = i;
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			long long int temp;
			scanf("%lld",&temp);
			if(i >= j) // Cij = Cji이므로, i >= j이면 확인할 필요X 
			{
				continue;
			}
			else
			{
				data[node_count].x = i;
				data[node_count].y = j;
				data[node_count].value = temp;
				node_count++;
			}
		}
	}
	
	sort(data,data+node_count,compare); // Cost가 가장 적은 순으로 정렬 
	long long int sum = 0;
	for(int i=0; i<node_count; i++)
	{
		if(union_find(data[i].x,data[i].y) == false) // x,y과 서로 연결되어있는가 확인후 연결안되어있으면 서로 연결 
		{
			sum += data[i].value;
		}
	}
	printf("%lld\n",sum);
}
