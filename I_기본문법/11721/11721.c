#include <stdio.h>
#include <string.h>
int main()
{
	char data[105];
	int i,len;
	scanf("%s",data);
	
	len = strlen(data); // 문자열의 길이를 구해주는 함수. 
	for(i=0; i<len; i++)
	{
		printf("%c",data[i]);
		if(i % 10 == 9) // i를 10으로 나눈 나머지가 9이면 10번째 입력이됨(0,1,2,3,4,5,6,7,8,9)
		{
			printf("\n");
		}
	}
}
