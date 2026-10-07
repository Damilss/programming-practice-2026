#include "dynamicarray.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

/*
 * Author: Emilio Scott
 * test_dynamicarray.c has unit test functions for the file dynamicarray.c
 * This file should have 100% coverage for dynamicarray.c
 * This file also includes it's own main
 *
 * Most of these functions don't need to be pointers since the the intArrs 
 * don't live beyond the functions that initialize them
 */

void test_initArr_1(int *assertion_count);
void test_initArr_2(int *assertion_count); 
void test_destroyArr_1(int *assertion_count); 
void test_destroyArr_2(int *assertion_count);
void test_appendItem_normal(int *assertion_count);
void test_appendItem_size_eq_capacity(int *assertion_count);
void test_setItem_normal(int *assertion_count);
void test_setItem_set_idx_eq(int *assertion_count);
void test_removeItem_normal(int *assertion_count);
void test_length_1(int *assertion_count);
void test_length_2(int *assertion_count);

/*
 * main.c is the test runner for this file, calls each function
 * @param: int argc, argument counter
 * @param: char *argv[] is the argument variables
 * @return: int, status code, 0 if succcess, non-zero if something went wrong
 */
int main (int argc, char *argv[]){
	int test_count = 0;
	int assertion_count = 0;

	//seed rand
	srand(time(NULL));

	printf("Now running test_dynamicarray.c\n");

	printf("test_initArr_1()\n");
	test_initArr_1(&assertion_count); test_count++;

	printf("test_initArr_2()\n");
	test_initArr_2(&assertion_count); test_count++;

	printf("test_destroyArr_1()\n");
	test_destroyArr_1(&assertion_count); test_count++;

	printf("test_destroyArr_2()\n");
	test_destroyArr_2(&assertion_count); test_count++;

	printf("test_appendItem_normal()\n");
	test_appendItem_normal(&assertion_count); test_count++;

	printf("test_appendItem_size_eq_capacity()\n");
	test_appendItem_size_eq_capacity(&assertion_count); test_count++;
	
	printf("test_setItem_normal\n");
	test_setItem_normal(&assertion_count); test_count++;

	printf("test_setItem_set_idx_bigger()\n");
	test_setItem_set_idx_eq(&assertion_count); test_count++;

	printf("test_setItem_set_idx_bigger()\n");
	test_removeItem_normal(&assertion_count); test_count++;
	
	printf("%d tests ran\n", test_count);
	printf("%d assertions ran \n", assertion_count);


	return 0;
}


/*
 * test_initArr_1() is the first unit test of initArr()
 * remember caller of initArr() has to check if (*intArr.arr) != NULL)
 * @param: int &assertion_count, takes the address of a counter to increment
 * @return: void
 */
void test_initArr_1 (int *assertion_count) {	
	intArr result = initArr();

	intArr expected;
	expected.arr = calloc(10, sizeof(*expected.arr));
	expected.capacity = 10;
	expected.size = 0;	

	if (expected.arr == NULL){
		printf("test_initArr_1(): test invalid, expected arr pointed is NULL\n");
		assert (expected.arr != NULL); (*assertion_count)++;
		return;
	}
	
	printf("test_initArr_1(): asserting result.arr != NULL\n");
	assert (result.arr != NULL); (*assertion_count)++;

	printf("test_initArr_1(): asserting result.arr != NULL\n");
	assert (result.capacity = 10); (*assertion_count)++;

	for (int i = 0; i < result.capacity; i++){
		printf("test_initArr_1(): asserting result.arr index %d intialized to 0\n", i);
		assert (result.arr[i] == 0); (*assertion_count)++;
	}
	
	printf("test_initArr_1(): asserting result.size == 0\n");
	assert (result.size == expected.size); (*assertion_count)++; 
	
	/*
	 * instead of using destoryArr(), keeping function testing independent
	 * If destroyArr(); doesn't work, doesn't cause memory leak
	 * structs get automatally forgotten after test ends
	 */	
	free(expected.arr); 
	free(result.arr);
}

/*
 * test_initArr_2() second unit tset of initArr()
 * remember caller of initArr() has to check if (*intArr.arr != NULL)
 * @param: int &assertion_count, takes address of a counter to increment
 * @return: void
 */
void test_initArr_2 (int *assertion_count) {
	
	intArr result = initArr();
	
	intArr expected;
	expected.arr = calloc (10,sizeof(*expected.arr));
	expected.capacity = 10;
	expected.size = 0;

	if (expected.arr == NULL){
		printf("test_initArr_1: test invalid, expected arr pointed is NULL");
	
		assert (expected.arr != NULL); (*assertion_count)++;
		return;
	}
	printf ("test_initArr_2(): asserting result.arr != NULL\n");
	assert (result.arr != NULL); (*assertion_count)++;

	printf ("test_initArr_2(): asserting result.capacity == expected.capacity\n");
	assert (result.capacity == expected.capacity); (*assertion_count)++;

	printf ("test_initArr_2(): asserting result.size == expected.size\n");
	assert (result.capacity == expected.capacity); (*assertion_count)++;

	/*
	 * instead of using destroyArr(), keeping function testing independent
	 * If destroyArr(); doesn't work, doesn't cause memory leak
	 * structs get automatally forgotten after test ends
	 */	
	free(expected.arr);
	free(result.arr);	
}

