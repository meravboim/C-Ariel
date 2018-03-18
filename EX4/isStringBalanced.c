#include <stdio.h>
#include<string.h>
#include <stdbool.h>

typedef struct stack {
  int stack[100];
  int top;
} stack;

struct stack usual={.top=-1};
struct stack straight={.top=-1};
struct stack curly={.top=-1};

bool isempty(stack st) {
   if(st.top == -1)
      return true;
   else
      return false;
}

int pop(stack* st) {
   int data;
      data = st->stack[st->top];
      st->top = st->top - 1;
      return data;
}

int push(stack* st,int data) {
      st->top = st->top + 1;
      st->stack[st->top] = data;
}


 bool isStringBalanced(char* sentence, int size){
     int i;
     for(i=0;i<size;i++){
        if(sentence[i]=='(')
           push(&usual,1);
        if(sentence[i]=='{')
           push(&curly,1);
        if(sentence[i]=='[')
           push(&straight,1);
        if(sentence[i]==')'){
            if(isempty(usual))
                return false;
            else
                pop(&usual);
        }
        if(sentence[i]=='}'){
            if(isempty(curly))
                return false;
            else
                pop(&curly);
        }
        if(sentence[i]==']'){
            if(isempty(straight))
                return false;
            else
                pop(&straight);
        }

     }
     if(!isempty(straight)||!isempty(usual)||!isempty(curly))
        return false;
     else
        return true;
 }


int main(){
char* sentence="if(x[i]>x[j){return;}";
bool x=isStringBalanced(sentence, strlen(sentence));
printf(x ? "true" : "false");
return 0;
}
