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

