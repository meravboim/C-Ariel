#include <stdio.h>
#include <stdlib.h>

//3.à
typedef struct myClass {
    int m_x;
    void (*add)();
} myClass;

void add(int y, myClass *s){
    s->m_x= s->m_x+y;
}
//3.á
typedef struct Derived{
    myClass clas;
}Derived;

void add2(int y, Derived *s){
    s->clas.m_x= s->clas.m_x^y;
}

typedef struct Derived2{
    int m_y;
    myClass clas;
}Derived2;

void add3(int y, Derived2 *s){
    s->clas.m_x= s->clas.m_x+y;
    s->m_y=y;
}

int main(){
myClass* temp = (myClass*)malloc(sizeof(myClass));
temp->m_x = 1;
temp->add = add;
printf("part1\n");
printf("m_x=%d\n",temp->m_x);
temp->add(20,temp);
printf("m_x=%d\n",temp->m_x);


Derived* temp2 = (Derived*)malloc(sizeof(Derived));
temp2->clas.m_x = 1;
temp2->clas.add = add2;
printf("part2\n");
temp2->clas.add(4,temp2);
printf("m_x=%d\n",temp2->clas.m_x);


Derived2* temp3 = (Derived2*)malloc(sizeof(Derived2));
temp3->clas.m_x = 1;
temp3->clas.add = add3;
printf("part3\n");
temp3->clas.add(20,temp3);
printf("m_x=%d\n",temp3->clas.m_x);
printf("m_y=%d\n",temp3->m_y);
return 0;
}
