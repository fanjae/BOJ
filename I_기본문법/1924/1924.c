#include <stdio.h>
int main()
{
	int day[12]={31,28,31,30,31,30,31,31,30,31,30,31}; // 1~12월까지의 일 개수 저장.
	int x=1,y=1;
	int mod=1;
	int sx,sy;
	scanf("%d %d",&sx,&sy); 
	while(sx > x || sy > y) 
	{
		if(sx == x && sy == y)
		{
			break;
		}
		y++; // Day(일) 증가
		if(y > day[x-1]) // 해당 월의 Day를 넘어갔으면 다시 1일로 초기화
		{
			y = 1;
			x++;
		}
		mod = (mod % 7) + 1; // 7일 나눈 나머지에 계속 누적 시킴.
	}
	switch(mod) // 누적시킨 나머지로 요일을 구함.
	{
		case 1:
		{
			printf("MON\n");
			break;
		}
		case 2:
		{
			printf("TUE\n");
			break;
		}
		case 3:
		{
			printf("WED\n");
		   break;
		}
		case 4:
		{
			printf("THU\n");
			break;
		}
		case 5:
		{
			printf("FRI\n");
			break;
		}
		case 6:
		{
			printf("SAT\n");
		   break;
		}
		case 7:
		{
			printf("SUN\n");
			break;
		}
	}
}
