#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int pid;
	int status;

	//fork();

	switch(pid = fork())
		{
		  case -1: 
		  	puts("error");/*при вызове fork() возникла ошибка*/
		  	break;
		  case 0: 
		  	printf("descendant %d ", pid);
		  	sleep(3);
		  	printf("%s\n", argv[1]);
		  	execvp(argv[1], argv);
		  	exit(0);
		  	break;
		  default: 
		  	printf("parent %d status %d\n", pid, WEXITSTATUS(status));/*это код родительского процесса*/
		  	sleep(3);
		  	waitpid(pid, &status, 0);
		  	break;
		}

	//puts("Hello, World!");
	//sleep(10);
	return 0;
}