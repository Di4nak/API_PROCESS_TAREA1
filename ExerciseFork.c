#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]){
	
	int contador = 1;
	int rc= fork();
	
	if(rc < 0){
		fprintf(stderr,"Fork error\n");
		exit(1);
	}else if(rc==0){
		contador+=5;
		printf("child count: %d\n",contador);		
	}else{
		contador +=2;
		printf("parent count: %d\n",contador);
	}
	return 1;
}
