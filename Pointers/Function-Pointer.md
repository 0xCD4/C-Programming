# Function Pointer

Below is a simple example using a function pointer where a function is passed an integer
and returns an integer. We also define a square function that squares an integer and
then returns the square. To simplify these examples, we ignore the possibility of integer
overflow.

```c
int (*fptr1)(int);
int square(int num) {
 return num*num;
}
// 


```

To use the function pointer to execute the square function, we need to assign the square
function’s address to the function pointer, as shown below. As with array names, when
we use the name of a function by itself, it returns the function’s address. We also declare
an integer that we will pass to the function.

```c

int n = 5;
fptr1 = square;
printf("%d squared is %d\n",n, fptr1(n));

```
illustrates how memory is allocated for this example. We have placed the
square function below the program stack. This is for illustrative purposes only. Func‐
tions are allocated in a different segment than that used by the program stack. The
function’s actual location is normally not of interest.



```c
typedef int (*funcptr)(int);
...
funcptr fptr2;
fptr2 = square;
printf("%d squared is %d\n",n, fptr2(n));

```
## Passing Function Pointers

Passing a function pointer is easy enough to do. Simply use a function pointer declara‐
tion as a parameter of a function. We will demonstrate passing a function pointer using
add, sub, and compute functions as declared below:

```c
int add(int num1, int num2) {
 return num1 + num2;
}
int subtract(int num1, int num2) {
 return num1 - num2;
}
typedef int (*fptrOperation)(int,int);
int compute(fptrOperation operation, int num1, int num2) {
 return operation(num1, num2);
}

```

The following sequence demonstrates these functions:

```c
printf("%d\n", compute(add,4,5)); // The result will be 9
printf("%d\n", compute(sub,5,10)); // The result will be -5


```

The whole written code :

```c
typedef int(*fptr)(int, int);




int add(int num1, int num2)
{

    return num1+num2;

}

int sub(int num1, int num2)
{

    return num1-num2;


}

int compute(fptr operation, int num1, int num2)
{
        return operation(num1, num2);

}


int main()
{



    printf("%d\n",compute(add,5,6));
    printf("%d\n",compute(sub,5,6));



}

```
Following are some interesting facts about function pointers.

1) Unlike normal pointers, a function pointer points to
code, not data.  Typically a function pointer stores the start of 
executable code.

2) Unlike normal pointers, we do not allocate de-allocate memory using function pointers.

3) A function’s name can also be used to get functions’ address.  For example, in the below program, we have removed address 
operator ‘&’ in assignment.  We have also changed function call by removing *, the program still works.

```c
#include <stdio.h> 
// A normal function with an int parameter 
// and void return type 
void fun(int a) 
{ 
	printf("Value of a is %d\n", a); 
} 

int main() 
{ 
	void (*fun_ptr)(int) = fun; // & removed 

	fun_ptr(10); // * removed 

	return 0; 
}

```

4) Like normal pointers, we can have an array of function pointers. Below example in point 5 shows syntax for array of pointers.

5) Function pointer can be used in place of switch 
case.  For example, in below program, user is asked for a choice between
0 and 2 to do different tasks.

```c

#include <stdio.h> 
void add(int a, int b) 
{ 
	printf("Addition is %d\n", a+b); 
} 
void subtract(int a, int b) 
{ 
	printf("Subtraction is %d\n", a-b); 
} 
void multiply(int a, int b) 
{ 
	printf("Multiplication is %d\n", a*b); 
} 

int main() 
{ 
	// fun_ptr_arr is an array of function pointers 
	void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply}; 
	unsigned int ch, a = 15, b = 10; 

	printf("Enter Choice: 0 for add, 1 for subtract and 2 "
			"for multiply\n"); 
	scanf("%d", &ch); 

	if (ch > 2) return 0; 

	(*fun_ptr_arr[ch])(a, b); 

	return 0; 
}

```

6) Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.

For example, consider the following C program where wrapper() receives a void fun() as parameter and calls the passed function.

```c
// A simple C program to show function pointers as parameter 
#include <stdio.h> 

// Two simple functions 
void fun1() { printf("Fun1\n"); } 
void fun2() { printf("Fun2\n"); } 

// A function that receives a simple function 
// as parameter and calls the function 
void wrapper(void (*fun)()) 
{ 
	fun(); 
} 

int main() 
{ 
	wrapper(fun1); 
	wrapper(fun2); 
	return 0; 
}

```

7) This point in particular is very useful in C. In C, we can use 
function pointers to avoid code redundancy.  For example a simple qsort() function can be used to sort arrays in ascending order or descending or by any other order in case of array of structures.  Not only this, with function pointers and void pointers, it is possible to use qsort for 
any data type.

```c
// An example for qsort and comparator 
#include <stdio.h> 
#include <stdlib.h> 

// A sample comparator function that is used 
// for sorting an integer array in ascending order. 
// To sort any array for any other data type and/or 
// criteria, all we need to do is write more compare 
// functions. And we can use the same qsort() 
int compare (const void * a, const void * b) 
{ 
return ( *(int*)a - *(int*)b ); 
} 

int main () 
{ 
int arr[] = {10, 5, 15, 12, 90, 80}; 
int n = sizeof(arr)/sizeof(arr[0]), i; 

qsort (arr, n, sizeof(int), compare); 

for (i=0; i<n; i++) 
	printf ("%d ", arr[i]); 
return 0; 
}


```
8) Similar to qsort(), we can write our own functions that can be used for any data type and can do different tasks without code redundancy. 
Below is an example search function that can be used for any data type. In fact we can use this search function to find close elements (below a threshold) by writing a customized compare function.

```c
#include <stdio.h> 
#include <stdbool.h> 

// A compare function that is used for searching an integer 
// array 
bool compare (const void * a, const void * b) 
{ 
return ( *(int*)a == *(int*)b ); 
} 

// General purpose search() function that can be used 
// for searching an element *x in an array arr[] of 
// arr_size. Note that void pointers are used so that 
// the function can be called by passing a pointer of 
// any type. ele_size is size of an array element 
int search(void *arr, int arr_size, int ele_size, void *x, 
		bool compare (const void * , const void *)) 
{ 
	// Since char takes one byte, we can use char pointer 
	// for any type/ To get pointer arithmetic correct, 
	// we need to multiply index with size of an array 
	// element ele_size 
	char *ptr = (char *)arr; 

	int i; 
	for (i=0; i<arr_size; i++) 
		if (compare(ptr + i*ele_size, x)) 
		return i; 

	// If element not found 
	return -1; 
} 

int main() 
{ 
	int arr[] = {2, 5, 7, 90, 70}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int x = 7; 
	printf ("Returned index is %d ", search(arr, n, 
							sizeof(int), &x, compare)); 
	return 0; 
}

```

