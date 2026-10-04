#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

/*
 * Author: Emilio S
 * dynamic arraylist data structure practice in C
 */

/*
 * struct intArr is an array list data structure, starting off with 10 spaces
 * that dynamically adjust themselves.
 */
typedef struct {
	int *arr;
	int capacity;
	int size;
}intArr;

/*
 * initArray() initializes an array instance
 * @return: intArr, the given array that was intialized
 */ 
intArr initArr(void);

/*
 * destroyArray() deletes the given array
 * @param: intArr *arr, the specified array to be deleted
 * @return: void
 */
void destroyArray(intArr *arr);

/*
 * appendItem() appends a number to the end of an intArr
 * if the array is at full capacity, recreate the array adn double the size of the
 * array to fit more items inside, moving all of the items from the origianl into
 * the new array
 * @param: intArr *arr, is the specified array
 * @param: int item, the item you want to append to the array
 * @return: int, exit status if return is non-zero, then something went wrong
 * 		1 = null output
 */
int appendItem(intArr *arr, int item);

/*
 * setItem(), recieves item and index and sets the item in specified array
 *
 * I chose to have the set index range be from 0 - arr->size than capacity.
 *
 * @param: intArr *arr, is the specified intArr
 * @param: int item, specified item to put in array
 * @param: int idx specified index for item to be set
 * @return: int exit status, if return is non-zero, then something went wrong
 * 		2 = bad input
 */
int setItem(intArr *arr, int item, int idx);

/*
 * removeItem() takes specified item from intArr, removes it, slides rest of
 * values from remaining index highest then specified idx, depending where
 * specified index of removed item was
 * @param: intArr *arr, specified arr
 * @param: int idx, specified idx for item remove
 * @return: int, exit status, if return is non-zero, then something went wrong
 * 		2 = bad input
 */
int removeItem(intArr *arr, int idx);

/*
 * length(), retreives arr->size
 * @param: intArr *arr, specified arr
 * @return: int returns the length of specified arr
 */
int length(const intArr *arr);

#endif
