#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>             
#include <stdlib.h>
#include <time.h>


int place(int, int, int, int(*)[21]);
int Odello();


int arr[21][21] = { 0 };
char ch;
int turn = 0;
int x = 8, y = 8;
int i, j;
int num;
int a = 1, b = 1, c = 0;
int b_n = 0;
int w_n = 0;

clock_t  start, mid, end;
int place(int, int, int, int(*)[21]);

void main() {
	Odello();
}



int Odello() {
	arr[10][10] = 1;
	arr[11][11] = 1;
	arr[10][11] = 2;
	arr[11][10] = 2;
	start = clock();
	while (1) {
		b_n = 0;
		w_n = 0;
		system("cls");
		for (i = 0; i < 21; i++) {
			for (j = 0; j < 21; j++) {
				switch (arr[i][j]) {
				case 0:
					printf(" ┼");
					break;
				case 1:
					printf("●");
					b_n++;
					break;
				case 2:
					printf("○");
					w_n++;
					break;
				case 3:
					printf("★");
					b_n++;
					break;
				case 4:
					printf("☆");
					w_n++;
					break;
				case 5:
					printf("●");
					b_n++;
					break;
				case 6:
					printf("○");
					w_n++;
					break;

				}
			}
			printf("\n");
		}
		printf("\t 백돌 vs 흑돌\n");
		mid = clock();

		printf("\t  %d vs  %d\t%d초 경과", b_n, w_n, (int)((mid - start) / 1000));

		if (turn % 2 == 0)
			b_n--;
		else
			w_n--;

		if ((int)((mid - start) / 1000) > 10 * 30) { //승리 조건1
			system("cls");
			printf("\t 흑돌 vs 백돌\n");
			printf("\t  %d vs  %d\n", b_n, w_n);
			if (b_n > w_n)
				printf("흑돌 승!\n");
			else
				printf("백돌 승!\n");
		}
		if (b_n > 70) {                                          // 승리 조건2
			system("cls");
			printf("흑돌 승리!");
		}
		else if (w_n > 70) {
			system("cls");
			printf("백돌 승리!");
		}


		ch = getch();

		if (turn % 2 == 0) {
			switch (ch) {
			case 'a':
				if (x == 0)
					break;
				switch (arr[y][x - 1]) {
				case 0:
					arr[y][x - 1] = 1;
					break;
				case 1:
					arr[y][x - 1] = 3;
					break;
				case 2:
					arr[y][x - 1] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				x--;
				num = 1;
				break;
			case 'd':
				if (x == 20)
					break;

				switch (arr[y][x + 1]) {
				case 0:
					arr[y][x + 1] = 1;
					break;
				case 1:
					arr[y][x + 1] = 3;
					break;
				case 2:
					arr[y][x + 1] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				x++;
				num = 2;
				break;
			case 'w':
				if (y == 0)
					break;
				switch (arr[y - 1][x]) {
				case 0:
					arr[y - 1][x] = 1;
					break;
				case 1:
					arr[y - 1][x] = 3;
					break;
				case 2:
					arr[y - 1][x] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				num = 3;
				y--;
				break;
			case 's':
				if (y == 20)
					break;
				switch (arr[y + 1][x]) {
				case 0:
					arr[y + 1][x] = 1;
					break;
				case 1:
					arr[y + 1][x] = 3;
					break;
				case 2:
					arr[y + 1][x] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				num = 4;
				y++;
				break;
			case 13: //무조건 상대편돌이 내 돌 사이에 끼이게끔 만들면 됨
				if (arr[y][x] == 1) {
					if (place(x, y, turn, arr)) {
						//-------------------------------------------------------------------------------------
						//왼쪽
						while (x - a >= 0) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
							if (arr[y][x - a] == 1) {
								break;
							}
							else if (arr[y][x - a] == 2) {
								a++;
							}
							else {
								a = 1;
								break;
							}
						}
						for (; a > 1; a--)
							arr[y][x - (a - 1)] = 1;
						a = 1;
						//-------------------------------------------------------------------------------------
						//오른쪽
						while (x + a <= 20) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
							if (arr[y][x + a] == 1) {
								break;
							}
							else if (arr[y][x + a] == 2) {
								a++;
							}
							else {
								a = 1;
								break;
							}
						}
						for (; a > 1; a--)
							arr[y][x + (a - 1)] = 1;
						a = 1;
						//-------------------------------------------------------------------------------------
						//아래
						while (y + b <= 20) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
							if (arr[y + b][x] == 1) {
								break;
							}
							else if (arr[y + b][x] == 2) {
								b++;
							}
							else {
								b = 1;
								break;
							}
						}
						for (; b > 1; b--)
							arr[y + (b - 1)][x] = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//위
						while (y - b >= 0) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
							if (arr[y - b][x] == 1) {
								break;
							}
							else if (arr[y - b][x] == 2) {
								b++;
							}
							else {
								b = 1;
								break;
							}
						}
						for (; b > 1; b--)
							arr[y - (b - 1)][x] = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//1-7시 대각선
						while (y + b <= 20) {
							if (arr[y + b][x - a] == 1) {
								break;
							}
							else if (arr[y + b][x - a] == 2) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y + (b - 1)][x - (a - 1)] = 1;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//7-1시 대각선
						while (y - b >= 0) {
							if (arr[y - b][x + a] == 1) {
								break;
							}
							else if (arr[y - b][x + a] == 2) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y - (b - 1)][x + (a - 1)] = 1;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//11-5시 대각선
						while (y + b <= 20) {
							if (arr[y + b][x + a] == 1) {
								break;
							}
							else if (arr[y + b][x + a] == 2) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y + (b - 1)][x + (a - 1)] = 1;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//5-11시 대각선
						while (y - b >= 0) {
							if (arr[y - b][x - a] == 1) {
								break;
							}
							else if (arr[y - b][x - a] == 2) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y - (b - 1)][x - (a - 1)] = 1;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//turn++;
						arr[y][x] = 5;
						turn = 1;
					}
					break;
				}
			}
		}
		else {
			switch (ch) {
			case 'a':
				if (x == 0)
					break;
				switch (arr[y][x - 1]) {
				case 0:
					arr[y][x - 1] = 2;
					break;
				case 1:
					arr[y][x - 1] = 3;
					break;
				case 2:
					arr[y][x - 1] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				x--;
				num = 1;
				break;
			case 'd':
				if (x == 20)
					break;

				switch (arr[y][x + 1]) {
				case 0:
					arr[y][x + 1] = 2;
					break;
				case 1:
					arr[y][x + 1] = 3;
					break;
				case 2:
					arr[y][x + 1] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				x++;
				num = 2;
				break;
			case 'w':
				if (y == 0)
					break;
				switch (arr[y - 1][x]) {
				case 0:
					arr[y - 1][x] = 2;
					break;
				case 1:
					arr[y - 1][x] = 3;
					break;
				case 2:
					arr[y - 1][x] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				num = 3;
				y--;
				break;
			case 's':
				if (y == 20)
					break;
				switch (arr[y + 1][x]) {
				case 0:
					arr[y + 1][x] = 2;
					break;
				case 1:
					arr[y + 1][x] = 3;
					break;
				case 2:
					arr[y + 1][x] = 4;
					break;
				}
				switch (arr[y][x]) {
				case 1:
					arr[y][x] = 0;
					break;
				case 2:
					arr[y][x] = 0;
					break;
				case 3:
					arr[y][x] = 1;
					break;
				case 4:
					arr[y][x] = 2;
					break;
				case 5:
					arr[y][x] = 1;
					break;
				case 6:
					arr[y][x] = 2;
					break;
				}
				num = 4;
				y++;
				break;
			case 13:
				if (arr[y][x] == 2) {
					if (place(x, y, turn, arr)) {
						//-------------------------------------------------------------------------------------
						//왼쪽
						while (x - a >= 0) {                        //a는 1부터 하니까 a-1을 해야됨
							if (arr[y][x - a] == 2) {
								break;
							}
							else if (arr[y][x - a] == 1) {
								a++;
							}
							else {
								a = 1;
								break;
							}
						}
						for (; a > 1; a--)
							arr[y][x - (a - 1)] = 2;
						a = 1;
						//-------------------------------------------------------------------------------------
						//오른쪽
						while (x + a <= 20) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
							if (arr[y][x + a] == 2) {
								break;
							}
							else if (arr[y][x + a] == 1) {
								a++;
							}
							else {
								a = 1;
								break;
							}
						}
						for (; a > 1; a--)
							arr[y][x + (a - 1)] = 2;
						a = 1;
						//-------------------------------------------------------------------------------------
						//아래
						while (y + b <= 20) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
							if (arr[y + b][x] == 2) {
								break;
							}
							else if (arr[y + b][x] == 1) {
								b++;
							}
							else {
								b = 1;
								break;
							}
						}
						for (; b > 1; b--)
							arr[y + (b - 1)][x] = 2;
						b = 1;
						//-------------------------------------------------------------------------------------
						//위
						while (y - b >= 0) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
							if (arr[y - b][x] == 2) {
								break;
							}
							else if (arr[y - b][x] == 1) {
								b++;
							}
							else {
								b = 1;
								break;
							}
						}
						for (; b > 1; b--)
							arr[y - (b - 1)][x] = 2;
						b = 1;
						//-------------------------------------------------------------------------------------
						//1-7시 대각선
						while (y + b <= 20) {
							if (arr[y + b][x - a] == 2) {
								break;
							}
							else if (arr[y + b][x - a] == 1) {
								a++;
								b++;
							}
							else {
								b = 1;
								a = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y + (b - 1)][x - (a - 1)] = 2;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//7-1시 대각선
						while (y - b >= 0) {
							if (arr[y - b][x + a] == 2) {
								break;
							}
							else if (arr[y - b][x + a] == 1) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y - (b - 1)][x + (a - 1)] = 2;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//11-5시 대각선
						while (y + b <= 20) {
							if (arr[y + b][x + a] == 2) {
								break;
							}
							else if (arr[y + b][x + a] == 1) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y + (b - 1)][x + (a - 1)] = 2;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//5-11시 대각선
						while (y - b >= 0) {
							if (arr[y - b][x - a] == 2) {
								break;
							}
							else if (arr[y - b][x - a] == 1) {
								a++;
								b++;
							}
							else {
								a = 1;
								b = 1;
								break;
							}
						}
						for (; b > 1; b--) {
							arr[y - (b - 1)][x - (a - 1)] = 2;
							a--;
						}
						a = 1;
						b = 1;
						//-------------------------------------------------------------------------------------
						//turn++;
						arr[y][x] = 6;
						turn = 0;
					}
				}
				break;
			}
		}
	}
}


int place(int x, int y, int tern, int(*arr)[21]) {

	int a = 1;
	int b = 1;
	if (tern % 2 == 0) {
		//-------------------------------------------------------------------------------------
		//왼쪽
		while (x - a >= 0) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
			if (arr[y][x - a] == 1) {
				if (a == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y][x - a] == 2) {
				a++;
			}
			else {
				break;
			}
		}
		a = 1;
		//-------------------------------------------------------------------------------------
		//오른쪽
		while (x + a <= 20) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
			if (arr[y][x + a] == 1) {
				if (a == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y][x + a] == 2) {
				a++;
			}
			else {
				break;
			}
		}
		a = 1;
		//-------------------------------------------------------------------------------------
		//아래
		while (y + b <= 20) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
			if (arr[y + b][x] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x] == 2) {
				b++;
			}
			else {
				break;
			}
		}
		b = 1;
		//-------------------------------------------------------------------------------------
		//위
		while (y - b >= 0) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
			if (arr[y - b][x] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x] == 2) {
				b++;
			}
			else {
				break;
			}
		}
		b = 1;
		//-------------------------------------------------------------------------------------
		//1-7시 대각선
		while (y + b <= 20) {
			if (arr[y + b][x - a] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x - a] == 2) {
				a++;
				b++;
			}
			else { //0이면
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//7-1시 대각선
		while (y - b >= 0) {
			if (arr[y - b][x + a] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x + a] == 2) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//11-5시 대각선
		while (y + b <= 20) {
			if (arr[y + b][x + a] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x + a] == 2) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//5-11시 대각선
		while (y - b >= 0) {
			if (arr[y - b][x - a] == 1) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x - a] == 2) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
	}
	else {
		//-------------------------------------------------------------------------------------
		//왼쪽
		while (x - a >= 0) {                        //a는 1부터 하니까 a-1을 해야됨
			if (arr[y][x - a] == 2) {
				if (a == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y][x - a] == 1) {
				a++;
			}
			else {
				break;
			}
		}
		a = 1;
		//-------------------------------------------------------------------------------------
		//오른쪽
		while (x + a <= 20) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
			if (arr[y][x + a] == 2) {
				if (a == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y][x + a] == 1) {
				a++;
			}
			else {
				break;
			}
		}
		a = 1;
		//-------------------------------------------------------------------------------------
		//아래
		while (y + b <= 20) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
			if (arr[y + b][x] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x] == 1) {
				b++;
			}
			else {
				break;
			}
		}
		b = 1;
		//-------------------------------------------------------------------------------------
		//위
		while (y - b >= 0) {                        // 왼쪽//a는 1부터 하니까 a-1을 해야됨
			if (arr[y - b][x] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x] == 1) {
				b++;
			}
			else {
				break;
			}
		}
		b = 1;
		//-------------------------------------------------------------------------------------
		//1-7시 대각선
		while (y + b <= 20) {
			if (arr[y + b][x - a] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x - a] == 1) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//7-1시 대각선
		while (y - b >= 0) {
			if (arr[y - b][x + a] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x + a] == 1) {
				a++;
				b++;
			}
			else {
				break;
			}
		}

		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//11-5시 대각선
		while (y + b <= 20) {
			if (arr[y + b][x + a] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y + b][x + a] == 1) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------
		//5-11시 대각선
		while (y - b >= 0) {
			if (arr[y - b][x - a] == 2) {
				if (b == 1) {
					break;
				}
				else {
					return 1;
				}
			}
			else if (arr[y - b][x - a] == 1) {
				a++;
				b++;
			}
			else {
				break;
			}
		}
		a = 1;
		b = 1;
		//-------------------------------------------------------------------------------------

	}
	return 0;
}
