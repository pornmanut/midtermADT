#include <stdio.h>

#define MAX_STACK 10

int TOP = 0;
char STACK_CHAR[MAX_STACK];

int stackIsOverflow(){
  return TOP == MAX_STACK;
}
int stackIsEmpty(){
  return TOP == 0;
}

void initilalizeStack()
{
  //Set all stack to ' '
  for(int i=0;i<MAX_STACK;i++){
    STACK_CHAR[i] = ' ';
  }
}
void Push(char charater){
  if(!stackIsOverflow()){
    STACK_CHAR[TOP] = charater;
    TOP++;
  }else{
    printf("Can't Push:Stack is Overflow\n");
  }
}
void Pop(char *Pcharater){
  if(!stackIsEmpty()){
    TOP--;
    *Pcharater = STACK_CHAR[TOP];
    //We will set it to zero for easy to understand
    STACK_CHAR[TOP] = ' ';
  }else{
    printf("Can't Pop:Stack is Empty\n");
  }
}

//Show Stack
void printStack(){
  for(int i=MAX_STACK-1;i>=0;i--){
    printf("%2d: %c ",i+1,STACK_CHAR[i]);
    if(i == TOP){
      printf("|<--TOP\n");
    }else{
      printf("|\n");
    }
  }
}

int main(){
  initilalizeStack();
  Push('A');
  Push('B');
  Push('C');
  printStack();
  char c ;
  Pop(&c);
  printStack();
  printf("C: %c\n",c);
  printStack();
  Pop(&c);
  printStack();
  Pop(&c);
  printStack();
  Pop(&c);
  printStack();
  return 0;
}
