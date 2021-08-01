#include <stdio.h>
#include <stdio.h>
int main(void)
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++) // n번째 줄까지 별이 줄어듦
    {
        for(j=1;j<i;j++)
        {
            printf(" ");
        }
        for(j=1;j<=2*(n-i)+1;j++) // i번째 줄에 대해서 2*(n-i)+1개 만큼 별 출력
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=2;i<=n;i++) // n+1번째 줄부터 별이 늘어남
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        for(j=1;j<=i*2-1;j++) // n+1번째 줄에 대해서 2*i-1개 만큼씩 늘어남.
       {
            printf("*");
        }
        printf("\n");
    }
}
