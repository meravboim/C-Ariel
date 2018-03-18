#include <stdio.h>
#include <stdbool.h>
#include "FunctionsName.h"
#define MATRIX_SIZE 4
int main()
{
    char matrix[MATRIX_SIZE][MATRIX_SIZE]={{'C','A','R','T'},{'E','T','A','K'},{'E','S','M','E'},{'L','L','P','N'}};
    int NumOfWords=printWords(matrix);
    printf("Number Of Words In The Matrix Is %d \n", NumOfWords);
    return 0;
}
int printWords(char A[MATRIX_SIZE][MATRIX_SIZE]){
    int count=0;
    char word [17];
    int size=0;
    char words [100] [100];
    bool visit[MATRIX_SIZE][MATRIX_SIZE]={{false}};
    int row,column;
    for(row=0;row<MATRIX_SIZE;row++){
      for(column=0;column<MATRIX_SIZE;column++){
        count=printWordsRecursive(A,visit,row,column,word,size,count,words);

    }
    }
    return count;
}

int printWordsRecursive(char A[MATRIX_SIZE][MATRIX_SIZE], bool visit[MATRIX_SIZE][MATRIX_SIZE],int row,int column,char word[],int size,int count, char words[100][100]){
    visit[row][column]=true;
    word[size]=A[row][column];
    word[size+1]=0;
    size++;
    bool B=true;
    int i;
    for(i=0;i<count;i++){
        if(strcmp(words[i],word)==0)
            B=false;
    }
    if(isWord(word)&&B){
    strcpy(words[count], word);
     count++;
     printf("%s \n", word);
  }
  int r,c;
     for (r=row-1; r<=row+1 && r<MATRIX_SIZE; r++){
      for ( c=column-1; c<=column+1 && c<MATRIX_SIZE; c++){
            if(!(r==row-1&&c==column-1)&&!(r==row+1&&c==column-1)&&!(r==row+1&&c==column+1)&&!(r==row-1&&c==column-1)){
              if (r>=0 && c>=0 && !visit[r][c])
                count=printWordsRecursive(A,visit, r, c, word,size,count,words);
            }

    }
}
   word[size]=0;
    size--;
    visit[row][column] = false;
    return count;
}



bool isWord(char* s){

		return (!strcmp(s,"CAT") |
			!strcmp(s,"CATS") |
			!strcmp(s,"TRAM") |
			!strcmp(s,"TRAMS") |
			!strcmp(s,"TAME") |
			!strcmp(s,"CAR") |
			!strcmp(s,"CARS") |
			!strcmp(s,"RAT") |
			!strcmp(s,"RATS") |
			!strcmp(s,"RAMP") |
			!strcmp(s,"ART") |
			!strcmp(s,"CART") |
			!strcmp(s,"STAMP") |
			!strcmp(s,"TAKEN") |
			!strcmp(s,"MEN") |
			!strcmp(s,"MAKE") |
			!strcmp(s,"TAKE") |
			!strcmp(s,"ATE") |
			!strcmp(s,"SELL") |
			!strcmp(s,"STEEL") |
			!strcmp(s,"RAKE") );

}


