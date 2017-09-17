#include <stdio.h>


int Pred(int x){
  return --x;
}
int Succ(int x){
  return ++x;
}
int myAddition(int x,int y){
  if(y >0){
      return myAddition(Succ(x),Pred(y));
  }else return x;
}

int main(){
  int number = myAddition(8,20);
  printf("Number: %d",number);
  return 0;
}
