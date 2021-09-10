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
	
	 // ���� ������ ��ȣ���� ���� ���, N���� �¸������� �� N���� �������� (n+1) /2 �� ��ġ���� �ٴ´�. 
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
