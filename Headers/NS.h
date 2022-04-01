#ifndef NESTED_STRUCTURES_HEADER
#define NESTED_STRUCTURES_HEADER

//Global Librairies
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//Main Defines
#define CUPCAKE_VERSION "1.0"

//Color Defines
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KPNK  "\x1b[95m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define KBLK  "\x1B[30m"

int NestedStructures();
void TraceLine();

struct UnderSub
{
    int integer;
};

struct AnotherSub
{
    int age;
    char name[20];
    char surname[20];
    struct UnderSub* under_sub;
};

struct Sub
{
    int age;
    char name[20];
    char surname[20];
    struct UnderSub* under_sub;
};

struct Main
{
    int id;
    struct Sub* sub;
    struct AnotherSub* another_sub;
};

void TraceLine(int lenght)
{
    for (int i = 0; i < lenght; i++)
        printf("━");
}

int NestedStructures()
{
    struct Main* main;

    main = malloc(sizeof(*main));
    if (main == NULL)
    {
        printf("%s Could Not Allocate Memory. Exiting... [-1] \n", KRED);
        return -1;
    }

    main->id = 1;

    main->sub = malloc(sizeof(*(main->sub)));
    if (main->sub == NULL)
    {
        printf(" Could Not Allocate Memory. Exiting... [-1] \n");
        free(main);
        return -1;
    }

    main->another_sub = malloc(sizeof(*(main->another_sub)));
    if (main->another_sub == NULL)
    {
        printf("%s Could Not Allocate Memory. Exiting... [-1] \n", KRED);
        free(main);
        return -1;
    }

    main->sub->under_sub = malloc(sizeof(*(main->sub->under_sub)));
    if (main->sub->under_sub == NULL)
    {
        printf("%s Could Not Allocate Memory. Exiting... [-1] \n", KRED);
        free(main);
        return -1;
    }

    main->another_sub->under_sub = malloc(sizeof(*(main->another_sub->under_sub)));
    if (main->another_sub->under_sub == NULL)
    {
        printf("%s Could Not Allocate Memory. Exiting... [-1] \n", KRED);
        free(main);
        return -1;
    }

    printf(" Enter Name (String) [Sub] >> ");
    if (scanf("%19s", main->sub->name) != 1)
    {
        printf("%s Error : Invalid Input ! Exiting [-1] \n", KRED);
        free(main->sub);
        free(main);
        return -1;
    }

    printf(" Enter Surname (String) [Sub] >> ");
    if (scanf("%19s", main->sub->surname) != 1)
    {
        printf("%s Error : Invalid Input ! Exiting [-1] \n", KRED);
        free(main->sub);
        free(main);
        return -1;
    }

    printf(" Enter Age (Integer) [Sub] >> ");
    if (scanf("%d", &main->sub->age) != 1)
    {
        printf("%s Error : Invalid Input ! Exiting [-1] \n", KRED);
        free(main->sub);
        free(main);
        return -1;
    }

    printf("\n");

    printf(" Enter Name (String) [Another Sub] >> ");
    if (scanf("%19s", main->another_sub->name) != 1)
    {
        printf("%s Error : Invalid Input ! Exiting [-1] \n", KRED);
        free(main->another_sub);
        free(main);
        return -1;
    }

    printf(" Enter Surname (String) [Another Sub] >> ");
    if (scanf("%19s", main->another_sub->surname) != 1)
    {
        printf("%s Error : Invalid Input ! Exiting [-1] \n", KRED);
        free(main->another_sub);
        free(main);
        return -1;
    }

    printf(" Enter Age (Integer) [Another Sub] >> ");
    if (scanf("%d", &main->another_sub->age) != 1)
    {
        printf("%s Error : Invalid Input ! Exiting [-1] \n", KRED);
        free(main->another_sub);
        free(main);
        return -1;
    }

    printf("\n");

    printf(" Under Sub (Integer) [1] >> ");
    if (scanf("%d", &main->sub->under_sub->integer) != 1)
    {
        printf("%s Error : Invalid Input ! Exiting [-1] \n", KRED);
        free(main->sub->under_sub);
        free(main);
        return -1;
    }

    printf(" Under Sub (Integer) [2] >> ");
    if (scanf("%d", &main->another_sub->under_sub->integer) != 1)
    {
        printf("%s Error : Invalid Input ! Exiting [-1] \n", KRED);
        free(main->another_sub->under_sub);
        free(main);
        return -1;
    }

    //printf("\n");
    //printf("ID : %d\n", main->id);
    
    printf("\n");

    TraceLine(11);
    printf(" SUB DATA ");
    TraceLine(11);

    printf("\n");

    printf(" Name : %s\n", main->sub->name);
    printf(" Surname : %s\n", main->sub->surname);
    printf(" Age : %d\n", main->sub->age);
    printf("\n");

    TraceLine(7);
    printf(" ANOTHER SUB DATA ");
    TraceLine(7);

    printf("\n");

    printf(" Name : %s\n", main->another_sub->name);
    printf(" Surname : %s\n", main->another_sub->surname);
    printf(" Age : %d\n", main->another_sub->age);

    printf("\n");

    TraceLine(8);
    printf(" UNDER SUB DATA ");
    TraceLine(8);

    printf("\n Under Sub Integer [1] : %d\n", main->sub->under_sub->integer);
    printf(" Under Sub Integer [2] : %d\n", main->another_sub->under_sub->integer);

    printf("\n\n");

    free(main->sub->under_sub);
    free(main->another_sub->under_sub);
    free(main->another_sub);
    free(main->sub);
    free(main);
}

#endif
