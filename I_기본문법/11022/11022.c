#include <stdio.h>
int main(void)
{
	int i=1;
	int n;
	scanf("%d",&n);
	
	while(i <= n) // i�� n �����϶� ���� ����. 
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d + %d = %d\n",i,a,b,a+b);
		
		i++; // i�� �������� ������ while�� ������ �����Ƿ� i ���� 
	}
}
	
