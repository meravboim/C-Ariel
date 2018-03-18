#ifndef FUNCTIONSNAME_H_INCLUDED
#define FUNCTIONSNAME_H_INCLUDED
#define MATRIX_SIZE 4

int printWords(char A[MATRIX_SIZE][MATRIX_SIZE]);
bool isWord(char* s);
int printWordsRecursive(char A[MATRIX_SIZE][MATRIX_SIZE], bool visit[MATRIX_SIZE][MATRIX_SIZE],int row,int column,char word [],int size,int count, char words[100][100]);


#endif // FUNCTIONSNAME_H_INCLUDED
