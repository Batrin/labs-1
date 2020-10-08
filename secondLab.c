#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	//FILE *file;
	char name[] = "file.txt";
	char str[255];
	char sym;
    int count = 0; 

	int ch;
	int num, i = 0, position = 0;

	//file = fopen(name, "r");

	int file1;
	file1 = open(name, O_RDONLY);
	int arr[255];

	char buff[64];

	arr[0] = 0;
    
	do{
		printf("Введите номер строки");
		scanf("%d", &num);
		lseek(file1, arr[num], SEEK_SET);

	    while(read(file1, buff, 1) != 0){
	    	if (buff[0] == '\n')
	    	{
	    		i++;
	    		position = lseek(file1, 0, SEEK_CUR);
	    		printf("\n|%d, %d|\n", i, position);
	    		arr[i] = position;
	    	}
	    	printf("%s", buff);

	    }
	} while(num != 0);

    printf("\n%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
    printf("%d\n", arr[3]);



    //printf("Содержимое файла:%s\nВсего прочитано: %i\n", buff, count);
    


	

	close(file1);



	return 0;
}