#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
 * is a small employee databse practice with arrays and malloc and structs
 * Author: Emilio Scott
 */

typedef struct Employee {
	char* name;
	int salary;
}Empl;

double avrgSal(Empl* employee, int size);

int minSal(Empl* employee, int size);

int maxSal(Empl* employee, int size);

void printEmployees(Empl* employee, int size);


int main(int argc, char* argv[]){
	
	srand(time(NULL));
	Empl* employeedatabase = (Empl*)malloc(sizeof(Empl)*10);	
	Empl* employee1 = (Empl*)malloc(sizeof(Empl));
	Empl* employee2 = (Empl*)malloc(sizeof(Empl));
	Empl* employee3 = (Empl*)malloc(sizeof(Empl));
	Empl* employee4= (Empl*)malloc(sizeof(Empl));
	
	employee1->name = "Sam";
	employee1->salary = rand() % 100001 + 100000;
	employee2->name = "Jenice";
	employee2->salary = rand() % 100001 + 100000;
	employee3->name = "Tom";
	employee3->salary = rand() % 100001 + 100000;
	employee4->name  = "Jack";
	employee4->salary = rand() % 100001 + 100000;

	employeedatabase[0] = *employee1;
	employeedatabase[1] = *employee2;
	employeedatabase[2] = *employee3;
	employeedatabase[3] = *employee4;
	
	printf("The average salary is %0.2lf\n", avrgSal(employeedatabase, 4));	
	return 0;
}

double avrgSal(Empl* employee, int size){

	int sum = 0;
	for ( int i = 0; i < size; i++ ){
		sum = sum + (employee + i)->salary;
	}

	return (sum/size);
}

