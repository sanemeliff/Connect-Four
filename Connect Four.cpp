#include "stdio.h"
#include <stdlib.h>
//we defined row and column value as 10 here because it will be more readible when we use them in the functions
#define ROW 10
#define COLUMN 10 
//we wrote this function here because we used this function before it has written 
int checkWin(char board[ROW][COLUMN]);
//this function prints the array which is given in the parameter
int printBoard(char board[ROW][COLUMN]){
	//this for adds number to the rows
	for(int k=0; k<10; k++){
		printf(" ");
		printf("%d", k+1);
	}
	printf("\n");
	for(int i=0; i<ROW; i++){
		//adds number to the columns
		printf("%d", i+1, " ");
		for(int j=0; j<COLUMN; j++){
			printf("%c ", board[i][j], " ");
		}
		printf("\n");
	}
}
int play(char board[ROW][COLUMN]){
	int turn=0;
    int rowValue;
    int colValue;
    //turn!=100 because our array size is 10x10 which corresponds to 100
    while(turn!=100){
    	    if(turn % 2 == 0){
    	printf("First player (B) enter row value:");
    	scanf("%d", &rowValue);
    	printf("First player (B) enter column value:");
    	scanf("%d", &colValue);
    	printf("\n");
    	//checks if the chosen cell is empty
    	if(board[rowValue-1][colValue-1]==' '){
    	board[rowValue-1][colValue-1]='B';
    	//we call the checkWin function to check if first player wins after the move
		checkWin(board);	
		}
		//checks if the scanf value is out of the board
		else if(rowValue>10 || colValue>10){
		  	printf("Between 1-10 please!\n\n");
		  	//to make program ask again to the first player 
		  	turn--;
		  }
		  //checks if there is already a stone
    	    else if(board[rowValue-1][colValue-1]=='W' || board[rowValue-1][colValue-1]=='B'){
    		printf("There is already a stone, move another place\n\n");
    		turn--;
		}
    	printBoard(board);
	}
	else{
		printf("Second player (W) enter row value:");
    	scanf("%d", &rowValue);
    	printf("Second player (W) enter column value:");
    	scanf("%d", &colValue);
    	printf("\n");
    	if(board[rowValue-1][colValue-1]==' '){
    	board[rowValue-1][colValue-1]='W';
    	checkWin(board);
		}
		else if(rowValue>10 || colValue>10){
		  	printf("Between 1-10 please!\n\n");
		  	turn--;
		  }
		  else if(board[rowValue-1][colValue-1]=='W' || board[rowValue-1][colValue-1]=='B'){
		  printf("There is already a stone, move another place\n\n");
		  turn--;
		  }
		  
    	printBoard(board);
	}
	//we increase the turn value after every move
turn++;
	}
}
int checkWin(char board[ROW][COLUMN]){
	//in this for loop we check the row values if there is a consecutive four stone horizantally
	for (int i = 0; i < ROW; i++)
    {
    	for(int j = 0; j < COLUMN;j++)
		{
    	  if (board[i][j] == 'B' && board[i+1][j] == 'B' && board[i+2][j] == 'B' && board[i+3][j] == 'B'){
        	  printBoard(board);
			  printf("\n\n<BLACK> PLAYER WINS! CONGRATS\n\n");
        	  //used this library function to exit the program if game is finished
			  exit(0);
			}
		  else if(board[i][j] == 'W' && board[i+1][j] == 'W' && board[i+2][j] == 'W' && board[i+3][j] == 'W'){
		  	  printBoard(board);
			  printf("\n\n<WHITE> PLAYER WINS! CONGRATS\n\n");
		  	  exit(0);
		    }
	    }	
	}
    //in this for loop we check the column value if there is a consecutive for stone vertically 
	for (int i = 0; i < ROW; i++)
    {
    	for(int j = 0; j < COLUMN;j++)
		{
    	  if (board[i][j] == 'B' && board[i][j+1] == 'B' && board[i][j+2] == 'B' && board[i][j+3] == 'B'){
        	  printBoard(board);
			  printf("\n\n<BLACK> PLAYER WINS! CONGRATS\n\n");
        	  exit(0);
			}
		  else if(board[i][j] == 'W' && board[i][j+1] == 'W' && board[i][j+2] == 'W' && board[i][j+3] == 'W'){
		  	  printBoard(board);
			  printf("\n\n<WHITE> PLAYER WINS! CONGRATS\n\n");
		  	  
		  	  exit(0);
		    }
	    }	
	}
}


int main(){
	//we created the board with two dimensional array
	char board[ROW][COLUMN];
	int choosePlayer;
	printf("***The game has started***\n");
	//we fill the board with space value
		for(int i=0; i<ROW; i++){
		for(int j=0; j<COLUMN; j++){
			board[i][j]=' ';
		}
	}
	//printed empty board
	printBoard(board);
	printf("**For BLACK press 1**\n");
	printf("**For WHITE press 2**\n");
	scanf("%d", &choosePlayer);
	//wanted two choose player from the user
	switch(choosePlayer){
		case 1:
			printf("You choosed black player, you start first..!\n\n");
			play(board);
			break;
		case 2:
			printf("You choosed white player.. Wait for your turn..\n\n");
			play(board);
			break;
	}
	
}
