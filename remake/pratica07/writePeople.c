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
    int i, num_people;
    Person p = {35, 1.65, "xpto"};

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    printf("Number of people: ");
    scanf("%d", &num_people);
    for(i = 0 ; i < num_people ; i++)
    {    
        printf("Person number %d: \n", i+1);
        printf("Name: ");
        scanf("%s", p.name);
        printf("Age: ");
        scanf("%d", &p.age);
        printf("Height: ");
        scanf("%lf", &p.height);
        printPersonInfo(&p);
        fwrite(&p, sizeof(Person), 1, fp);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
