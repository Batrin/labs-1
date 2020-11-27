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
    char buf2[1] = "l";

    /*if (argc != 2) {
        fprintf(stderr, "Использование: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }*/
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    //cpid = fork();


    if ((p1 = fork()) == 0)
    {
    	//close(pipefd[0]);  
    	write(pipefd[1], buf, 20);
    	exit(0);
    }

    	/*if (p1 > 0)
    	{
    		close(pipefd[1]);
    	printf("%c", pipefd[0]);
    		
    	}*/

    if (p1 > 0 && (p2 = fork() == 0))
    {
    	close(pipefd[1]);
    		printf("%s", buf2);
    	/*while(read(pipefd[0], buf2, 1) != 0){
    		//sleep(1);
    		//delay(5000);

    	}*/
    	exit(0);
    }






/*    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (cpid == 0) {    //Потомок читает из канала 
        close(pipefd[1]);          //Закрывает неиспользуемый конец для записи 
        while (read(pipefd[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);
    } else {            //Родитель пишет значение argv[1] в канал 
        close(pipefd[0]);          // Закрывает неиспользуемый конец для чтения 
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);          // Читатель видит EOF 
        wait(NULL);                // Ожидание потомка 
        exit(EXIT_SUCCESS);
    }*/


	return 0;
}