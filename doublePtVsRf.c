#include <stdio.h>
#include <time.h>

#define RAND_MAX 10e10
#define SIZE 100000

double array[SIZE][SIZE];

double fRandVal(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

double* fRandRef(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    f =  fMin + f*(fMax -fMin);
    return &f;
}

void fillarrayValue(){
	int i, j;
	double d;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			d=fRandVal(1.000,100.000);
			array[i][j] = d;
			//printf("%e\n", d);
		}
	}
}

void fillarrayReference(){
	int i, j;
	double d;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			d=*fRandRef(1.000,100.000);
			array[i][j] = d;
			//printf("%e\n", d);
		}
	}
}

int main(int argc, char* argv[]){
	int a;
	while(--argc>0){
		a = atoi(*++argv);
		switch(a){
			case 1:{
				fillarrayValue();
				printf("double by Value\n");
				break;
			}			
			case 2:{
				fillarrayReference();
				printf("double by Reference\n");
				break;
			}
			default:{
				printf("Not Valid Option!\n");
				break;
			}	
		}
	}
	// printf("Please select some option number\n");
	return 0;
}