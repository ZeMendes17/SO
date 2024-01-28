#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

void storePersonInfo(Person *p, Person people[], int i)
{
    people[i] = *p;
}


int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    Person people[100];    
    Person p;
    int np, N, i, j, count;

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    //np = fread(people,sizeof(Person),100,fp); // é para ser capaz de escrever no ficheiro


    printf("How many people?\n");
    scanf("%d",&N); // ler o  numero de pessoas a escrever no ficheiro

    count = 0;
    /* read all the itens of the file */
    while(fread(&p, sizeof(Person), 1, fp) == 1)
    {

        storePersonInfo(&p, people,count);
        count++;
    }

     for(i = count ; i < N + count ; i++)
    {    
        printf("Person number %d: \n", i+1);
        printf("Name: ");
        scanf("%s", p.name);
        printf("Age: ");
        scanf("%d", &p.age);
        printf("Height: ");
        scanf("%lf", &p.height);
        printPersonInfo(&p);
        // fwrite(&p, sizeof(Person), 1, fp);
        storePersonInfo(&p, people,i);
    }

    fp = fopen(argv[1], "wb");
    for(j = 0; j < i; j++){
        printPersonInfo(&people[j]);
        fwrite(&people[j], sizeof(Person), 1, fp);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