/*
 * test_destroyArray_1() first unit test of destroyArr()
 * @param: int &assertion_count, takes address of a counter to increment
 * @return: void
 */
void test_destoryArr_1 (int *assertion_count) {

	// essentially initArr(); but don't use initArr() for test of 
	// other functions
	intArr *result = &(intArr){
		.arr = calloc(10, sizeof(*result->arr)),
		.capacity = 10,
		.size = 0,
	};


	intArr expected = (intArr){
		.arr = NULL,
		.capacity = -1,
		.size= -1,
	};
	
	destroyArr(result);

	printf("test_destroyArr_1(): asserting result->size == expected.size\n");
	assert(result->size == expected.size); (*assertion_count)++;

	printf ("test_destroyArr_1(): asserting result->capacity == expected.capacity\n");
	assert (result->capacity == expected.capacity); (*assertion_count)++;

	printf ("test_destroyArr_1(): asserting result->arr == expected.arr\n");
	assert (result->arr == expected.arr); (*assertion_count)++;	
	
	//in case that destroyArr() fails
	if (result->arr != NULL){
		free(result->arr);
		result->arr = NULL; 
	}
}

/*
 * test_destroyarr_2() second unit test of destroyArr()
 * @param: int &assertion_count, takes address of a counter to increment
 * @return: void
 */
void test_destroyArr_2 (int *assertion_count) {
	// essentially initArr(); but don't use initArr() for test of
	// other functions
	intArr *result = &(intArr){
		.arr = calloc(10, sizeof(*result->arr)),
		.capacity = 10,
		.size = 0,
	};
	
	intArr expected = (intArr){
		.arr = NULL,
		.capacity = -1,
		.size = -1,
	};

	destroyArr(result);

	printf("test_destroyArr_2(): asserting result->size == expected.size\n");
	assert (result->size == expected.size); (*assertion_count)++;

	printf ("test_destoryArr_2(): asserting result->capacity == expected.capacity\n");
	assert (result->capacity == expected.capacity); (*assertion_count)++;

	printf("test_destroyArr_2(): asserting result->arr = expected.arr\n");
	assert(result->arr = expected.arr); (*assertion_count)++;

	if (result->arr != NULL){
		free(result->arr);
		result->arr = NULL;
	}
}

	


/*
 * test_appendItem_normal() is the intended runthrough of appendItem()
 * @param: int &assertion_count, takes address of a counter to increment 
 * @return: void
 */
void test_appendItem_normal (int *assertion_count) {
	intArr *result = &(intArr){
		.arr = calloc(10, sizeof(*result->arr)),
		.capacity = 10,
		.size = 0,
	};

	intArr expected = (intArr){
		.arr = calloc(10, sizeof(*expected.arr)),
		.capacity = 10,
		.size = 0, 
	};

	 if (result->arr == NULL){
		printf("test_appendItem_normal(): result->arr == NULL, Aborting unit tests\n");

	}else if (expected.arr == NULL){
		printf("test_appendItem_normal(): expected.arr == NULL, Aborting unit tests\n");

	} else {
		expected.arr[0] = 4; expected.size++; 
		appendItem(result, 4);

		// important to differentiate the pointer->struct values opposed to the regular struct
		printf("test_appendItem_normal(): asserting result->arr[0] == expected.arr[0]\n");
		assert(result->arr[0] == expected.arr[0]);


		printf("test_appendItem_normal(): asserting result->size == expected.size\n");
		assert(result->size == expected.size);

		printf("test_appendItem_normal(): asserting result->capacity == expected.capacity\n");
		assert(result->capacity == expected.capacity);

	}

	free(expected.arr);
	expected.arr = NULL;

	free(result->arr);
	result->arr = NULL; 

}


/*
 * test_appendItem_size_eq_capacity()
 * This test runs through the case where capcity is full and arrray needs to
 * be resized
 * @param: int &assertion_count, takes address of a counter to increment
 * @return: void
 */
