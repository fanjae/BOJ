#include <stdio.h>
#include <algorithm>
long long int dp[505][505];
int data[505][505];

using namespace std; 

// dp[i][j] = �밢������ ���� Ȥ�� �������� �̾����� ���ü� �ִ� �ִ밪.
// dp[i][1] = ������ �ڽ��� �밢���� ����(�迭������ ���� ���� �̾ƿ� �� ����) 
int main(void)
{
	int n;
	long long max_value = 0;
	scanf("%d",&n);
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			scanf("%lld",&data[i][j]);
		}
	}
	
	dp[1][1] = data[1][1];
	for(int i=2; i<=n; i++) // �ڽ��� ������ �ڽ��� ���� �� �ִ� �ִ밪. 
	{
		dp[i][1] = dp[i-1][1] + data[i][1];
	}


	for(int i=2; i<=n; i++)
	{
		for(int j=2; j<=i; j++)
		{
			dp[i][j] = max(data[i][j]+dp[i-1][j-1],data[i][j]+dp[i-1][j]); // �밢���� ���� Ȥ�� �밢���� ������ �������� �ִ밪�� ��� 
			if(i == n)
			{
				max_value = max(max_value,dp[i][j]);
			}
		}
	}
	printf("%lld\n",max_value);
}
		
