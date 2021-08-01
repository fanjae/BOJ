#include <stdio.h>
int main(void)
{
	int a,b;
	while(1) // 계속 입력을 받는다. (while은 True일때 반복)
	{
		scanf("%d %d",&a,&b);

		if(a == 0 && b == 0)
		{
			break;
		}
		printf("%d",a+b);
	}
}
