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

	int ch, strLength = 0;
	int num, i = 0, position = 0;

	//file = fopen(name, "r");

	int file1;
	file1 = open(name, O_RDONLY);
	int arr[255];
	int *lenghts = NULL;
	int *positions = NULL;


	char buff[64];

	arr[0] = 0;
	//lenghts = (int*)realloc(lenghts, 1 * sizeof(int));
    
    while(read(file1, buff, 1) != 0){
    	//strLenght++;
    	if (buff[0] == '\n')
    	{
    		//lenghts[i] = strLenght;
    		i++;
    		position = lseek(file1, 0, SEEK_CUR);
    		//printf("\n|%d, %d|\n", i, position);
    		positions = (int*)realloc(positions, (i) * sizeof(int));
    		//lenghts = (int*)realloc(lenghts, (i) * sizeof(int));
    		positions[i] = position;

    		//strLenght = 0;
    	}
    	//printf("%s", buff);

    }
    
	do{
		printf("Введите номер строки\n");
		scanf("%d", &num);
		lseek(file1, positions[num-1], SEEK_SET);
		strLength = positions[num] - positions[num-1];
		read(file1, buff, strLength);
		printf("\n%s\n", buff);

	} while(num != 0);

	printf("\n%d\n", positions[0]);
	printf("%d\n", positions[1]);
	printf("%d\n", positions[2]);
	printf("%d\n", positions[3]);
	printf("%d\n", positions[2] - positions[1]);
	


    /*printf("\n%d, %d\n", positions[0], lenghts[0]);
    printf("\n%d, %d\n", positions[1], lenghts[1]);
    printf("\n%d, %d\n", positions[2], lenghts[2]);
    printf("\n%d, %d\n", positions[3], lenghts[3]);*/

  


    //printf("Содержимое файла:%s\nВсего прочитано: %i\n", buff, count);
    


	

	close(file1);



	return 0;
}