#include <stdio.h>
int main(void)
{
	int n;
	int i,j;
	scanf("%d",&n);

	for(i = 1; i <= n; i++) // 1부터 n번째 줄까지 반복.
	{
		for(int j = 1; j <= i; j++) 
		{
			printf("*"); // i번째 줄에 i개 만큼의 별이 출력되어야 함.
		}
		printf("\n");
	}
}

