#include "dynamicarray.h"

#include <stdlib.h>
#include <stdio.h>

/*
 * Author: Emilio S
 * dynamic arraylist data structure practice in C
 */

// Remember that caller has to make sure (*(intArr.arr) != NULL)
intArr initArr(void){
	int *new_arr = calloc(10, sizeof(int));
	int new_capacity = 10;
	int new_size = 0; 

	return (intArr){
		.arr = new_arr,
		.capacity = new_capacity,
		.size = new_size
	};
}

void destroyArr(intArr *arr){
	free (arr->arr);

	arr->arr = NULL;
	arr->capacity = -1;
	arr->size = -1;
}


int appendItem(intArr *arr, int item){

	// checks if arr is overloaded
	if ( arr->capacity <= arr->size ){

		//resizes and moves items
		int new_capacity = arr->capacity * 2;
		int *new_arr = realloc(arr->arr,  new_capacity * sizeof (*arr->arr));
	
		if (new_arr == NULL)
		{
			fprintf(stderr, 
				"appendItem(): new_arr: when setting reallocating new arr, new_arr pointer = NULL"
				);
			return 1;
		}

		arr->arr = new_arr;
		arr->capacity = new_capacity;
	}

	// increment and appendItem	
	arr->size++;
	(arr->arr)[(arr->size) - 1] = item;	

	return 0;
}

int setItem(intArr *arr, int item, int idx){

	// or if (idx >=arr.size)
	if (arr->size < idx){
		fprintf(stderr, "setItem(): index is out of range of intArr");
		return 2;
	}
		
	arr->arr[idx] = item;	

	return 0; 
}

int removeItem(intArr *arr, int idx){

	// or if (idx >=arr.size)
	if (arr->size < idx){
		fprintf(stderr, "removeItem(): index is out of range of intArr");
		return 2;
	} 
	
	//if specified index isn't the last item in arraylist
	if ( !(idx == arr->size - 1) ){

		// slide every item in front of removed item over	
		for (int i = idx; i < arr->size - 1;i++){
			arr->arr[i] = arr->arr[i+1];
			}
	}

	arr->size--;

	return 0;
}

int length(const intArr *arr){
	return arr->size;
}

