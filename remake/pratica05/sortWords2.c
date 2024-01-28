#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sortCrescente(const void *p1, const void *p2){
	char *px1 = *((char **) p1);
	char *px2 = *((char **) p2);

	return strcasecmp(px1,px2);
}

int main(int argc, char **argv){

	int counter = 0;
	char *line = malloc(sizeof(char) * 100);
	char **words = malloc(sizeof(char *));

    fprintf(stderr,"Digite palavras (END para terminar)\n");
	while(1){
		scanf("%s",line);

		if(strcmp(line,"END") == 0){
			break;
		}
		counter++;
		words = (char **) realloc(words, counter*sizeof(char *));
		words[counter - 1] = strdup(line);
	}

	qsort(words, counter, sizeof(char *), sortCrescente);

	for (int i = 0 ; i < counter ; i++)
		printf("%s ",words[i]);
	printf("\n");


}