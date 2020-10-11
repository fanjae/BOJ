#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            printf(" ");
        }
        if(i >= 2 && i <= n - 1)
        {
        	printf("*");
        	for(int j=1; j<2*(i-1); j++)
        	{
        		printf(" ");
        	}
        	printf("*");
        }
	else
	{
		for(int j=1; j<=2*i-1; j++)
		{
			printf("*");
		}
	}
        printf("\n");
    }
}
