
#include "LinkedListAPI.h"

typedef struct car {
	char *model;
	char *serial;
	int year;
}Car;

char* printCar(void *a) {
	
	char *toReturn;
	int length;
	Car *toBePrinted;
	
	toBePrinted = (Car *)a;
	
	length = strlen(toBePrinted->model) + strlen(toBePrinted->serial) + 11 + 20 + 1;
	toReturn = malloc(sizeof(char) * length);
	
	sprintf(toReturn, "%s %d, serial: %s", toBePrinted->model, toBePrinted->year, toBePrinted->serial);
	
	return toReturn;
}

int compareCar(const void *a, const void *b) {
	
	Car *carOne;
	Car *carTwo;
	
	carOne = (Car *)a;
	carTwo = (Car *)b;
	
	return strcmp(carOne->serial, carTwo->serial);
}

void deleteCar(void *a) {
	
	Car *toBeDeleted;
	toBeDeleted = (Car*)a;
	
	free(toBeDeleted->model);
	free(toBeDeleted->serial);
	free(toBeDeleted);
	
	return;
}
	

int main(void) {
	
	List *carList;
	Car *tmpCar;
	Car *checkCar;
	char *j;
	char *str;
	ListIterator ptr;
	
	j = malloc(sizeof(char)*2);
	carList = initializeList(&printCar, &deleteCar, &compareCar);
	
	for(int i = 1; i <= 7; i++) {
		
		sprintf(j, "%c", i + 82); 
		
		tmpCar = malloc(sizeof(Car));
		
		tmpCar->year = 2013 + i;
		
		tmpCar->model = malloc(sizeof(char) * 8);
		strcpy(tmpCar->model, "Model ");
		strcat(tmpCar->model, j);
		
		tmpCar->serial = malloc(sizeof(char) * 7);
		strcpy(tmpCar->serial, "ABCDE");
		strcat(tmpCar->serial, j);
		
		insertSorted(carList, (void *)tmpCar);
		
		tmpCar++;
		
	}
	
	ptr = createIterator(carList);
	checkCar = (Car *)nextElement(&ptr);
	
	while( checkCar != NULL ) {
		
		str  = carList->printData(checkCar);
		printf("%s\n", str);
		free(str);
		checkCar = (Car *)nextElement(&ptr);
		
	}
	
	printf("TESTING: clearList\n");
	clearList(carList);
	if(carList->length != 0) {
		printf("FAILED: length is not zero\n");
	}
	if(carList->head != NULL || carList->tail != NULL) {
		printf("FAILED: list not cleared (nodes still in head/tail)\n");
	}
	
	free(checkCar);
	free(j);
	freeList(carList);
	
	return 0;
}
