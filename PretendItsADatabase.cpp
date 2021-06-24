#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <unordered_map>

/**
 * 
 * I don't know how to code a database. :(
 * Please accept this instead and pretend it's a database... :O
 * 
 * **/
typedef std::unordered_map<std::string,std::string>::const_iterator databaseRef;

struct PretendItsADatabase {

    std::unordered_map<std::string, std::string> pleasePretendThisIsADatabase = {
        {"BuddyElf","\"N\\v?i4mA*XYcG7x3Z$lHHBS<?bhl,6i^Lv"},
        {"Elfy_McElface","uK_cG>\"l7Y<f;,Ei/Zf[*IN"},
        {"MiniSanta","uu;#Bh-Q`XelRFmw-.#;*!]"}
    };

    std::pair<int, std::string> queryDB(std::string method, std::string username){
        if(method == "GET"){
            // GET password for the given username
            databaseRef dbIter = pleasePretendThisIsADatabase.find(username);

            if (dbIter == pleasePretendThisIsADatabase.end()){
                // couldn't find the username in the "database"
                return std::make_pair(1, "Computer says no. ");
            } else {
                return std::make_pair(0, dbIter->second);
            }

        } else {
            // Well, you're short of luck
            // because I'm not gonna implement the rest
            // since I'd do it wrong anyways and GET is all I need
            // for my project... 
            return std::make_pair(1, "Computer says no. ");
        }
    }

};


int main(int argc, char * argv[]){

    if(argc != 3){printf("Computer says no. "); return(1);}
    PretendItsADatabase db;
    std::pair<int, std::string> res = db.queryDB(argv[1], argv[2]);
    if (res.first == 0){
        printf("%s",res.second.c_str());
    }
}
