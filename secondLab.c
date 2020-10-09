#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	//FILE *file;
	char name[] = "file.txt";
	int strLength = 0, num, i = 0, position = 0;

	int file1;

	file1 = open(name, O_RDONLY);
	
	int *lengths = NULL;
	int *positions = NULL;


	char buff[64];

	lengths = (int*)malloc(1 * sizeof(int));
    
    while(read(file1, buff, 1) != 0){
    	if (buff[0] == '\n')
    	{
    		lengths[i] = strLength;
    		i++;
    		position = lseek(file1, 0, SEEK_CUR);
    		positions = (int*)realloc(positions, (i+1) * sizeof(int));
    		lengths = (int*)realloc(lengths, (i+1) * sizeof(int));
    		positions[i] = position;

    		strLength = 0;
    	}else{
 		   	strLength++;
    	}

    }

    lengths[i] = strLength;
    positions = (int*)realloc(positions, (i + 2) * sizeof(int));
    positions[i+1] = lseek(file1, 0, SEEK_END);

	do{
		memset(buff, 0, 64);
		printf("\nВведите номер строки\n");
		scanf("%d", &num);
		if(num > i+1){
			printf("В файле всего %d строк(и), введите номер строки из этого диапазона\n", i+1);
		}else if(num != 0){
			lseek(file1, positions[num-1], SEEK_SET);
			strLength = lengths[num-1];
			read(file1, buff, strLength);
			printf("\n%s, длина %d\n", buff, strLength);
		}

	} while(num != 0);


/*	for (int n = 0; n < i; n++){
	    printf("\n%d, %d\n", positions[n], lengths[n]);
	}	*/

	

	close(file1);
	free(positions);
	free(lengths);




	return 0;
}