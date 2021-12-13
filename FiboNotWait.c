#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
	int fibo = 50;
	int rc = fork();
	
	if(rc < 0){
		fprintf(stderr,"Fork failed\n");
		exit(1);
	}
	
	else if(rc == 0){
		int i;
		int t1 = 0, t2 = 1;
		int sum = t1+t2;
		
		printf("%d\n",t1);
		printf("%d\n",t2);
		
		for(i=3;i<=fibo;++i){
			printf("%d\n",sum);
			t1 = t2;
			t2 = sum;
			sum = t1 +t2;
		}
	}else{
		printf("parent: soy el padre\n");
	}
	
	return 0;
}
