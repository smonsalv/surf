2#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOP 1000000
#define CICLE 10000
//#define RAND_MAX 100
#define frand() ((double) rand() / (RAND_MAX+1.0))

//const long long TOP = 1000000;

long long counter; 

int theArray[TOP];

int random_number(int min_num, int max_num);
void pontVsArray();
void fill_array();
void print_array();
void call_array();
void double_call_by_value();
void double_call_by_reference();
void print_double(double thedouble);
void call_funtion();

int main(int argc, char *argv[]){
	int a = 0;
	while(--argc>0){
		a =  atoi(*++argv);
	}
	switch(a){
	case 1:{
		printf("Pointer Vs Array Test: \n");
		//fill_array();	
		break;
	}
	case 2:{
		printf("Value Vs Reference Test: \n");
		//print_array();	
		break;
	}
	case 3:{
		printf("Printf Vs fwrite Test: \n");
		break;
	}
	case 4:{
		printf("double_call_by_value\n");
		double_call_by_value();
		break;
	}
	case 5:{
		printf("fill the array\n");
		fill_array();
		break;
	}
	case 6:{
		printf("print the array\n");
		print_array();
		break;
	}
	case 7:{
		call_funtion();
		break;
	}
	default:
		printf("Wrong Comand");

	
	} 
	return 0;		
}

void pointVsArray(){
	for(counter=0;counter<TOP;counter++){
		//pointVsArray();
	}
}

void fill_array(){
	for(counter=0;counter<TOP;counter++){
		srand (time(NULL));
		//theArray[counter] = random_number(0,100);
		theArray[counter] = frand();
	}
}

void print_array(){
	for(counter = 0; counter < TOP; counter++){
		printf(" %d, -> %d \n", counter, theArray[counter]);
	}	
}

void double_call_by_value(double d){
	double rand1 = frand();
	print_double(rand1);
}

void print_double(double d2){
	printf("%e\n", d2);
}

void call_funtion(){
	int i,r;
	for(i=0;i<CICLE;i++){
		r = random_number(1,100);
		printf("%d -> %d \n", i, r);
	}
}


int random_number(int min_num, int max_num){
	int result=0,low_num=0,hi_num=0;
	if(min_num<max_num)	{
		low_num=min_num;
        hi_num=max_num+1; // this is done to include max_num in output.
    }else{
        low_num=max_num+1;// this is done to include max_num in output.
        hi_num=min_num;
	}
	srand(time(NULL));
	result = (rand()%(hi_num-low_num))+low_num;
	return result;
}
        

