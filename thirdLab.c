#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <fcntl.h>

#include <sys/mman.h>

int main(int argc, char const *argv[])
{
	char name[] = "file.txt";
	int strLength = 0, num, i = 0, position = 0, k = 0;

	int file1;

	file1 = open(name, O_RDONLY);

	int len = lseek(file1, 0, SEEK_END);

	void *src;
	char *findPtr;

	if((src = mmap(0, len, PROT_READ, MAP_SHARED, file1, 0)) == MAP_FAILED){
		perror("mmap error");
	}
		
	int *lengths = NULL;
	int *positions = NULL;
	lengths = (int*)malloc(1 * sizeof(int));

	findPtr = src;

	while(findPtr[k] != 0){
    	if (findPtr[k] == '\n')
    	{
    		lengths[i] = strLength;
    		i++;
    		position = k + 1;
    		positions = (int*)realloc(positions, (i+1) * sizeof(int));
    		lengths = (int*)realloc(lengths, (i+1) * sizeof(int));
    		positions[i] = position;

    		strLength = 0;
    	}else{
 		   	strLength++;
    	}
    	k++;

    }

    lengths[i] = strLength;
    positions = (int*)realloc(positions, (i + 2) * sizeof(int));
    positions[i+1] = lseek(findPtr, 0, SEEK_END);

	for (int k = 0; k < i; k++)
	{
		printf("pos %d, len %d\n", positions[k], lengths[k]);
	}

	do{
		printf("\nВведите номер строки\n");
		scanf("%d", &num);
		if(num > i+1){
			printf("В файле всего %d строк(и), введите номер строки из этого диапазона\n", i+1);
		}else if(num != 0){
			strLength = lengths[num-1];
			k = 0;
			while(k < strLength){
				printf("%c", findPtr[positions[num-1] + k]);
				k++;
			}
		}

	} while(num != 0);
	
	






	return 0;
}