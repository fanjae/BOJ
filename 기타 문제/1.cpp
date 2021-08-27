#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

bool isCreate[999999]={0};
using namespace std;

int solution(vector<vector<int>> dice) {
    int answer = 0;
    int arr[5]={0};
    
    int dice_size = dice.size();
    
  	for(int i=0; i<dice_size; i++)
	{
		for(int j=0; j<dice_size; j++)
		{
			arr[j] = j;
		}
		do
		{
			vector <int> target;
			for(int k=0; k<=i; k++)
			{
				target.push_back(arr[k]);
			}
			int sum = 0;
			int cal = 1;
			int target_size = target.size();

			if(target_size == 1)
			{
				for(int k=0; k<6; k++)
				{
					sum = 0;
					if(dice[target[0]][k] == 0)
					{
						continue;
					}
					else
					{
						sum = sum + dice[target[0]][k];
					}
					isCreate[sum] = true;
				}
			}
			if(target_size == 2)
			{
				
				for(int k=0; k<6; k++)
				{
					sum = 0;
					for(int l=0; l<6; l++)
					{
						if(dice[target[0]][k] == 0)
						{
							continue;
						}
						else
						{
							sum = dice[target[0]][k] * 10 + dice[target[1]][l];
						}
						isCreate[sum] = true;
					}
				}
			}
			if(target_size == 3)
			{
				for(int k=0; k<6; k++)
				{
					sum = 0;
					for(int l=0; l<6; l++)
					{
						for(int m=0; m<6; m++)
						{
							if(dice[target[0]][k] == 0)
							{
								continue;
							}
							else
							{
								sum = dice[target[0]][k] * 100 + dice[target[1]][l] * 10 + dice[target[2]][m];
							}
							isCreate[sum] = true;
						}
					}
				}
			}
			if(target_size == 4)
			{
				for(int k=0; k<6; k++)
				{
					sum = 0;
					for(int l=0; l<6; l++)
					{
						for(int m=0; m<6; m++)
						{
							for(int n=0; n<6; n++)
							{
								if(dice[target[0]][k] == 0)
								{
									continue;
								}
								else
								{
									sum = dice[target[0]][k] * 1000 + dice[target[1]][l] * 100 + dice[target[2]][m] * 10 + dice[target[3]][n];
								}
								isCreate[sum] = true;
							}
						}
					}
				}
			}
		}while(next_permutation(arr,arr+dice_size));
	}  

	for(int i=1; i<=999999; i++)
	{
		if(!isCreate[i])
		{
			answer = i;
			break;
		}
	}
    return answer;
}

int main(void)
{
	vector <vector <int>> dice = {{1,6,2,5,3,4},{9,9,1,0,7,8}};
	cout << solution(dice);
}
