#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define black 0
#define white 1
#define empty 2
int* computerAI_one();
//void chessBoard_init();
int connect6();
void win3D_init();
void mywin_init();
int* computerAI_two();
int wins[19][19][1000];
int mywin[924] = {0};
int computerwin[924] = {0};
int board[19][19];
int count = 0;
void main()
{
	/*while (1)
	{*/
		connect6();
	/*}*/
	
	
}
typedef struct _Point {
	int x, y;

}Point;

typedef struct _Step {
	Point First, Second;
	int value;
}Step;


//void chessBoard_init()//棋盘初始化函数
//{
//	for (int i = 0; i < 19; i++)
//	{
//		for (int j = 0; j < 19; j++)
//		{
//			board[i][j] = empty;
//		}
//	}
//}

void win3D_init() //赢点位置1，便于计分，同时统计所有赢法种数
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				wins[i][j+k][count] = 1;
			}
			count++;
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				wins[j + k][i][count] = 1;
			}
			count++;
		}
	}

	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j <14; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				wins[i + k][j + k][count] = 1;

			}
			count++;
		}
	}

	for (int i = 0; i < 14; i++)
	{
		for (int j = 18; j > 4; j--)
		{
			for (int k = 0; k < 6; k++)
			{
				wins[i + k][j - k][count] = 1;
			}
			count++;
		}
	}
}
void mywin_init() 
{
	for (int i = 0; i < count; i++)
	{
		mywin[i] = 0;
		computerwin[i] = 0;
	}
}

