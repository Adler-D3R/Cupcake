#ifndef MAIN_HEADER
#define MAIN_HEADER

//Global Librairies
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

//Main Defines
#define DCFA_VERSION "1.0"

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
        printf("%s                    Cupcake - Version V %s                  \n", KWHT, DCFA_VERSION);
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
        printf("%s  Cupcake - Version V %s \n", KWHT, DCFA_VERSION);
        printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━\n \n", KPNK);
}

#endif
