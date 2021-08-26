/* 
https://www.acmicpc.net
Problem ID : 2643
DP(Dynamic Programming)
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
struct paper
{
	int x;
	int y;
};

struct paper data[105]; // 종이의 크기 
int dp[105]; // dp[x] : x번째에서 쌓을 수 있는 최대 색종이 장수 
int ans;
int n;
bool compare(const struct paper &dat1, const struct paper &dat2) // 정렬 비교 함수 
{
	if(dat1.x != dat2.x)
	{
		return dat1.x > dat2.x;
	}
	else
	{
		return dat1.y > dat2.y;
	}
}

int cal(int index)
{
	int &ret = dp[index];
	if(ret != -1)
	{
		return ret;
	}
	
	int value = 0;
	for(int i=0; i<=n; i++)
	{
		if(index == i) // 자기 자신과 비교하지 않음 
		{
			continue;
		}
		
		if((data[index].x >= data[i].x && data[index].y >= data[i].y) || (data[index].x >= data[i].y && data[index].y >= data[i].x)) // 위에 종이를 쌓을 수 있는가?  
		{
			value = max(value,cal(i));
		}
	}
	if(value == 0) // 1개도 쌓을 수 없는 경우(본인만 쌓을 수 있음) => 1 
	{
		return ret = 1;
	}
	else // 1개 이상 쌓을 수 있는 경우 (본인을 포함하여 +1을 리턴) 
	{
		return ret = value + 1;
	}
}
int main(void)
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	data[0].x = 1000; // 임의로 1000짜리 종이를 깔았다고 가정함. 
	data[0].y = 1000;
	
	for(int i=1; i<=n; i++) 
	{
		int x, y;
		scanf("%d %d",&x,&y);
		data[i].x = x;
		data[i].y = y;
	}
	
	sort(data,data+n+1,compare); // 내림차순 정렬 
	cal(0);
	
	for(int i=1; i<=n; i++)
	{
		ans = max(ans,dp[i]);
	}
	printf("%d\n",ans); 
}

	
		
