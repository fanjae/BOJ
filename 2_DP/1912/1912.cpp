#include <stdio.h>
#include <algorithm>
using namespace std;
int data[100005];
int dp[100005]={0};

// dp[i] : i+1��° ������ �������� �����ؼ� ���� �� �ִ� �� �� ���� ū ��.
// dp[0] : 1��° ������ �������� �����ؼ� ���� �� �ִ� ���� ū ��. 
int main()
{

	int result,n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&data[i]);
	}
	for(int i=0; i<n; i++)
	{
		dp[i] = data[i] > data[i] + dp[i-1] ? data[i] : data[i] + dp[i-1];
	}
	result = dp[0];
	for(int i=1; i<n; i++)
	{
		if(result < dp[i])
		{
			result = dp[i];
		}
	}
	printf("%d\n",result);
}
