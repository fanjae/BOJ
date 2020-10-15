#include <stdio.h>
#include <algorithm>

using namespace std;
int data[1005][1005]={0};
int dp[1005][1005] ={0};
// dp[n][0] : n��° ���� ���������� ĥ������ �ּ� ���
// dp[n][1] : n��° ���� �ʷ����� ĥ������ �ּ� ���
// dp[n][2] : n��° ���� �Ķ����� ĥ������ �ּ� ��� 
int main(void)
{
	int i,j;
	int n;
	int min_value;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=3; j++)
		{
			scanf("%d",&data[i][j]);
			if(i == 1)
			{
				dp[i][j] = data[i][j];
			}
		}
	}

	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=3; j++)
		{
			if(j == 1) // i��° ���� ������ ����������, ���� ���� �ʷ� Ȥ�� �Ķ��� �����ؾ��Ѵ�. (�̶� ���� ���� dp[i-1][2]�� dp[i-1][3]�� ���) 
			{	
				dp[i][j] = min(dp[i-1][2]+data[i][j],dp[i-1][3]+data[i][j]); 
			}
			if(j == 2) // // i��° ���� �ʷ��� ����������, ���� ���� ���� Ȥ�� �Ķ��� �����ؾ��Ѵ�. (�̶� ���� ���� dp[i-1][1]�� dp[i-1][3]�� ���) 
			{
				dp[i][j] = min(dp[i-1][1]+data[i][j],dp[i-1][3]+data[i][j]);
			}
			if(j == 3) // i��° ���� �Ķ��� ����������, ���� ���� ���� Ȥ�� �ʷ��� �����ؾ��Ѵ�. (�̶� ���� ���� dp[i-1][1]�� dp[i-1][2]�� ���) 
			{
				dp[i][j] = min(dp[i-1][1]+data[i][j],dp[i-1][2]+data[i][j]);
			}
		}
	}
	min_value = dp[n][1];
	for(int i=1; i<=3; i++)
	{
		min_value = min(min_value,dp[n][i]);
	}
	printf("%d\n",min_value);

}		
