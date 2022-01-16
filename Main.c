//D.C.F.A. Header
#include "Headers/Main.h"

//Color Defines
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define KBLK  "\x1B[30m"

int main(int argc, char *argv[])
{

	//Get Window Size
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	//If Window Is Too Small, Print Reduced Logo
	if(w.ws_row > 25 && w.ws_col > 133)
	{
		Logo(); //Normal Logo
	}
        else
        {
		ReducedLogo(); // Reduced Logo
        }

	//Args Analyser - Creating "i" Properly
	int* ptr_i = NULL; //Initialize Pointer Of Integer "i"
	ptr_i = malloc(sizeof(ptr_i)); //Set Pointer Value To Provided Memory Adress

	//Check If It Received Adress Properly
	if(ptr_i == NULL)
	{
		printf("%s [FATAL] Error While Allocating Adress To ptr_i ! \n Exiting Now...", KRED); //ptr_i Didn't Receive The Adress ! We Must Exit Before We Damage The Computer (Not Enough RAM)
		exit(0); //Exit Program
	}

	//If We Got Here, Everything Is Alright :)
	*ptr_i = 0; // Sets "i" Value To 0

	//Args Analyser - Gets All Provided Args
	for (int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0)
                {
                        printf(" %s[%sINFO%s] Printing Version ... \n", KWHT, KBLU, KWHT);
                }

		if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
                {
                        printf(" %s[%sINFO%s] Printing Help ... \n", KWHT, KBLU, KWHT);
                }
	}

	free(ptr_i); //We Don't Need "i" Anymore. Let's Free It So That We Free RAM (Pure Optimization)

	//MainMenu();
	return 0;
}
