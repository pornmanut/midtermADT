#include <stdio.h>

#define MAX_STACK 10

char Input[MAX_STACK];
int Top = 0;

int StackIsEmpty(){
  return Top == 0;
}
int StackIsFull(){
  return Top == MAX_STACK;
}

void Pop(char *item){
  if(!StackIsEmpty())
  {
    Top--;
    *item = Input[Top];
    //Input[Top] = ' ';
  }else{
    printf("Stack Underflow\n");
  }
}
void Push(char item){
  if(!StackIsFull())
  {
    Input[Top] = item;
    Top++;
  }else{
    printf("Stack Overflow\n");
  }
}
void printStack(){
  for(int i=MAX_STACK;i>=0;i--)
  {
    printf("%2d: %c",i,Input[i]);
    if(i==Top){
      printf("<-Top\n");
    }else if(i>Top){
      printf("\n");
    }else{
      printf("<-%d\n",i+1);
    }
  }
}

#define STATE_POP 1
#define STATE_PUSH 0
#define RANGE_W 1
#define RANGE_X 2
#define RANGE_Y 3
#define RANGE_Z 4
#define ERROR_MSG 5
int stringDetect(char *charater){
  int state = STATE_PUSH;
  int counter = 1;
  int number = 0;
  char item;
  for(int i=0;charater[i] != '\0';i++)
  {
    switch (state) {
      case STATE_PUSH:
        switch (charater[i]) {
          case 'a':
          case 'b':
          case 'c':
          case 'd':
            Push(charater[i]);
            number++;
            printf("->Push '%c' into Stack\n",charater[i]);
            break;
          case 'R':
            if(counter == RANGE_W){
              state = STATE_POP;
              counter++;
              printf("Change State\n");
            }else return ERROR_MSG;
            break;
          case 'M':
            if(counter == RANGE_Y){
              state = STATE_POP;
              counter++;
            }else return ERROR_MSG;
              break;
          default:
            return counter;
        }
        break;
      case STATE_POP:
        Pop(&item);
        if(charater[i] == item)
        {
          number--;
          printf("->Pop %c isEquals %c\n",charater[i],item);
        }else if(charater[i] == 'L')
        {
          if(number != 0){
            return counter;
          }
          if(counter == RANGE_X){
            printf("Change State\n");
            state = STATE_PUSH;
            counter++;
          }else return ERROR_MSG;
        }else return counter;
        break;
    }
  }
  if(number != 0){
    return counter;
  }
  if(counter == RANGE_Z) return 0;
  else return ERROR_MSG;
}
#define SIZE 20
int main()
{
  char answer[SIZE] = "abcRcbaLddaMadd";
  printf("%s\n",answer);
  printf("Return: %d\n",stringDetect(answer));
  //printStack();
  return 0;
}
