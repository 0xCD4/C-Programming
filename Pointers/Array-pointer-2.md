# Array pointers

Hello everyone, 

today i am going to be writing a blog about array pointer. It is useful to learn pointers to code and program more understandably.
It is however important to have fundamental knowledge about pointers. It will be useful if we will want to work with multidimensional arrays.
We can declare a pointer that can point to whole array instead  of only one element of the array. Let me code some examples:

```c

data_type (*var_name)[size_of_array];

```
We would like to increase our coding skills, as a low-level programmer, it shall be great to enhance our skills. I am going to enlight the definitions what I meant.

When we define an array, we put the type of the items in the array before the variable name and then the length of the array in square brackets after the variable

We cannot put * after the [] to get a pointer to an array. You need to put an * followed by the variable you define in parentheses, preceded by the type of the array and followed by [] like this:


```c
int (*pointer1)[];
int (*pointer2)[10];

```

Let me code another example:

```c

int main(int argc, char const *argv[])
{
	int arr[] = { 3, 5, 6, 7, 9 };
    int *ptr1= arr;
    int (*ptr2)[5] = &arr;
    printf("%p\n",ptr1);
    printf("%p\n",&arr);
    printf("%zu\n", sizeof(*ptr2));
}

```
1. We have defined an *arr* that holds 5 elements
2. We also defined *ptr1* which holds the address of *arr*
3. Moreover, we can also declare *array pointer* which will hold 5*4 bytes = 20 bytes

We will print and the result :

```c
0x7ffd8849a1f0 <-- ptr
0x7ffd8849a1f0 <-- &arr
20 <-- sizeof(*ptr2)

```
1. We can see that the first result; is the *ptr* adress
2. The second result, is the address of *array*
3. *ptr2* holds 5 element, and we know that each element in *int* has 4 bytes 


Let me code more examples:

```c
int arr[] = { 3, 5, 6, 7, 9 };
int *ptr1= arr;
int (*ptr2)[5] = &arr;
printf("sizeof(ptr1) = %lu, sizeof(*ptr1) = %lu\n",sizeof(ptr1), sizeof(*ptr1));
printf("%zu\n",sizeof(*ptr2));
```

The result:


```c
sizeof(ptr1) = 8, sizeof(*ptr1) = 4     
20
```
1. We can see that sizeof *ptr1 (which points to the address) has 4 bytes
2. On the other hand, ptr1 has 8 bytes 

That is the difference.

We should note that : all pointers are 8 bytes. Also, In C size of a pointer is not fixed as it depends on Word size of the processor. In general a 32-bit computer machine then size of a pointer would be 4 bytes while for a 64-bit computer machine,
it would be 8 bytes.


## Example Array-pointer

I will going to use an example from [scaler](https://www.scaler.com/topics/c/array-of-pointers-in-c/)

```c
#include <stdio.h>

int main()
{
  // array declaration and initialization
  int a[5] = {5, 6, 7, 8, 9}, i;
	
  // Valid in case of arrays but not valid in case of single integer values.
  int *ptr = a;
	
  // All representations prints the base address of the array
  printf("ptr : %u, &a[0] : %u, a : %u, &a : %u\n", ptr, &a[0], a, &a);

  for(i = 0; i < 5; i++)
  {
	// printing address values
	printf("[index %d] Address : %u\n", i, (ptr + i));
  }

  printf("\n");

  for (i = 0; i < 5; i++)
  {
	// Accessing array values through pointer 
	// a[i] = *(a + i) = *(ptr + i) = *(i + a) = a[i]
	printf("[index %d] Value : %d %d %d %d\n", i, *(a + i), *(ptr + i), *(i + a), a[i]);
  }

  printf("\n");

  // Gives address of next byte after array's last element
  printf("&a : %u, &a + 1 : %u\n", &a, &a + 1);  

  // Gives the address of the next element
  printf("a : %u, a + 1 : %u\n", a, a + 1);

  // Gives value at index 1
  printf("*(a + 1) : %d\n", *(a + 1)); 
	
  // Gives (value at index 0) + 1
  printf("*a + 1 : %d\n", *a + 1);   
	
  // Gives (value at index 0) / 2, we can't perform *(p / 2) or *(p * 2)
  printf("(*ptr / 2) : %d\n", (*ptr / 2)); 

  return 0;
}


```


The result:

```c

[Success] Your code was executed successfully
ptr : 1709381984, &a[0] : 1709381984, a : 1709381984, &a : 1709381984
[index 0] Address : 1709381984
[index 1] Address : 1709381988
[index 2] Address : 1709381992
[index 3] Address : 1709381996
[index 4] Address : 1709382000

[index 0] Value : 5 5 5 5
[index 1] Value : 6 6 6 6
[index 2] Value : 7 7 7 7
[index 3] Value : 8 8 8 8
[index 4] Value : 9 9 9 9

&a : 1709381984, &a + 1 : 1709382004
a : 1709381984, a + 1 : 1709381988
*(a + 1) : 6
*a + 1 : 6
(*ptr / 2) : 2
```
1. As we know, `ptr`, `&a[0]`, a and &a are representing the same address, so all representations print the same address value in the output.
2. First for loop (i = 0 to 4) is used to print the address of all the array elements
3. Second for loop (i = 0 to 4) is used to demonstrate that `a[i]` = `*(a + i)` = `*(ptr + i)` = `*(a + i)` = `a[i]`. All these representations of the array elements are equivalent to each other.
4. &arr + 1 gives the address of the element that is next to the last element (&arr + 1 covers the whole array) while `a + 1` gives the address of the second element of the array.
5. `*(a + 1)` prints the value at index 1 in the output and is equivalent to `a[1]`.
6. `*a + 1` prints the (value at `[index 0]) + 1` and is equivalent to `a[0] + 1` 
7. (*ptr / 2) prints the (value at [index 0]) / 2, we can't perform division or multiplication operations on pointers directly. (*(p / 2) or *(p * 2) respectively).

I hope that it was clear to understand about pointers. Practice would be great.


## Binary-search with pointer
```c
#include <stdio.h>
#include <assert.h>

int *bin_search(int *left, int *right, int x)
{
	while(left<right)
	{
		int *mid = (right-left)/2+left; // calculates the mid
		if(*mid == x)
			return mid;
		if(*mid<x)
			left = mid+1;
		else
			right = mid;

	}
	
	


}

int main()
{
 
 int array[] = { 0, 1, 2, 3, 4 };
 int n = sizeof array  / sizeof *array ; // 5
 int *result = bin_search(array,array+n,7); // array = 0, array + n = 5, x = 3
 if(*result)
 {
 	printf("Found\n");
 }
 else
 {printf("Not found\n");}
 	


}

```
It does work on sublime-text editor but not on Code-Block
