/***
 * 
 * Elf Help Centre. 
 * 
 * Gone are the days of keeping a paper list for Santa's naughty and nice list! 
 * Because Santa would like to distribute the list to the worker elves, this program
 * has been created to give elves (but only the elves!) the list of naughty and nice people. 
 * 
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <signal.h>
#include <ctype.h>

#define BUFFSIZE 256

int main(int argc, char * argv[])
{

    // Welcome message
    printf("Welcome to the help centre for Santa's Workshop!\n");
    
    // Get username
    char uname[BUFFSIZE]; 
    int flush;
    printf("Please enter your username: ");
    scanf("%255s", uname);
    while ((flush = fgetc(stdin)) != '\n' && flush != EOF); 

    // Get password and encode
    printf("Please enter the password: ");
    char pword[BUFFSIZE];
    char kword[] = "MerryXM$";
    int index=0;
    scanf("%255s", pword);
    while ((flush = fgetc(stdin)) != '\n' && flush != EOF); 
    while(pword[index] != 0){
        char result[BUFFSIZE];
        int k_index = index % 8;
        if(pword[index] < 32 || pword[index] > 126){printf("Hm. sus input... quiting. \n"); return(1);}
        int vigen = ((((pword[index]-32) + (kword[k_index]-32)) + 95))%95+32;
        pword[index] = vigen;
        index++;
    }

    // Get password from db and check if the password is correct
    char databasePassword[BUFFSIZE] = {'\0'};
    FILE *fp;
    char cmd[BUFFSIZE*2];
    strncpy (cmd, "/home/michelle.nguyen3/PretendItsADatabase GET ", BUFFSIZE*2);
    strncat (cmd, uname, BUFFSIZE*2);
    fp = popen(cmd, "r");
    while (fgets(databasePassword, BUFFSIZE, fp) != NULL){};
    pclose(fp);
    if(databasePassword[0] == '\0'){printf("Incorrect username / password. \n"); return(1);}
    if(strcmp(pword, databasePassword) != 0){printf("Incorrect username / password. \n"); return(1);}

    // Constants
    char NICEFILENAME[] = "/home/michelle.nguyen3/nice.txt";
    char NAUGHTYFILENAME[] = "/home/michelle.nguyen3/naughty.txt";
    char COMMAND[] = "cat";

    while(1){

        // Ask which list to print
        printf("Would you link to print out:");
        printf("\n\t(1) Nice list \n\t(2) Naughty list\n\t(0) Quit Program\n");
        printf("Make selection: ");
        char userinput[2];
        char *ptr;
        scanf("%s", userinput);
        long selection = -1;
        if(isdigit(userinput[0])) selection = strtol(userinput, &ptr, 10);

        // Print out the appropriate list. 
        if (selection == 1){
            // Nice list selected
            printf("\n------Nice List---------\n");
            char * args[] = { COMMAND, NICEFILENAME, NULL };
            execvp(args[0], args);
            return 1;

        } else if (selection == 2){
            // Naughty list selected
            printf("\n------Naughty List------\n");
            char * args[] = { COMMAND, NAUGHTYFILENAME, NULL };
            execvp(args[0], args);
            return 1;

        } else if (selection == 0){
            // Quit program
            printf("\nHappy Holidays! \n");
            break;
        } else {
            // Invalid input
            printf("Invalid input. Please try again.\n\n");
        }
    }

    return 0;
}
