/* 
https://www.acmicpc.net
Problem ID : 15683
Brute Force 
*/

#include <stdio.h>

struct CCTV
{
	int x;
	int y;
	int type;
};
int data[8][8];
int n,m;
int answer = 105; // 사각 지대의 최소 크기  
int cctv_count = 0; // cctv 개수 
int rotate[6]={0,4,2,4,4,1}; // 각 cctv별 회전 횟수 
CCTV cam[8]; // cctv별 정보 


void array_copy(int original_array[8][8], int target_array[8][8]) // 배열 복사 
{
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			target_array[i][j] = original_array[i][j];
		}
	}
}

void update(int direction, CCTV target_cam) 
{
	direction = direction % 4;
	if(direction == 0) // 북 
	{
		for(int i=target_cam.x-1; i>=0; i--)
		{
			if(data[i][target_cam.y] == 6)
			{
				break;
			}
			else
			{
				data[i][target_cam.y] = -1;
			}
		}
	}
	if(direction == 1) // 동
	{
		for(int i=target_cam.y+1; i<m; i++)
		{
			if(data[target_cam.x][i] == 6)
			{
				break;
			}
			else
			{
				data[target_cam.x][i] = -1;
			}
		}
	}
	if(direction == 2) // 남
	{
		for(int i=target_cam.x+1; i<n; i++)
		{
			if(data[i][target_cam.y] == 6)
			{
				break;
			}
			else
			{
				data[i][target_cam.y] = -1;
			}
		}
	}
	if(direction == 3) // 서
	{
		for(int i=target_cam.y-1; i>=0; i--)
		{
			if(data[target_cam.x][i] == 6)
			{
				break;
			}
			else
			{
				data[target_cam.x][i] = -1;
			}
		}
	}
}
void cctv_search(int cam_index)
{
	if(cam_index == cctv_count) // 모든 cctv에 대한 셋팅이 끝난 경우 
	{
		int temp_safe = 0;
		for(int i=0; i<8; i++)
		{
			for(int j=0; j<8; j++)
			{
				if(data[i][j] == 0) 
				{
					temp_safe++;	
				}
			}
		}
		if(answer > temp_safe) // 안전 지대 크기가 최소이면 저장 
		{
			answer = temp_safe;
		}
		return ;
	}
	
	int orignal[8][8];
	int cam_type = cam[cam_index].type;
	
	for(int i=0; i<rotate[cam_type]; i++)
	{
		array_copy(data,orignal);	
		if(cam_type == 1) // 1방향 CCTV 
		{
			update(i, cam[cam_index]);
		}
		if(cam_type == 2) // 2방향 반대 CCTV
		{
			update(i, cam[cam_index]);
			update(i+2, cam[cam_index]);
		}
		if(cam_type == 3) // 2방향 직각 CCTV
		{
			update(i, cam[cam_index]);
			update(i+1, cam[cam_index]);
		}
		if(cam_type == 4) // 3방향 CCTV
		{
			update(i, cam[cam_index]);
			update(i+1, cam[cam_index]);
			update(i+2, cam[cam_index]);
		}
		if(cam_type == 5) // 4방향 CCTV
		{
			update(i, cam[cam_index]);
			update(i+1, cam[cam_index]);
			update(i+2, cam[cam_index]);
			update(i+3, cam[cam_index]);
		}

		cctv_search(cam_index+1);
		
		// 모든 탐색이 끝난 이후 원래대로 되돌림 
		array_copy(orignal,data);
	}
}
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			data[i][j] = 6;
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d",&data[i][j]);
			if(data[i][j] != 0 && data[i][j] != 6) // 빈칸이나 벽이 아니면 cctv 정보 저장 
			{
				cam[cctv_count].x = i;
				cam[cctv_count].y = j;
				cam[cctv_count].type = data[i][j];
				cctv_count++;	
			}
		}
	}
	cctv_search(0);
	printf("%d\n",answer);
}
