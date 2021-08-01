#include <stdio.h>
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) // T가 5인경우, 5,4,3,2,1만큼 반복 T가 0이 되면 이 반복문이 종료
	{
		int a,b;
		scanf("%d %d",&a,&b); 
		printf("%d\n",a+b);
	}
}
