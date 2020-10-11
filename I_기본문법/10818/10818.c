#include <stdio.h>
int main(void)
{
	int min = 0;
	int max = 0;
	int i,n;
	scanf("%d",&n);

	for(i=1; i<=n; i++)
	{
		int data;
		scanf("%d",&data);
		if(i == 1) // 첫번째 값을 임의로 최소값, 최대값으로 지정.
		{
			max = data;
			min = data;
		}
		else
		{
			if(max < data) // data가 max보다 큰 경우
			{
				max = data; // max에 data를 넣음.
			}
			if(min > data) // data가 min보다 작은 경우
			{
				min = data; // min에 data를 넣음
			}
		}
	}
	printf("%d %d",min,max);
}

