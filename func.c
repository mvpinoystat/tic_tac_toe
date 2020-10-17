#include<stdio.h>
#include<stdlib.h>

//draw the board
void layout_frame(char *cont[3][3])
{
	system("clear");
	printf("\n      Tic Tac Toe    \n\n");
	printf("Player 1 (x) - Player 2 (o)\n\n");
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 17; ++j)
		{
			if (j == 9 || j == 13)
				printf("|");
			else
				{	
					if(j > 5 && (i == 2|| i == 5))
						printf("_");
					else
						{
							if(j == 7 && i == 1)
								printf("%c",*cont[0][0]);
							else if(j == 11 && i == 1)
								printf("%c",*cont[0][1]);
							else if(j == 15 && i == 1)
								printf("%c",*cont[0][2]);
							else if(j == 7 && i == 4)
								printf("%c",*cont[1][0]);
							else if(j == 11 && i == 4)
								printf("%c",*cont[1][1]);
							else if(j == 15 && i == 4)
								printf("%c",*cont[1][2]);
							else if(j == 7 && i == 7)
								printf("%c",*cont[2][0]);
							else if(j == 11 && i == 7)
								printf("%c",*cont[2][1]);
							else if(j == 15 && i == 7)
								printf("%c",*cont[2][2]);
							
							else	
								printf(" ");
						}
				}
		}
		printf("\n");
	}
	printf("\n");
}
/*
Update the array .Get the location integer from keyboard plus the address of the array.
*/
void update_value(char input_number, int player, char *cont[3][3])
{
	//update or change the value in the array using pointer cont
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if (*cont[x][y] == input_number)
			{
				
				if (player == 1)
					*cont[x][y] = 'x';
				else if (player == 2)
					*cont[x][y] = 'o'; 
			}
			else
				continue;
		}
	}
	
}


//check if there is already a winner
//return 1 if there is and 0 if none.
int check_winner(char *cont[3][3])
{
	//ith row, jth column
	int winner = 0; //default no winner
	//row check (horizontal)
	for (int i = 0; i < 3; i++)
	{
		if ((*cont[i][0] == *cont[i][1]) &&(*cont[i][0]  == *cont[i][2]))
		{
			winner = 1;
			break;
		}
	}
	//column check (horizontal)
	for (int j = 0; j < 3; j++)
	{
		if((*cont[0][j] == *cont[1][j]) && (*cont[0][j] == *cont[2][j]))
		{
			winner = 1;
			break;
		}
	}
	//diagonal check	
	if((*cont[0][0] == *cont[1][1])&&(*cont[0][0] == *cont[2][2]))
		winner = 1;
	if((*cont[0][2] == *cont[1][1]) &&(*cont[0][2] == *cont[2][0]))
		winner = 1;
		
	return winner; 
}

int filled_up(char *cont[3][3])
{
	
	//check if everthing is filled up:
	int status = 1; //there is no available slot;
	int counter = 0; //counter
	int is_filled[9] = {0}; // default all slot is empty
	//ith row, jth column
	//check the status of each slot
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			{
				//printf("%c ",*cont[i][j]);
				if ((*cont[i][j] == 'x') || (*cont[i][j] == 'o'))
					{
						is_filled[counter] = 1;//this location is not filled
						//printf(" in counter %d is_filled :%d\n",counter,is_filled[counter]);	
						counter++;
					}
					
				else
					{
						is_filled[counter] = 0;
						//printf(" in counter %d is_filled :%d\n",counter,is_filled[counter]);	
						counter++;
					}
					
				
			}
	}
	
	//check is_filled array:
	for(int y = 0; y < 9; y++)
	{
		if(is_filled[y] == 0 )
		{
			status = 0; //change the status if there is still a slot
			break;//needed to break the loop if a slot is detected
		}
	}
	return status;
}

	
