#include <stdio.h>

#define MAXSTACK 10

typedef struct stackStruct{
  char Items[MAXSTACK];
  int Top;
  int Front,Rear;
}TYPE_STACK;
void Print_allItemsInStack(TYPE_STACK*);
int isStackOverFlow(TYPE_STACK *stack){
  return stack -> Top == MAXSTACK;
}
int isStackEmpty(TYPE_STACK *stack){
  return stack -> Top == 0;
}
void Push(TYPE_STACK *stack,char item){
  if(!isStackOverFlow(stack)){
    stack -> Items[stack-> Top] = item;
    (stack->Top)++;
  }else{
    printf("Can't Push: StackIsOverFlow\n");
  }
}
void ReLocationStack(TYPE_STACK *stack){
  for(int i=0;i<MAXSTACK-1;i++){
  if(stack ->Items[stack->Front] == ' '){
    if(stack->Items[stack->Rear+1] != ' '){
      stack->Items[stack->Front] = stack->Items[stack->Rear+1];
      stack->Items[stack->Rear+1] = ' ';
      Print_allItemsInStack(stack);
    }
  }else{
    stack->Front++;
    stack->Rear++;
  }
  }
  stack->Top--;
  stack->Front =0;
  stack->Rear = 0;
}
void Initilize(TYPE_STACK *stack){
    for(int i=0;i<MAXSTACK;i++){
      stack -> Items[i] = ' ';
    }
    stack -> Top =0;
    stack -> Front =0;
    stack -> Rear =0;
}
void Print_allItemsInStack(TYPE_STACK *stack){
  for(int i=MAXSTACK-1;i>=0;i--){
    printf("%2d: %c ",i,stack -> Items[i]);
    printf("|");
    if(stack -> Top == i)printf(" <-Top");
    if(stack -> Front == i)printf(" <-Front");
    if(stack -> Rear == i)printf(" <-Rear");
    printf("\n");
  }
  printf("\n");
}
void Delete_2nd_From_Bottom_Stack(TYPE_STACK *stack){
    stack -> Items[1] = ' ';
    Print_allItemsInStack(stack);
    ReLocationStack(stack);
}
int main()
{
  TYPE_STACK myStack;
  Initilize(&myStack);
  Push(&myStack,'A');
  Push(&myStack,'B');
  Push(&myStack,'C');
  Push(&myStack,'D');
  Push(&myStack,'E');
  Delete_2nd_From_Bottom_Stack(&myStack);
  Print_allItemsInStack(&myStack);
  Push(&myStack,'F');
  Push(&myStack,'G');
  Delete_2nd_From_Bottom_Stack(&myStack);
  Print_allItemsInStack(&myStack);

  return 0;
}