int* computerAI_one()
{
	int myScore[19][19];
	int computerScore[19][19];
	int max = 0;
	int u = 0, v = 0;
	int *myarray= (int*)malloc(2 * sizeof(int));

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			myScore[i][j] = 0;
			computerScore[i][j] = 0;
		}
	}

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] == empty)
			{
				for (int k = 0; k < count; k++)
				{
					if (wins[i][j][k] == 1)
					{
						if (mywin[k] == 1)
						{
							myScore[i][j] += 200;
						}
						else if (mywin[k] == 2)
						{
							myScore[i][j] += 400;
						}
						else if (mywin[k] == 3)
						{
							myScore[i][j] += 2000;
						}
						else if (mywin[k] == 4)
						{
							myScore[i][j] += 10000;
						}
						else if (mywin[k] == 5)
						{
							myScore[i][j] += 40000;
						}

						if (computerwin[k] == 1)
						{
							computerScore[i][j] += 220;
						}
						else if (computerwin[k] == 2)
						{
							computerScore[i][j] += 420;
						}
						else if (computerwin[k] == 3)
						{
							computerScore[i][j] += 2100;
						}
						else if (computerwin[k] == 4)
						{
							computerScore[i][j] += 20000;
						}
						else if (computerwin[k] == 5)
						{
							computerScore[i][j] += 80000;
						}
					}
				}
				if (myScore[i][j]>max)
				{
					max = myScore[i][j];
					u = i;
					v = j;
				}
				else if (myScore[i][j] == max)
				{
					if (computerScore[i][j]>computerScore[u][v])
					{
						u = i;
						v = j;
					}
				}
				if (computerScore[i][j]>max)
				{
					max = computerScore[i][j];
					u = i;
					v = j;
				}
				else if (computerScore[i][j] == max)
				{
					if (myScore[i][j]>myScore[u][v])
					{
						u = i;
						v = j;
					}
				}

			}
		}
	}
	//这里应该返回u、v
	myarray[0] = u;
	myarray[1] = v;
	return myarray;


}
int* computerAI_two()
{
	int myScore[19][19];
	int computerScore[19][19];
	int max = 0;
	int u = 0, v = 0;
	int *myarray=(int*)malloc(2 * sizeof(int));

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			myScore[i][j] = 0;
			computerScore[i][j] = 0;
		}
	}

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] == empty)
			{
				for (int k = 0; k < count; k++)
				{
					if (wins[i][j][k] == 1)
					{
						if (mywin[k] == 1)
						{
							myScore[i][j] += 200;
						}
						else if (mywin[k] == 2)
						{
							myScore[i][j] += 400;
						}
						else if (mywin[k] == 3)
						{
							myScore[i][j] += 2000;
						}
						else if (mywin[k] == 4)
						{
							myScore[i][j] += 10000;
						}
						else if (mywin[k] == 5)
						{
							myScore[i][j] += 40000;
						}

						if (computerwin[k] == 1)
						{
							computerScore[i][j] += 220;
						}
						else if (computerwin[k] == 2)
						{
							computerScore[i][j] += 420;
						}
						else if (computerwin[k] == 3)
						{
							computerScore[i][j] += 2100;
						}
						else if (computerwin[k] == 4)
						{
							computerScore[i][j] += 20000;
						}
						else if (computerwin[k] == 5)
						{
							computerScore[i][j] += 80000;
						}
					}
				}
				if (myScore[i][j]>max)
				{
					max = myScore[i][j];
					u = i;
					v = j;
				}
				else if (myScore[i][j] == max)
				{
					if (computerScore[i][j]>computerScore[u][v])
					{
						u = i;
						v = j;
					}
				}
				if (computerScore[i][j]>max)
				{
					max = computerScore[i][j];
					u = i;
					v = j;
				}
				else if (computerScore[i][j] == max)
				{
					if (myScore[i][j]>myScore[u][v])
					{
						u = i;
						v = j;
					}
				}

			}
		}
	}
	//这里应该返回u、v
	myarray[0] = u;
	myarray[1] = v;
	return myarray;


}
int connect6()//形参待定
{
	Step step;
	char message[256];
	int computerside;
	int start = 0;

	//初始化代码
	//chessBoard_init();
	win3D_init();//各个点位初始化
	mywin_init();
	//
	while (1)
	{
		fflush(stdout);

		//获取平台消息
		scanf("%s", message);

		//分析指令
		if (strcmp(message, "move") == 0)//若message=move则返回0
		{

			scanf("%s",message);
			fflush(stdin);

			step.First.x = message[0] - 'A';
			step.First.y = message[1] - 'A';
			step.Second.x = message[2] - 'A';
			step.Second.y = message[3] - 'A';

			//处理对方走棋，即将棋盘对应位置置为对方棋子
			board[step.First.x][step.First.y] = computerside ^ 1;
			for (int k = 0; k < count; k++)
			{
				if (wins[step.First.x][step.First.y][k] == 1)
				{
					mywin[k]++;
					computerwin[k] = 7;
				}
			}
			board[step.Second.x][step.Second.y] = computerside ^ 1;

			//region 计算对方某种赢法得分
			
			for (int k = 0; k < count; k++)
			{
				if (wins[step.Second.x][step.Second.y][k] == 1)
				{
					mywin[k]++;
					computerwin[k] = 7;
				}
			}
			//endregion
			//生成走法，并保存在step中
			int *p=computerAI_one();
			step.First.x = p[0];
			step.First.y = p[1];
			//处理己方行棋
			board[step.First.x][step.First.y] = computerside;//注意
			for (int k = 0; k < count; k++)
			{
				if (wins[step.First.x][step.First.y][k] == 1)
				{
					computerwin[k]++;
					mywin[k] = 7;
				}
			}

			int *p1=computerAI_two();
			step.Second.x = p1[0];
			step.Second.y = p1[1];
			board[step.Second.x][step.Second.y] = computerside;//注意

			//region  计算我方AI得分
			
			for (int k = 0; k < count; k++)
			{
				if (wins[step.Second.x][step.Second.y][k] == 1)
				{
					computerwin[k]++;
					mywin[k] = 7;
				}
			}
			//endregion

			//输出走法
			printf("move %c%c%c%c\n", step.First.x + 'A', step.First.y + 'A', step.Second.x + 'A', step.Second.y + 'A');

		}
		else if(strcmp(message, "new") == 0)//建立新棋局
		{
			scanf("%s", message);//获取己方执棋颜色		
			fflush(stdin);
			if (strcmp(message, "black") == 0)//执黑
				computerside = black;
			else//执白
				computerside = white;

			//初始化棋局
			for (int i = 0; i<19; i++)
				for (int j = 0; j<19; j++)
					board[i][j] = empty;


			start = 1;
			mywin_init();
			if (computerside == black)
			{
				//生成第一手着法，并保存在step结构中
				step.First.x = 9;
				step.First.y = 9;
				//...

				//处理己方行棋
				board[step.First.x][step.First.y] = computerside;
				for (int k = 0; k < count; k++)
				{
					if (wins[step.First.x][step.First.y][k] == 1)
					{
						computerwin[k]++;
						mywin[k] = 7;
					}
				}

				//输出着法
				printf("move %c%c@@\n", step.First.x + 'A', step.First.y + 'A');


			}
		}
		else if (strcmp(message, "error") == 0)//着法错误
		{
			fflush(stdin);
			break;
		}

		else if (strcmp(message, "name?") == 0)//询问引擎名
		{
		
			fflush(stdin);
			//输出引擎名
			printf("name HaHaHa\n");
			

		}

		else if (strcmp(message, "end") == 0)//对局结束
		{
			//printf("This is a end messsage\n");
			fflush(stdin);
			start = 0;
		}
		else if (strcmp(message, "quit") == 0)//退出引擎
		{
			fflush(stdin);

			printf("Quit!\n");
			break;

		}
	}
	return 0;
}

