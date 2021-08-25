#include <stdio.h>
int main(void)
{
	int A,B;
	int m;
	int data[30];
	int value = 0;
	int set = 1;
	int answer[205];
	int index = 0;
	scanf("%d %d",&A,&B); // A진법과 B진법 
	scanf("%d",&m); // A진법으로 이루어진 m자리의 수 
	
	for(int i=0; i<m; i++)
	{
		scanf("%d",&data[i]);
	}
	
	for(int i=m-1; i>=0; i--) // A진법을 10진법으로 변경 
	{
		value += (set * data[i]);
		set *= A;
	}
	
	while(value > 0) // B진법으로 변경 
	{
		answer[index] = value % B;
		value /= B;
		index++;
	}
	
	for(int i=index-1; i>=0; i--) // B진법으로 변경한 자릿수 출력 
	{
		printf("%d ",answer[i]);
	}
}
