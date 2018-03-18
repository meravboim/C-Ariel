#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MATRIX_ROW 6
#define MATRIX_COLUMN 7
//print the board
void printStartOfTurn(char board[MATRIX_ROW][MATRIX_COLUMN]){
    int i,j;
    for(i=0;i<MATRIX_ROW;i++){
        for(j=0;j<MATRIX_COLUMN;j++){
            printf("|%c",board[i][j]);}
        printf("|\n");}
    for(j=1;j<=MATRIX_COLUMN;j++)
        {printf(" %d",j);}
}
//change the turn
char nextturn(char turn){
    if(turn=='x') return 'o';
    if(turn=='o') return 'x';
}
//check if the input is int number
int ifisdigit(char str[10]){
    int i;
    int countofundigit=0;
    for(i=0;i<strlen(str);i++){
        if(!isdigit(str[i])){
           if(str[i]!='.') return 2;
           else countofundigit++;
        }
    }
    if(countofundigit>1) return 2;
    if(countofundigit==1)  return 1;
    return 0;
}
//check if the input is good
int checkinput(char input[],int order,char board[MATRIX_ROW][MATRIX_COLUMN]){
    if(ifisdigit(input)==2) return 1;
    if(ifisdigit(input)==1) return 5;
    if(ifisdigit(input)==0){
        int columnchoice=atoi(input);
        if(columnchoice>7||columnchoice<0) return 2;
        if((columnchoice<=7&&columnchoice>=1)&&(board[0][columnchoice-1]!=' ')) return 3;
        if(columnchoice==0&&order==0) return 4;
    }
    return 0;
}

int countrowsequence(char board[MATRIX_ROW][MATRIX_COLUMN]){
    int countMax=1;
    int count=1;
    int i,j;
    for(i=0;i<MATRIX_ROW;i++){
        for(j=0;j<MATRIX_COLUMN-1;j++){
           if(' '!=board[i][j]&&board[i][j]==board[i][j+1])
             count++;
           else{
              if(count>countMax)
                 countMax=count;
               count=1;}
        }
        if(count>countMax)
            countMax=count;
        count=1;
    }
    return countMax;
}

int countcloumnsequence(char board[MATRIX_ROW][MATRIX_COLUMN]){
    int countMax=1;
    int count=1;
    int i,j;
    for(j=0;j<MATRIX_COLUMN;j++){
        for(i=0;i<MATRIX_ROW-1;i++){
           if(' '!=board[i][j]&&board[i][j]==board[i+1][j])
              count++;
           else{
               if(count>countMax)
                  countMax=count;
               count=1;}
        }
        if(count>countMax)
            countMax=count;
        count=1;
    }
    return countMax;
}

bool countRightdiagonalsequence(char board[MATRIX_ROW][MATRIX_COLUMN]){
    int i,j;
    for(i=MATRIX_ROW-3;i<MATRIX_ROW;i++){
        for(j=0;j<MATRIX_COLUMN-3;j++){
           if(' '!=board[i][j]&&board[i][j]==board[i-1][j+1]&&board[i][j]==board[i-2][j+2]&&board[i][j]==board[i-3][j+3])
              return true;
        }
    }
    return false;
}


bool countLeftdiagonalsequence(char board[MATRIX_ROW][MATRIX_COLUMN]){
    int i,j;
    for(i=MATRIX_ROW-3;i<MATRIX_ROW;i++){
        for(j=MATRIX_COLUMN-4;j<MATRIX_COLUMN;j++){
            if(' '!=board[i][j]&&board[i][j]==board[i-1][j-1]&&board[i][j]==board[i-2][j-2]&&board[i][j]==board[i-3][j-3])
               return true;
        }
    }
    return false;
}

bool CheckifWin(char board[MATRIX_ROW][MATRIX_COLUMN]){
    int countrow=countrowsequence(board);
    int countcloumn=countcloumnsequence(board);
    bool countLeftdiagonal=countLeftdiagonalsequence(board);
    bool countRightdiagonal=countRightdiagonalsequence(board);
    if(countrow>=4||countcloumn>=4||countLeftdiagonal||countRightdiagonal)
        return true;
    return false;
}

bool CheckifFullBoard(char board[MATRIX_ROW][MATRIX_COLUMN]){
    int j;
    for(j=0;j<MATRIX_COLUMN;j++){
        if(board[0][j]==' ') return false;
    }
    return true;
}

bool CheckIfEnd(char board[MATRIX_ROW][MATRIX_COLUMN],char turn){
    bool win=CheckifWin(board);
    bool fullboard=CheckifFullBoard(board);
    if(win){
        printf("Player %c wins!\n",turn);
        exit(0);}
    if(fullboard){
        printf("It's a tie!n");
        exit(0);}
    return false;
}



int main(){
char board[MATRIX_ROW][MATRIX_COLUMN];
int InsertionOrder[MATRIX_ROW][MATRIX_COLUMN];
int order=0;
bool endgame=false;
char turn='x';
char input[10];
int i,j;
//reset the matrix board and InsertionOrder
for(i=0;i<MATRIX_ROW;i++){
    for(j=0;j<MATRIX_COLUMN;j++)
        {board[i][j]=' ';}
}
for(i=0;i<MATRIX_ROW;i++){
    for(j=0;j<MATRIX_COLUMN;j++)
        {InsertionOrder[i][j]=0;}
}

printf("Welcome!\n");
while(!endgame){
    printStartOfTurn(board);
    printf("\nPlayer %c, please enter a column number (or 0 to undo):\n",turn);
    scanf("%s",&input);
    //check the input is good
    int goodinput=checkinput(input,order,board);
        while(goodinput!=0&&goodinput!=5){
            switch(goodinput){
            case 1:
                 printf("Invalid input, bye-bye!\n");
                 exit(0);
            break;
            case 2:
                printStartOfTurn(board);
                printf("\nInvalid input, the number must be between 1 to 7:\n");
            break;
            case 3:
                printStartOfTurn(board);
                printf("\nInvalid input, this column is full. Please choose another one:\n");
            break;
            case 4:
                 printStartOfTurn(board);
                 printf("\nBoard is empty - can't undo!\n");
            break;
            default:
                 printf("goodinput isn't right\n");
            break;
            }
            scanf("%s",&input);
            goodinput=checkinput(input,order,board);
        }

   //make the move
   int columnchoice=atoi(input);
   if(columnchoice==0){
   int row,column;
   for(i=0;i<MATRIX_ROW;i++){
       for(j=0;j<MATRIX_COLUMN;j++){
          if(InsertionOrder[i][j]==order){
               row=i;
               column=j;
            }
        }
     }
    board[row][column]=' ';
    order--;
   }
   else{
     columnchoice--;
     int indexofinsert=-1;
     for(i=0;i<MATRIX_ROW;i++){
       if(board[i][columnchoice]==' ') indexofinsert++;
     }
     board[indexofinsert][columnchoice]=turn;
     order++;
     InsertionOrder[indexofinsert][columnchoice]=order;
   }
    //check if someone win and change the turn
    endgame=CheckIfEnd(board,turn);
    turn=nextturn(turn);
    if(goodinput==5){
        printStartOfTurn(board);
        printf("you enter a double number,Invalid input, bye-bye!\n");
        endgame=true;
    }
}
    return 0;
}
