#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


//#include <dos.h>


int main(int argc, char const *argv[])
{

	int pipefd[2];
    pid_t p1, p2;
    char buf[] = "HeLlO wOrLd!";
    char buf2[2];


    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }


    if ((p1 = fork()) == 0)
    {
    	close(pipefd[0]);  
    	write(pipefd[1], buf, sizeof(buf));
    	exit(0);
    }



    if (p1 > 0 && (p2 = fork() == 0))
    {
    	close(pipefd[1]);
    	while(read(pipefd[0], buf2, 1) != 0){
    		printf("%c", toupper(buf2[0]));
 

    	}
    	exit(0);
    }

	return 0;
}