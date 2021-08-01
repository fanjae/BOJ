#include <stdio.h>
int main(void)
{
	int a,b;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d,%d",&a,&b); // scanf의 특징상 입력받은 데이터의 서식을 지정할 수 있다. 
		printf("%d\n",a+b);	
	}
}
	
