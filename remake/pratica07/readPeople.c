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

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    Person p;
    Person people[100];
    int i,j,num_people;
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

    /* read all the itens of the file */
    i = 0;
    while(fread(&p, sizeof(Person), 1, fp) == 1)
    {
        people[i] = p; 
        // printPersonInfo(&people[i]);
        i++;
    }
    
    printf("Number of people: ");
    scanf("%d", &num_people);
    for(j = 0 ; j < num_people ; j++)
    {    
        printf("Person number %d: \n", i+1);
        printf("Name: ");
        scanf("%s", p.name);
        printf("Age: ");
        scanf("%d", &p.age);
        printf("Height: ");
        scanf("%lf", &p.height);
        // printPersonInfo(&p);
        people[i] = p; 
        i++;
        // fwrite(&p, sizeof(Person), 1, fp);
    }
    fp = fopen(argv[1], "wb");

    for(j = 0; j < i; j++){
        printPersonInfo(&people[j]);
        fwrite(&people[j], sizeof(Person), 1, fp);
    }
    fclose(fp);

    return EXIT_SUCCESS;
}
