#include <stdio.h>


#define LIMIT 6

void get_set_elements(int array[])
{
  int count; 

  for(count = 0; count < LIMIT; count++)
  {
    printf("Enter Element No. %d\t", count + 1);
    scanf("%d", &array[count]);
  }
}

void sort(){

}


int main(){
  

  int set_A[LIMIT], set_B[LIMIT], intersection_array[LIMIT], union_array[LIMIT * 2 ];
    int total;

 
}