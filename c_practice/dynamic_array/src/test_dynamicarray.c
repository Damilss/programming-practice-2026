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

	printf("Now running test_dynamicarray.c\n");




	return 0;
}

/*
 * test_initArr_1() is the first unit test of initArr()
 * @return: void
 */
static void test_initArr_1 (void) {
	
	intArr *result = initArr();

	intArr expected;
	expected.arr = calloc(10, sizeof(int));
	expcted.capacity = 10;
	expected.size = 0;	

	if (expected.arr == NULL){
		printf("test_initArr_1: test invalid, expected arr pointed is NULL");
		assert (expected.arr != NULL);	
		return;
	}

	assert (result.arr !=NULL);
	assert (result.capacity = 10);
	assert (result.size = 0);	
	
}

/*
 * test_initArr_2() second unit tset of initArr()
 * @return: void
 */
static void test_initArr_2 (void) {


}

/*
 * test_destroyArray_1() first unit test of destroyArr()
 * @return: void
 */
static void test_destoryArr_1 (void) {


}

/*
 * test_destroyarr_2() second unit test of destroyArr()
 * @return: void
 */
static void test_destroyArr_2 (void) {


}


/*
 * test_appendITem_normal() is the intended runthrough of appendItem()
 * @return: void
 */
static void test_appendItem_normal (void) {


}

/*
 * test_appendItem_size_eq_capacity()
 * @return: void
 */
static void test_appendItem_size_eq_capacity (void) {


}

/* test_appendItem_size_gr_capacity()
 * @return: void
 */
static void test_appendITem_size_gr_capacity (void) {


}

/*
 * tset_setItem_normal()
 * @return: void
 */
static void test_setItem_normal (void) { 



}

static void test_setItem_set_idx_bigger (void) { 



}

static void test_removeItem_normal (void) {


}

