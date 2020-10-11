#include <stdio.h>
int main(void)
{
	int a,b;
	while( scanf("%d %d",&a,&b) != EOF) // 테스트 케이스 개수 주어지지 않음. EOF가 입력될때 까지 계속 입력 받음.
	{
		printf("%d\n",a+b);
	}
}
