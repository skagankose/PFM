#include <stdio.h>
#include <unistd.h>

#define MAX_SZ 256

int tappendFile() {

	FILE *out;
	char textToAppend[4096];
	char fileName[1024];

	printf("Enter text to append: ");
	fgets(textToAppend, MAX_SZ, stdin);

	printf("Enter a existing file name: ");
	scanf("%s", fileName);

	if( access( fileName, F_OK ) == -1 ) {
		printf("Error: There is no such file.\n");
		return(-1);
	}

	out = fopen(fileName, "a");

	if( out == NULL ) {
       printf("Error:Permission Denied!\n");
       return(-1);
    }

	fprintf(out, "%s", textToAppend);
	fclose(out);

	printf("Success.\n");
	return(0);

}