void test_appendItem_size_eq_capacity (int *assertion_count) {
	// initial expected of capacity from intArr()
	const int INITIAL_EXPECTED_CAPACITY = 10;
	const int TEST_VALUE = rand() % 10;
	printf("test_appendItem_size_eq_capacity(): TEST_VALUE = %d\n", TEST_VALUE);

	intArr *result = &(intArr){

		// -> higher precedence than * (no parantheses needed)
		.arr = calloc(10, sizeof(*result->arr)),
		.capacity = INITIAL_EXPECTED_CAPACITY,
		.size = 0,
	};

	intArr expected = (intArr){
		.arr = calloc(20, sizeof(*expected.arr)),
		.capacity = 20,
		.size = 0,
	};
	
	// setting seed for size == capacity for both expected and size
	// using rand to generate numbers	
	if(result->capacity == INITIAL_EXPECTED_CAPACITY && result->arr != NULL && expected.arr != NULL){
		for(int i = 0; i < INITIAL_EXPECTED_CAPACITY; i++){
			result->arr[i] = rand() % 100; result->size++; 
			
			expected.arr[i] = rand() % 100; expected.size++;				
		}
			
		appendItem(result, TEST_VALUE);	
		expected.arr[10] = TEST_VALUE; expected.size++;

		printf("test_appendItem_size_eq_capacity(): asserting result->size == expected.size\n");
		assert(result->size == expected.size); (*assertion_count)++;
		
		// result->capacity should double and equal expected.capacity (20)
		printf("test_appendItem_size_eq_capacity(): asserting result->capacity == expected.capacity\n");
		assert(result->capacity == expected.capacity); (*assertion_count)++;
		
		// both should equal TEST_VALUE
		printf("test_appendItem_size_eq_capacity(): asserting result->arr[11] == expected.arr[11] && \
				result->arr == TEST_VALUE\n");
		assert(result->arr[10] == expected.arr[10]); (*assertion_count)++;
		assert(result->arr[10] == TEST_VALUE); (*assertion_count)++;
		

	} else if (result->arr == NULL){
		printf("test_appendItem_size_eq_capacity(): result->arr == NULL, Aborting unit tests\n");

	} else if(expected.arr == NULL){
		printf("test_appendItem_size_eq_capacity(): expected.arr == NULL, Aborting Unit test\n");

	} else if (result->capacity != INITIAL_EXPECTED_CAPACITY){
		printf("test_appendItem_size_eq_capacity(): initalized capacity for result is not accurate, aborting unit tests\n");
		
	}	

	free(result->arr);
	result->arr = NULL;

	free(expected.arr);
	expected.arr = NULL;
}

/*
 * test_setItem_normal() unit test of intended run through of setItem()
 * @return: void
 */
void test_setItem_normal (int *assertion_count) { 
	const int INITIAL_EXPECTED_CAPACITY = 10;
	
	// set array size for both expected and result (0-9)
	const int SET_ARR_SIZE = rand() % 10; 
	const int SELECTED_IDX = rand() % SET_ARR_SIZE;
	const int TEST_VALUE = rand() % 100; 

	intArr *result = &(intArr){
		.arr = calloc(10, sizeof(*(result->arr))),
		.capacity = 10,
		.size = 0,
	};

	intArr expected = (intArr){
		.arr = calloc(10, sizeof(*(expected.arr))),
		.capacity = 10,
		.size = 0,
	};

	if(result->arr == NULL){
		printf("test_setItem_normal(): result->arr == NULL, Aborting unit tests\n");

	}else if(expected.arr == NULL){
		printf("test_setItem_normal(): expected.arr == NULL, Aborting unit tests\n");

	}else {	
		for(int i = 0; i < SET_ARR_SIZE; i++){
			result->arr[i] = rand() % 100; result->size++; 
			expected.arr[i] = rand() % 100; result->size++;

		}

		setItem(result, TEST_VALUE, SELECTED_IDX);
		expected.arr[SELECTED_IDX] = TEST_VALUE;
	
		printf("test_setItem_normal(): asserting \
			expected.arr[SELECTED_IDX] == result->arr[SELECTED_IDX]\n");
		assert(result->arr[SELECTED_IDX] == expected.arr[SELECTED_IDX]); (*assertion_count)++;

		printf("test_setItem_normal(): asserting \
			result->capacity == expected.capacity\n");
		assert(result->capacity == expected.capacity);(*assertion_count)++;

		printf("test_setItem_normal(): asserting \
			result->size == expected.size\n");
		assert(result->size == expected.size);(*assertion_count)++;

	}

	free(result->arr);
	result->arr = NULL;

	free(expected.arr);
	expected.arr = NULL;
}

/*
 * test_setItem_set_idx_bigger()
 * unit test testing where the set idx is bigger 
 * @return: void
 */
void test_setItem_set_idx_eq (int *assertion_count) { 



}

/*
 * test_removeItem_normal()
 * unit test of intended runthrough
 * @return: void
 */
void test_removeItem_normal (int *assertion_count) {


}

/*
 * test_length_1(), tests lenght function
 * @param: int &assertion_count,
 */
void test_length_1(int *assertion_count){
	
}

