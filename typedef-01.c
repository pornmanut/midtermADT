#include<stdio.h>

void Hanoi(int n,char F,char A,char T)
{
  if(n>0){
    Hanoi(n-1,F,T,A);
    printf("Move disk %d factor %c to %c.\n",n,F,T);
    Hanoi(n-1,A,F,T);
  }
}
int main(){
    Hanoi(4,'A','B','C');
    return 0;
}
