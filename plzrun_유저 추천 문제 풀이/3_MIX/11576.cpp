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
	scanf("%d %d",&A,&B); // A������ B���� 
	scanf("%d",&m); // A�������� �̷���� m�ڸ��� �� 
	
	for(int i=0; i<m; i++)
	{
		scanf("%d",&data[i]);
	}
	
	for(int i=m-1; i>=0; i--) // A������ 10�������� ���� 
	{
		value += (set * data[i]);
		set *= A;
	}
	
	while(value > 0) // B�������� ���� 
	{
		answer[index] = value % B;
		value /= B;
		index++;
	}
	
	for(int i=index-1; i>=0; i--) // B�������� ������ �ڸ��� ��� 
	{
		printf("%d ",answer[i]);
	}
}
