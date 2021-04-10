//以100以内的的素数为例子
#include<stdio.h>
#define NUMBER 100

int main(void)
{
  int i = 2,j;
  
  while(i <= 100){
    for(j = 2; j * j <= i; ++j){
        if((i % j) == 0){
          printf("%d ", i);
          break;
        }
    }
    ++i;
  }
  
  return 0;
}
