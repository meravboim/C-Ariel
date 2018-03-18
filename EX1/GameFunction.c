#include "NameOfFunction.h"

//פונקציה שמחזירה את הערך הקטן ביותר
int min(int num1,int num2,int num3){
  int min=num1;
    if(num2<min)
    min=num2;
    if(num3<min)
    min=num3;

return min;

}
//מחזירה את הערך הגדול ביותר
int max(int num1,int num2,int num3){
    int max=num1;
    if(num2>max)
    max=num2;
    if(num3>max)
    max=num3;

return max;

}
//פונקציה שמחזירה את הערך האמצעי
int mid(int num1,int num2,int num3){
    if( (num1<=num2&& num1>=num3)||(num1<=num3&& num1>=num2))
    return num1;
     if  ((num2<=num3&& num2>=num1)||(num2<=num1&& num2>=num3))
    return num2;
     if ((num3<=num2&& num3>=num1)||(num3<=num1&& num3>=num2))
    return num3;

}

// פונקציה שבודקת מי מתחיל. 0-משתמש 1-מחשב
int WhoStart(int First_heap,int Seocend_heap,int Third_heap){
    if(First_heap==1&&Seocend_heap==1&&Third_heap==1)
        return 0;
        if(First_heap==0&&Seocend_heap==0&&Third_heap==1)
        printf("start again with another numbers!!");
           if(First_heap==0&&Seocend_heap==1&&Third_heap==1)
        return 1;
    if(First_heap+Seocend_heap==Third_heap)
    return 0;
    else
    return 1;
}

int CheckIfWin(int First_heap,int Seocend_heap,int Third_heap,int ComputerTurn){
    if(First_heap==0&&Seocend_heap==0&&Third_heap==1){
        if(ComputerTurn==0)
            printf("Game Over - You Lost !! \n");
        else
            printf("You win !! \n");

            return 1;
    }
    return 0;
}

int WhoAreEven(int num1,int num2,int num3){
    if(num1==num2)
        return 1;
    if(num3==num2)
        return 2;

        return 0;
}
