#include <stdio.h>

#define DSIZE 1000

void growarrayfile();
int** growarray();
//void array_by_value(int[][]);
void array_by_reference(int*, int,int);

void mdarray(int array[]){
	printf("%d\n",array[0]);
}

void growarrayfile(){
	int i, j;
	int thearray[DSIZE][DSIZE];
	FILE *of1;
	of1 = fopen("file1.txt","w");
	for(i = 0; i<DSIZE; i++){
		for(j=0; j<DSIZE; j++){
			thearray[i][j] = 1;
			fprintf(of1,"[%d][%d] -> %d \n",i,j,thearray[i][j]);
		}
	}
  //  return thearray;
 } 

int** growarray(){
	int i, j;
	int thearray[DSIZE][DSIZE];
	for(i = 0; i<DSIZE; i++){
		for(j=0; j<DSIZE; j++){
			thearray[i][j] = 1;
			//printf("[%d][%d] -> %d \n",i,j,thearray[i][j]);
		}
	}
	return thearray;
}

void array_by_value(int anArray[DSIZE][DSIZE]){
	int i,j;
	for(i = 0; i<DSIZE; i++){
		for(j=0; j<DSIZE; j++){
			anArray [i][j] = 1;
			printf("[%d][%d] -> %d \n",i,j,anArray[i][j]);
		}
 	}
} 
void array_by_reference(int *anArray, int cols, int rows){
	int i,j;
	for(i = 0; i<cols; i++){
		for(j=0; j<rows; j++){
			*(anArray + (i*cols) + j) = -1;
			printf("[%d][%d] -> %d \n",i,j,*(anArray + (i*cols) + j));
		}
	}
}



int main(int argc, char *argv[]){
	
	int a;
	while(--argc>0){
		a = atoi(*++argv);
		switch(a){
			case 1:{
				growarray();
				printf("growarray\n");
				break;
			}
			case 2:{
				growarrayfile();
				printf("growarrayfile\n");
				break;
			}			
			case 3:{
				array_by_value(growarray());
				printf("array_by_value\n");
				break;
			}			
			case 4:{
				array_by_reference(growarray(),DSIZE,DSIZE);
				printf("array_by_reference\n");
				break;
			}
			case 5:{
				printf("test case\n");
				break;
			}
			default:{
				printf("y que paso?\n");
				break;
			}	
		}
	}
	printf("por favor ingrese el numero de alguna opcion\n");
	return 0;
}