# notes

### oct 2, 10:15AM

Something that I just newly learned is that like in our example:

```c
typedef struct{
    int *arr = malloc(10 * sizeof(int));
    int size = 0;
    int capacity = 10;
} intArr;
```

where the you have something like `int *arr` treating a pointer as an array and
using something like `arr[i]` where i is some arbitrary integer (asssuming within
range of the pointer). It is essentially:

```c
arr[i] = *(arr + i)
```

and using something like the `[ ]` automatically derefences the pointer which is
a lot easier to read then having to do something like `*(arr + i)`

### oct 8, 12:00AM

I found the difference between
```c
intArr initArr(void){
	int *new_arr = calloc(10, sizeof(int));	

	return (intArr){
		.arr = new_arr,
		.capacity = 10,
		.size = 0
	};
}
```
 and the difference between initaiting without a function:
 ```c
 intArr *result = &(intArr){
		.arr = calloc(10, sizeof(int)),
		.capacity = 10,
		.size = 0
	};
```
---
int test_dynamicarray.c, (WIP)