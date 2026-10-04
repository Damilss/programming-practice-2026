#include "test_dynamicarray.h"


#include "dynamicarray.h"

#include <stdio.h>
#include <assert.h>

/*
 * Author: Emilio Scott
 * test_dynamicarray.c has unit test functions for the file dynamicarray.c
 * This file should have 100% coverage for dynamicarray.c
 * This file also includes it's own main
 */

/*
 * main.c is the test runner for this file, calls each function
 * @param: int argc, argument counter
 * @param: char *argv[] is the argument variables
 * @return: int, status code, 0 if succcess, non-zero if something went wrong
 */
int main (int argc, char *argv[]){
	int test_count = 0;
	int assertion_count = 0;

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

	printf("test_appendItem_size_gr_capacity()\n");
	test_appendItem_size_gr_capacity(&assertion_count); test_count ++;
	
	printf("test_setItem_normal\n");
	test_setItem_normal(&assertion_count); test_count++;

	printf("test_setItem_set_idx_bigger()\n");
	test_setItem_set_idx_bigger(&assertion_count); test_count++;

	printf("test_setItem_set_idx_bigger()\n");
	test_removeItem_normal(&assertion_count); test_count++;
	
	printf("%d tests ran\n", test_count);
	printf("%d assertions ran \n", *assertion_count);


	return 0;
}

/*
 * test_initArr_1() is the first unit test of initArr()
 * remember caller of initArr() has to check if (*intArr.arr) != NULL)
 * @param: int &assertion_count, takes the address of a counter to increment
 * @return: void
 */
static void test_initArr_1 (int &asertion_count) {	
	intArr result = initArr();

	intArr expected;
	expected.arr = calloc(10, sizeof(int));
	expcted.capacity = 10;
	expected.size = 0;	

	if (expected.arr == NULL){
		printf("test_initArr_1(): test invalid, expected arr pointed is NULL\n");
		assert (expected.arr != NULL);	
		return;
	}
	
	printf("test_initArr_1(): asserting result.arr != NULL\n");
	assert (result.arr != NULL);

	printf("test_initArr_1(): asserting result.arr != NULL\n");
	assert (result.capacity = 10);

	for (int i = 0; i < result.capacity; i++){
		printf("test_initArr_1(): asserting result.arr index %d intialized to 0\n", i);
		assert (result.arr[i] == 0);
	}
	
	printf("test_initArr_1(): asserting result.size == 0\n");
	assert (result.size == expected.size);

	destroyArr(expected);
	destoryArr(result);
}

/*
 * test_initArr_2() second unit tset of initArr()
 * remember caller of initArr() has to check if (*intArr.arr != NULL)
 * @param: int &assertion_count, takes address of a counter to increment
 * @return: void
 */
static void test_initArr_2 (int &assertion_count) {
	
	intArr result = initArr();
	
	intArr expected;
	expected.arr = calloc (10,sizeof(int));
	expected.capacity = 10;

	if expected.arr == NULL){
		printf("test_initArr_1: test invalid, expewcted arr pointed is NULL");
	
		assert (expected.arr != NULL);
		return;
	}
	printf ("test_initArr_2(): asserting result.arr != NULL\n");
	assert (result.arr != NULL);

	printf ("test_initArr_2(): asserting result.capacity == 10\n");
	assert (result.capacity == expected.capcity);

	printf ("test_initArr_2(): asserting result.size == 0\n");
	assert (result.capacity == expected.capacity);
	
	

}

/*
 * test_destroyArray_1() first unit test of destroyArr()
 * @return: void
 */
static void test_destoryArr_1 (int &assertion_count) {


}

/*
 * test_destroyarr_2() second unit test of destroyArr()
 * @return: void
 */
static void test_destroyArr_2 (&assertion_count) {


}


/*
 * test_appendItem_normal() is the intended runthrough of appendItem()
 * @return: void
 */
static void test_appendItem_normal (&assertion_count) {


}

/*
 * test_appendItem_size_eq_capacity()
 * This test runs through the case where capcity is full and arrray needs to
 * be resized
 * @return: void
 */
static void test_appendItem_size_eq_capacity (&assertion_count) {


}

/* test_appendItem_size_gr_capacity()
 * This test runs through where the capacity is full and array need sot be 
 * resized, but size greater than capacity
 * @return: void
 */
static void test_appendITem_size_gr_capacity (&assertion_count) {


}

/*
 * test_setItem_normal() unit tset of intended run through of setItem()
 * @return: void
 */
static void test_setItem_normal (&assertion_count) { 



}

/*
 * test_setItem_set_idx_bigger()
 * unit test testing where the set idx is bigger 
 * @return: void
 */
static void test_setItem_set_idx_bigger (void) { 



}

/*
 * test_removeItem_normal()
 * unit test of intended runthrough
 * @return: void
 */
static void test_removeItem_normal (void) {


}

