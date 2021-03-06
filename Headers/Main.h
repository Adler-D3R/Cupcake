#ifndef MAIN_HEADER
#define MAIN_HEADER

//Global Librairies
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

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

//Preparing Voids We're Going To Use Next
void SYSInfoRequest();
void CPUInfoRequest();
void StartThreads();
int NestedStructures();

void Logo()
{
	printf("\n");
	printf("%s   ██████╗██╗   ██╗██████╗  ██████╗ █████╗ ██╗  ██╗███████╗  \n", KPNK);
	printf("%s  ██╔════╝██║   ██║██╔══██╗██╔════╝██╔══██╗██║ ██╔╝██╔════╝  \n", KPNK);
	printf("%s  ██║     ██║   ██║██████╔╝██║     ███████║█████╔╝ █████╗    \n", KPNK);
	printf("%s  ██║     ██║   ██║██╔═══╝ ██║     ██╔══██║██╔═██╗ ██╔══╝    \n", KPNK);
	printf("%s  ╚██████╗╚██████╔╝██║     ╚██████╗██║  ██║██║  ██╗███████╗  \n", KPNK);
	printf("%s   ╚═════╝ ╚═════╝ ╚═╝      ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝  \n", KPNK);
	printf("\n");

        printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n", KPNK);
        printf("%s                    Cupcake - Version %s                   \n", KWHT, CUPCAKE_VERSION);
        printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n \n", KPNK);
}

void ReducedLogo()
{
	printf("\n");
	printf("%s             )  \n", KPNK);
	printf("%s            (.)  \n", KPNK);
	printf("%s            .|.  \n", KPNK);
	printf("%s            l7J  \n", KPNK);
	printf("%s            | |  \n", KPNK);
	printf("%s        _.--| |--._  \n", KPNK);
	printf("%s     .-';  ;`-'& ; `&.  \n", KPNK);
	printf("%s    & &  ;  &   ; ;   \\  \n", KPNK);
	printf("%s    \\      ;    &   &_/  \n", KPNK);
	printf("%s     F'''---...---'''J  \n", KPNK);
	printf("%s     | | | | | | | | |  \n", KPNK);
	printf("%s     J | | | | | | | F  \n", KPNK);
	printf("%s      '---.|.|.|.---'  \n", KPNK);
	printf("\n");

        printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━\n", KPNK);
        printf("%s   Cupcake - Version %s  \n", KWHT, CUPCAKE_VERSION);
        printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━\n \n", KPNK);
}

void MainMenu()
{
	//Alocate Memory To Get Module Number Right After
	char ptr_mod[3];

	//Prints The Main Menu
	printf(" %s0. %sQuit \n", KPNK, KWHT);
	printf(" %s1. %sGet System Informations \n", KPNK, KWHT);
	printf(" %s2. %sGet CPU Informations \n", KPNK, KWHT);
	printf(" %s3. %sThreading Test \n", KPNK, KWHT);
	printf(" %s4. %sNested Structures Example \n", KPNK, KWHT);
	printf(" %s99. %sGet Help \n", KPNK, KWHT);
	printf("\n");

	//Scan For The User Choice
	printf(" >> ");
	scanf("%2s", ptr_mod); //Blocks Buffer To 2 And Stores Result In ptr_mod Value (The One It Points To)
	printf("\n");

	//Let's Check Results So We Know What To Do
	if(strcmp(ptr_mod, "0") == 0 || strcmp(ptr_mod, "00") == 0)
	{
		printf(" Exiting... \n\n"); //We Tell User We Exit
		exit(0); //We're Exiting Cupcake
	}
	else if(strcmp(ptr_mod, "1") == 0 || strcmp(ptr_mod, "01") == 0)
        {
                SYSInfoRequest(); //We Call SysINFO Which Is Going To Check Terminal Size And Call The Appropriate Function
        }
	else if(strcmp(ptr_mod, "2") == 0 || strcmp(ptr_mod, "02") == 0)
        {
                CPUInfoRequest(); //Same Here For CPUInfo
        }
	else if(strcmp(ptr_mod, "3") == 0 || strcmp(ptr_mod, "03") == 0)
        {
                StartThreads(); //Call M-Threading Starter
        }
        else if(strcmp(ptr_mod, "4") == 0 || strcmp(ptr_mod, "04") == 0)
        {
                NestedStructures(); //Call Nested Structure Module Start Function
        }
	else if(strcmp(ptr_mod, "99") == 0)
	{
		printf(" CUPCAKE HELP : \n\n"); //Help Page
		printf("%s - '%s--help%s' : Prints Help Page. \n", KWHT, KPNK, KWHT);
	}

	MainMenu();
}

#endif
