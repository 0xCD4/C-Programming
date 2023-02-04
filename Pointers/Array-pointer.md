# Array-pointers

Welcome back to my C programming blog. Today, I am going to walk pointers trough with some examples that I want to give.
It is recommended to have to have solid understanding about arrays/pointers, because we will work with it.

This is the first part, the second part will be written. Stay tuned!

I will briefly explain what arrays are.

## Array

Arrays are collection of objects of the same type, laid out in memory as a sequence of contiguous objects. There is
aclose relationship between array and pointers to the first element (I will show examples); you can use
an array as if it is a pointer to its first element, and it degrades to that type.

Example:

```c

int A1[5];
int A2[5] = {1,2,3}; // only init first three
int A3[] = {1,2,3,4,5};
 
```
1. the first example you can see that we have declared an array with `5` elements
```c
5 * sizeof(int) = 20
```
2. the second example you can also see that contains five integers, but we have 
defined the first three of them. After declaring the integer, you can specify the array’s 
values afterward in curly braces. You do not have to set all of them—here, we only define 
the first three of five, but it is an error to provide more values than you say that the array 
contains.

3. The third example, we did not specify how many values will be given to that pointed array however,
	 we provide initial values. When we do this, the array will hold the values we given, and the size will match the number of values exactly.


You can also use this technique, that the lenght of `s` has given


```c
int x = strlen(s); // let say s = 5
char buffer[x]; // x will be given as being 5
// char buffer[5];

```
The buffer is allocated on the function call stack when we write buffer[x].

We should also not forget that:

```c
char example[5] = {'A','B','C','D','E'};

```

It starts at 0 index:

```bash
A --> 0
B --> 1
C --> 2
D --> 3
E --> 4
```

## Array-Pointers With example
As you can see that there is a close correspondence between pointers and arrays, and in any expression, you can use
as if it was a pointer to the underlying type. We should not forget :

They are not the same type, however. The sizeof() an array 
is not the size of a pointer to its elements, you cannot assign to an array, and the address 
of an array is a pointer to an array and not a pointer to a pointer of the underlying array.

I will show you later how : `1,2,3,4,5` will be represented as memory address.

```c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main()
{
int array[] = {1,2,3,4,5};
int *pointer= array;
int n = sizeof(array) / sizeof(*array); // *array represent to be 1

printf("sizeof of array : %zu sizeof of pointer : %zu\n",sizeof(array), sizeof(pointer));
}
```
Output : 

```
sizeof of array : 20
sizeof of pointer : 8
```

As you can see that I already declared an array list and a pointer.
We used `sizeof()` this is equal to be : 
```c
5*sizeof(int) --> we know that `int` holds 4 bytes --> 5*4 = 20
```
Pointer holds `8` bytes, so address of the array is a pointer that is 8 bytes, and so is the address of the pointer
The address of a pointer is itself a pointer, so when `pointer` has type `int *`, &pointer int **.


```c
char array[5] = {'A','B','C','D','E'};
char *pointers = array;
printf("%d\n", *pointers);
```
What will be the result ? Now we can clearly see that its being pointed to the first element.


output :

65 --> A

As we expected.

Do not forget :

```c

*pointers   = array[0]; // 65 --> A
*pointers+1 = array[1]; // 66 --> B
*pointers+2 = array[2]; // 67 --> C
*pointers+3 = array[3]; // 68 --> D
*pointers+4 = array[4]; // 69 --> E

```

The pointer that points to the 0th element of array and the pointer that points to the whole array are totally different. The following program shows this:

```c
// C program to understand difference between 
// pointer to an integer and pointer to an
// array of integers. 
#include<stdio.h>

int main()
{
	// Pointer to an integer
	int *p; 
	
	// Pointer to an array of 5 integers
	int (*pointer)[5]; 
	int arr[5];
	
	// Points to 0th element of the arr.
	p = arr;
	
	// Points to the whole array arr.
	pointer = &arr; 
	
	printf("p = %p, ptr = %p\n", p, pointer);
	
	p++; 
	pointer++;
	
	printf("p = %p, ptr = %p\n", p, pointer);
	
	return 0;
}

```

Output:

```c
p = 0x7fff4f32fd50, pointer = 0x7fff4f32fd50
p = 0x7fff4f32fd54, pointer = 0x7fff4f32fd64
```
p: is pointer to 0th element of the array arr, while `pointer` is a pointer that points to the whole array arr.

Lets see another example:

```c

#include<stdio.h>

int main()
{
	int arr[] = { 3, 5, 6, 7, 9 };
	int *p = arr;
	int (*ptr)[5] = &arr;
	
	printf("p = %p, ptr = %p\n", p+1, ptr+1);
	printf("*p = %d, *ptr = %p\n", *(p+1), *(ptr+1));
	
	
	return 0;
}

```
Output:

```bash
 p = 0x7ffd473e9e14, ptr = 0x7ffd473e9e24
*p = 5, *ptr = 0x7ffd473e9e2
```

I know that its may be confusing, that is why I will want to write in my second blog!

```c
int main()
{
	int arr[] = { 3, 5, 6, 7, 9 };
	int *p = arr; // arr[0]
	
	printf("%d\n",*p);
	// printf("%p\n", *ptr);
	printf("%p\n",&arr);
	printf("%d\n",*arr);
	
	return 0;
}

```

Output: 

```bash
3 ---> *p = arr[0] = 3
0x7ffda8869230 --> the memory address of being 3
3
```


To make it understandable

```c
#include<stdio.h>

int main()
{
	int arr[] = { 3, 5, 6, 7, 9 };
	int *ptr = arr; // arr[0]
	int n = sizeof(arr) / sizeof(*arr);
	
	for(int k = 0; k<n;k++)
	{
		printf("%p : %d\n", &arr[k], *(ptr+k));
	}
	
	
	return 0;
}

```

Output:

```bash
0x7ffe209a6840 : 3
0x7ffe209a6844 : 5
0x7ffe209a6848 : 6
0x7ffe209a684c : 7
0x7ffe209a6850 : 9

```
You can see that every element has its own memory address.

I think that it will be enough for this blog. Part 2 will be shared, stay tuned
