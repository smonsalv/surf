// #include <stdio.h>

// int main(int argc, char * argv[]){
// 	while(--argc>0){
// 		printf("%s \n", *++argv);
// 	}
// 	return 0;
// }

#include <stdio.h>

main(int argc, char *argv[]) {
	while (--argc > 0){
		 printf("%s", *++argv);
// 		 printf("%s%s", *++argv, (argc > 1) ? " " : "");
	}
return 0;
}
