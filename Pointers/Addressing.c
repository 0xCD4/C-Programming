#include <stdio.h>


int main()
{

int a = 3;
int b = 7;
int c;

double *aPtr,*bPtr,*cPtr;
c = a+b;

aPtr = &a;
bPtr = &b;
cPtr = &c;

printf("The value of c is %d\n",c);
printf("The value of &a is %p\n\n",&a);
printf("The value of bPtr is %p\n",bPtr);
printf("The value of *bPtr is %d\n\n", *bPtr);
printf("The value of cPtr is %p\n",cPtr);
printf("The value of *aPtr is %d\n\n", *aPtr);
printf("The value of *&a is %d\n", *&a);
printf("The value of *&c is %d\n\n",*&c);
printf("The value of *&aPtr is %p\n\n",*&aPtr);
printf("The value of *&bPtr is %p\n\n",*&bPtr);
printf("The value of *&cPtr is %p\n\n",*&cPtr);

return 0;




}
