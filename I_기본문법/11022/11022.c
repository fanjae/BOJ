#include <stdio.h>
int main(void)
{
	int i=1;
	int n;
	scanf("%d",&n);
	
	while(i <= n) // i가 n 이하일때 까지 동작. 
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d + %d = %d\n",i,a,b,a+b);
		
		i++; // i가 증가하지 않으면 while이 끝나지 않으므로 i 증가 
	}
}
	
