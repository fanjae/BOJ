/* 
https://www.acmicpc.net
Problem ID : 1057
Math 
*/
#include <stdio.h>
int main(void)
{
	int n, kim, lim;
	int next_kim,next_lim;
	int round = 1;
	scanf("%d %d %d",&n,&kim,&lim);
	
	 // 서로 인접한 번호끼리 붙을 경우, N번이 승리했을때 그 N번은 다음번에 (n+1) /2 번 위치에서 붙는다. 
	next_kim = (kim + 1) / 2;
	next_lim = (lim + 1) / 2; 
	
	while(1)
	{
		if(next_kim == next_lim)
		{
			printf("%d\n",round);
			break;
		}
		next_kim = (next_kim + 1) / 2;
		next_lim = (next_lim + 1) / 2;
		
		round++;
	}
}
