/* 
https://www.acmicpc.net
Problem ID : 12865
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
int weight[105];
int value[105];
int dp[105][100005]; 

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d",&weight[i],&value[i]);
	}
	
	// n : ������ ����
	// k : �ִ� ���� 
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<=k; j++)
		{
			dp[i][j] = dp[i-1][j]; // dp[i][j]�� ���� ���Կ��� ���������� ����� ������ ��Ƶд�. 
			if(j - weight[i] >= 0)
			{
				dp[i][j] = max(dp[i][j],value[i] + dp[i-1][j-weight[i]]);
				// ���� j���� ��������� ���� ��Ȳ. ��, (i-1)��° ��Ȳ��
				// �̹� ������ �������, ���� ��Ȳ����, ����� ������ �ִ� ��ġ ������ �����´�. 
			}
		}
	}

	printf("%d\n",dp[n][k]);
				
}
