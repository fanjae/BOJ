/* 
https://www.acmicpc.net
Problem ID : 6137
Two Pointers
*/
#include <stdio.h>
int main(void)
{
	char data[5005];
	int n;
	int list_len = 0;
	int print = 0;
	int start, end;
	scanf("%d",&n);
	getchar();
	for(int i=0; i<n; i++)
	{
		scanf("%c",&data[i]);
		getchar();
	}
	start = 0;
	end = n - 1;
	
	while(start <= end)
	{
		bool left = false;
		for(int i=0; i+start <= end; i++) // 가장 앞 문자와 가장 뒤 문자 중 하나를 추가하기 위해 같은 경우도 고려 필요함. 
		{
			if(data[i+start] < data[end-i]) // 왼쪽이 사전 상 앞으로 오면 왼쪽 값 추가 
			{
				left = true;
				break;
			}
			else if(data[i+start] > data[end-i]) // 오른쪽이 사전상 앞으로 오면 오른쪽 값 추가 
			{
				left = false;
				break;
			}		
		}
		if(left) // 왼쪽이었던 경우 왼쪽 문자 출력 
		{
			printf("%c",data[start]); 
			start++;
		}
		else // 오른쪽이었던 경우 오른쪽 문자 출력 
		{
			printf("%c",data[end]);
			end--;
		}
		
		print++;
		
		if(print == 80) // 80글자마다 새줄 문자 출력 필요. 
		{
			print = 0;
			printf("\n");
		}	
	}
	if(print != 0) // 80글자 이하로 끝난 경우에도 새줄 문자 출력 필요. 
	{
		printf("\n");
	}

}
