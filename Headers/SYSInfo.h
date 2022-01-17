#ifndef SYSINFO_HEADER
#define SYSINFO_HEADER

//Global Librairies
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>

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

void GetSYSInfo();
void GetSYSInfoReduced();

void SYSInfoRequest()
{
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

        if(w.ws_row > 25 && w.ws_col > 133)
        {
                GetSYSInfo();
        }
        else
        {
                GetSYSInfoReduced();
        }
}

void GetSYSInfo()
{
        printf("%s ─────────────────────────────────────────────────────────── \n", KPNK);
        printf("%s                      SYSTEM INFORMATIONS                    \n", KWHT);
        printf("%s ─────────────────────────────────────────────────────────── %s\n\n", KPNK, KWHT);

        struct utsname ubuff; errno = 0;
        if(uname(&ubuff) != 0) {
                perror(" Unable to retrieve System Informations. \n Exiting...");
                exit(EXIT_FAILURE);
        }

        printf("%s System Name : %s%s \n", KPNK, KWHT, ubuff.sysname);
        printf("%s Node Name : %s%s \n", KPNK, KWHT, ubuff.nodename);
        printf("%s Distro : %s%s \n", KPNK, KWHT, ubuff.version);
        printf("%s Release : %s%s \n", KPNK, KWHT, ubuff.release);
        printf("%s Machine : %s%s \n", KPNK, KWHT, ubuff.machine);
        printf("%s Domain Name : %s%s \n", KPNK, KWHT, ubuff.__domainname);
	printf("\n");
}

void GetSYSInfoReduced()
{
	printf("%s ───────────────────────── \n", KPNK);
	printf("%s    SYSTEM INFORMATIONS   \n", KWHT);
	printf("%s ───────────────────────── %s\n\n", KPNK, KWHT);

	struct utsname ubuff; errno = 0;
   	if(uname(&ubuff) != 0) {
      		perror(" Unable to retrieve System Informations. \n Exiting...");
		exit(EXIT_FAILURE);
   	}

	printf("%s System Name : %s%s \n", KPNK, KWHT, ubuff.sysname);
  	printf("%s Node Name : %s%s \n", KPNK, KWHT, ubuff.nodename);
   	printf("%s Distro : %s%s \n", KPNK, KWHT, ubuff.version);
   	printf("%s Release : %s%s \n", KPNK, KWHT, ubuff.release);
   	printf("%s Machine : %s%s \n", KPNK, KWHT, ubuff.machine);
	printf("%s Domain Name : %s%s \n", KPNK, KWHT, ubuff.__domainname);
	printf("\n");
}

#endif
