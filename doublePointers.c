#include <stdio.h>


void cant_change(int *x,int *y);
void change(int **x, int *y);

int main()
{

    int c = 1;
    int d = 2;
    int e = 3;
    int * a = &c;
    int * b = &d;
    int * f = &e;
    int ** pp = &a;  // pointer to pointer 'a'

    printf("a's value: %x \n", a);
    printf("b's value: %x \n", b);
    printf("f's value: %x \n", f);
    printf("can we change a?, lets see \n");
    printf("a = b \n");
    a = b;
    printf("a's value is now: %x, same as 'b'... it seems we can, but can we do it in a function? lets see... \n", a);
    printf("cant_change(a, f); \n");
    cant_change(a, f);
    printf("a's value is now: %x, Doh! same as 'b'...  that function tricked us. \n", a);

    printf("NOW! lets see if a pointer to a pointer solution can help us... remember that 'pp' point to 'a' \n");
     printf("change(pp, f); \n");
    change(pp, f);
    printf("a's value is now: %x, YEAH! same as 'f'...  that function ROCKS!!!. \n", a);
    return 0;
}

void cant_change(int * x, int * z){
    x = z;
    printf("\n ----> value of 'a' is: %x inside function, same as 'f', BUT will it be the same outside of this function? lets see\n", x);
}

void change(int ** x, int * z){
    *x = z;
    printf("\n ----> value of 'a' is: %x inside function, same as 'f', BUT will it be the same outside of this function? lets see\n", *x);
}