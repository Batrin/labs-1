#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int pid;
	int status;

	switch(pid = fork())
		{
		  case -1: 
		  	perror(1);
		  case 0: 
		  	printf("descendant %d ", pid);
		  	printf("%s\n", argv[1]);
		  	execvp(argv[1], &argv[1]);
		  	exit(0);
		  default: 
		  	waitpid(pid, &status, 0);
		  	printf("parent %d status %d\n", pid, WEXITSTATUS(status));
		  	break;
		}
	return 0;
}