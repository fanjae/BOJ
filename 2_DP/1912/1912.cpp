#include <stdio.h>
#include <algorithm>
using namespace std;
int data[100005];
int dp[100005]={0};

// dp[i] : i+1번째 수까지 연속으로 선택해서 구할 수 있는 합 중 가장 큰 합.
// dp[0] : 1번째 수까지 연속으로 선택해서 구할 수 있는 가장 큰 합. 
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
