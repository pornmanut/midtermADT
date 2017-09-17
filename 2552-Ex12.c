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
int myMuliplication(int x,int y){
  if(y >0){
    return myAddition(x,myMuliplication(x,Pred(y)));
  }return 0;
}
int main(){
  int a=8,b=20;
  int plus = myAddition(a,b);
  printf("%d + %d = %d\n",a,b,plus);
  int mutiply = myMuliplication(a,b);
  printf("%d * %d = %d\n",a,b,mutiply);
  return 0;
}
