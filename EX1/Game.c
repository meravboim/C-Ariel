#include <stdio.h>
#include "A.h"


int main()
{
    int num1,num2,num3;
    int First_heap,Seocend_heap,Third_heap;
    int EndGame=0;

    printf("please enter 3 numbers\n");
    scanf("%d %d %d", &num1,&num2,&num3);
    First_heap=min(num1,num2,num3);
    Seocend_heap=mid(num1,num2,num3);
    Third_heap=max(num1,num2,num3);

    printf(" packet sizes are: \n %d %d %d\n",First_heap,Seocend_heap,Third_heap);
    if (First_heap==0&&Seocend_heap==0&&Third_heap==1)
         EndGame=1;

    //בדיקה מי מתחיל
   int  ComputerTurn= WhoStart( First_heap,Seocend_heap,Third_heap);

while(EndGame==0){
if ( ComputerTurn==1){
            //המחשב משחק
        switch(WhoAreEven( First_heap,Seocend_heap,Third_heap)){
    case 0:
        if(First_heap==0&&Seocend_heap==1){
             printf("I turned %d to 0 \n",Third_heap);
             Third_heap=0;
          }
          else{
                if((Seocend_heap==2*First_heap)&&(Third_heap-First_heap<Seocend_heap)){
                  printf("I turned %d to %d \n",Seocend_heap,Third_heap-First_heap);
                  Seocend_heap=Third_heap-First_heap;
            }
                else{
                        printf("I turned %d to %d \n",Third_heap,Seocend_heap-First_heap);
                        Third_heap=Seocend_heap-First_heap;
                    }
                }
         break;
    case 1:
                    if(First_heap==0||First_heap==1){
                            if(Third_heap!=1){
                       printf("I turned %d to 1 \n",Third_heap);
                       Third_heap=1;
                            }
                            else{
                      printf("I turned %d to 0 \n",Third_heap);
                       Third_heap=0;

                            }
                       }
                       else{
                        printf("I turned %d to 0 \n",Third_heap);
                       Third_heap=0;
                       }
                     break;
    case 2:
        if(First_heap==0&&Seocend_heap==1){
            printf("I turned %d to 0 \n",Third_heap);
            Third_heap=0;
        }
          else{
            if(First_heap!=0){
               printf("I turned %d to 0 \n",First_heap);
               First_heap=0;
            }
            else{
                 printf("I turned %d to %d \n",Seocend_heap,Seocend_heap-1);
               Seocend_heap=Seocend_heap-1;
            }
            }

           break;



        }
        ComputerTurn=0;
        }
        else{
            //המשתמש משחק
            printf("Your Turn \n please state how much to take ?\n");
            int ChangeFrom,ChangeTo;
            scanf("%d to %d",&ChangeFrom,& ChangeTo);
            if(ChangeFrom>ChangeTo){
            if (ChangeFrom==First_heap)
             First_heap=ChangeTo;
             else if (ChangeFrom==Seocend_heap)
             Seocend_heap=ChangeTo;
             else if (ChangeFrom==Third_heap)
              Third_heap=ChangeTo;

             ComputerTurn=1;

            }
            else
                printf("illegal move. try again");
        }
        num1=First_heap;
        num2=Seocend_heap;
        num3= Third_heap;
        First_heap=min(num1,num2,num3);
        Seocend_heap=mid(num1,num2,num3);
        Third_heap=max(num1,num2,num3);
        printf(" packet sizes are now:\n %d %d %d\n",First_heap,Seocend_heap,Third_heap);
        EndGame=CheckIfWin( First_heap,Seocend_heap,Third_heap,ComputerTurn);


        }

    return 0;
}


