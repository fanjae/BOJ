#include <stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++) // 1부터 n번째 줄까지 반복
    {
        for(j=n;j>=i;j--) // 첫번째 줄 기준으로 5개가 모두 출력(1줄 내려갈때마다 별의 출력 개수를 줄여야함)
        {
            printf("*");
        }
        printf("\n");
    }
}
