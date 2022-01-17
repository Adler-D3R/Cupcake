#ifndef CPUINFO_HEADER
#define CPUINFO_HEADER

//Global Librairies
#include <stdio.h>
#include <stdlib.h>

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

void GetCPUInfo();
void GetCPUInfoReduced();

void CPUInfoRequest()
{
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

        if(w.ws_row > 25 && w.ws_col > 133)
        {
                GetCPUInfo();
        }
        else
        {
                GetCPUInfoReduced();
        }
}

void GetCPUInfo()
{
        printf("%s ─────────────────────────────────────────────────────────── \n", KPNK);
        printf("%s                       CPU INFORMATIONS                      \n", KWHT);
        printf("%s ─────────────────────────────────────────────────────────── %s\n\n", KPNK, KWHT);

        FILE *fp;
        char path[1024];

        // MODEL NAME
        // Open The Command To Read Its Output
        fp = popen("cat /proc/cpuinfo | grep name | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }

        // Reads The Output A Line At A Time
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sModel Name :%s%s", KPNK, KWHT, path);
        }

        //We Don't Need It Anymore. Let's Close The File.
        pclose(fp);

        //CORE NUMBER
        fp = popen("cat /proc/cpuinfo | grep cores | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sCPU Cores :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

        //CPU FREQUENCY
        fp = popen("cat /proc/cpuinfo | grep MHz | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sCPU Frequency [MHz] :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

        //CACHE SIZE
        fp = popen("cat /proc/cpuinfo | grep cache | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sCache Size :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

        //VENDOR ID
        fp = popen("cat /proc/cpuinfo | grep vendor_id | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sVendor ID :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

        //MICROCODE
        fp = popen("cat /proc/cpuinfo | grep microcode | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sMicrocode :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

        //ADDRESS SIZES
        fp = popen("cat /proc/cpuinfo | grep address | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sAddress Sizes :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

	printf("\n");
}

void GetCPUInfoReduced()
{
	printf("%s ───────────────────────── \n", KPNK);
	printf("%s     CPU INFORMATIONS     \n", KWHT);
	printf("%s ───────────────────────── %s\n\n", KPNK, KWHT);

	FILE *fp;
	char path[1024];

	// MODEL NAME
	// Open The Command To Read Its Output
	fp = popen("cat /proc/cpuinfo | grep name | cut -d ':' -f 2", "r");
	if (fp == NULL) {
	  printf("Failed to run command\n" );
	  exit(1);
	}

	// Reads The Output A Line At A Time
	while (fgets(path, sizeof(path), fp) != NULL) {
	  printf(" %sModel Name :%s%s", KPNK, KWHT, path);
	}

	//We Don't Need It Anymore. Let's Close The File.
	pclose(fp);

	//CORE NUMBER
        fp = popen("cat /proc/cpuinfo | grep cores | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sCPU Cores :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

	//CPU FREQUENCY
        fp = popen("cat /proc/cpuinfo | grep MHz | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sCPU Frequency [MHz] :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

	//CACHE SIZE
        fp = popen("cat /proc/cpuinfo | grep cache | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sCache Size :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

	//VENDOR ID
        fp = popen("cat /proc/cpuinfo | grep vendor_id | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sVendor ID :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

	//MICROCODE
        fp = popen("cat /proc/cpuinfo | grep microcode | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sMicrocode :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

	//ADDRESS SIZES
        fp = popen("cat /proc/cpuinfo | grep address | cut -d ':' -f 2", "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        }
        while (fgets(path, sizeof(path), fp) != NULL) {
          printf(" %sAddress Sizes :%s%s", KPNK, KWHT, path);
        }
        pclose(fp);

	printf("\n");
}

#endif
