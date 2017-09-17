#include <stdio.h>

#define MAXQUEUE 10

//create new type of variable call queue
typedef struct QueueStruct {
  //create char arrays to store data for queue
  char Items[MAXQUEUE];
  //create variable like pointer to point font and rear
  int Front,Rear;
}TYPE_QUEUE;

//set what is list item that insert
char Front(TYPE_QUEUE *queue){
  return queue -> Items[queue -> Front];
}
//see what is frist item that insert
char Rear(TYPE_QUEUE *queue){
  return queue -> Items[(queue -> Rear)-1];
}

int QueueIsEmpty(TYPE_QUEUE *queue){
  // if font of queue and rear of queue equation it will empty
  return queue -> Front == queue -> Rear;
}

int QueueIsFull(TYPE_QUEUE *queue){
  //if rear of queue = max it will full just rear not font
  return queue -> Rear == MAXQUEUE;
}
// just like push in stack
void Insert(TYPE_QUEUE *queue,char item){
  //check queue is not full
  if(!QueueIsFull(queue)){
    // set items or rear = item;
    queue -> Items[queue->Rear] = item;
    //rear++
    (queue -> Rear)++;
  }else{
    printf("Can't Insert: QueueIsOverFlow\n");
  }
}
// just like pop in stack
void Delete(TYPE_QUEUE *queue,char *item){
  if(!QueueIsEmpty(queue)){
    *item = queue -> Items[queue -> Front];
    //set queue that remove to zero for easy to understand
    queue -> Items[queue -> Front] = ' ';
    (queue -> Front)++;
  }else{
      *item = ' ';
      printf("Can't Remove: QueueIsUnderFlow\n");
  }
}

void Initialize(TYPE_QUEUE *queue){
  for(int i =0;i<MAXQUEUE;i++){
    //set address of queue to ' ' or like zero
    queue -> Items[i] = ' ';
  }
  queue -> Front = 0;
  queue -> Rear = 0;
}

void print_allItemInQueue(TYPE_QUEUE *queue){
  for(int i=MAXQUEUE;i>=0;i--){
      printf("%2d: %c ",i,queue -> Items[i]);
      if(queue -> Front == i){
        printf("| <- Front");
      }
      if(queue -> Rear == i){
        printf("| <- Rear");
      }
      printf("\n");
  }
  printf("\n");
}

int main()
{
  TYPE_QUEUE listofItem ;
  Initialize(&listofItem);
  Insert(&listofItem,'A');
  print_allItemInQueue(&listofItem);
  Insert(&listofItem,'B');
  print_allItemInQueue(&listofItem);
  char charater[] = "NAME";
  for(int i=0;i<4;i++){
    Insert(&listofItem,charater[i]);
  }
  print_allItemInQueue(&listofItem);
  char getCharater;
  Delete(&listofItem,&getCharater);
  print_allItemInQueue(&listofItem);
  printf("getCharater: %c\n",getCharater);
  Delete(&listofItem,&getCharater);
  print_allItemInQueue(&listofItem);
  printf("getCharater: %c\n",getCharater);
  printf("Peek Front: %c\n",Front(&listofItem));
  printf("Peek Rear: %c\n",Rear(&listofItem));
  for(int i=0;i<5;i++){
    Delete(&listofItem,&getCharater);
    print_allItemInQueue(&listofItem);
  }
  char newCharater[] = "GLORY";
  for(int i=0;i<5;i++){
    Insert(&listofItem,newCharater[i]);
    print_allItemInQueue(&listofItem);
  }
  return 0;
}
