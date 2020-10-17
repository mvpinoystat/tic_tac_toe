/*
Copyright (C) 2020 PinoyStat 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#include<stdio.h>
#include<stdlib.h>
#include"head.h"

int main(int argc, char *argv[])
{
	_Bool playgame = 1;
	while(playgame == 1)
		{
			//initialize array
			char contents[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
			//create a pointer and initialize it:
			char *con[3][3];
			for(int xaxis = 0 ; xaxis < 3; xaxis++)
			{
				for(int yaxis = 0; yaxis < 3; yaxis++)
				{
					//printf("Xaxis : %d, Yaxis : %d \n", xaxis, yaxis);
					con[xaxis][yaxis] = &contents[xaxis][yaxis]; //get the address
				}
			}
	
			int has_winner = 0, board_is_filled = 1; //game is on going.
	
			//play the game

			int player = 1;
			int *p;
			p = &player;
	
			char number = '0';
	
			layout_frame(con); // pass addresses of contents variable in memory
	
			while(has_winner == 0 )
				{
						printf("player %d, enter a number: \n",*p);
						scanf(" %c",&number);//empty space before %c
						update_value(number,*p,con);//update the array
						layout_frame(con);//refresh the layout
						printf("Player %d has entered %c\n",*p, number);
						has_winner = check_winner(con);
						if(has_winner ==1)
							{
								printf("Congrats to player %d!!! THE WINNER !!!\n", *p);
								break;
							}
						board_is_filled = filled_up(con); //check if all slots are filled.
						if(board_is_filled == 1)
						{
							printf("It is a draw\n");
							break;
						}
						//switch between players after each run
						if (*p == 1)
							*p = 2;
						else
							*p = 1;				
					}
					
	
			//This below is the loop of the game
			char answer = 'x';
			char *ptr;
			ptr = &answer;
			while(*ptr != 'z')
				{
					printf("Want to play again? y for yes, n for no:\n");
					scanf(" %c", &*ptr);
					if(*ptr == 'y')
					{
						playgame = 1;
						*ptr = 'z';//exit the while loop
					}
					else if (*ptr == 'n')
					{
						playgame = 0;
						*ptr = 'z';//exit the while loop
					}
							
				}	
				//printf("Existed the while loop")
			}
		printf("Thanks for playing!!!\n");
	return 0;
}
