#include <stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(k=1;k<i;k++) // i번째 줄에 i-1개의 공백 출력
        {
            printf(" ");
        }
        for(j=n;j>=i;j--)
        {
            printf("*");
        }
        printf("\n");
    }
}
