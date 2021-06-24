
Ho Ho Ho! It's that wonderful time of the year again-- there are only a few days until Christmas!

Oh wait- uh oh, you haven't been nice this year? 
Certainly you must be on the naughty list then... 
But fret not! It just so happens that the database for Santa's Workshop / Elf Help Centre has been leaked!
The Elf Help Centre contains the electronic list the elves keep for knowing who is nice and gets a present,
and who is naughty and will go hell-- er no, nevermind- I guess, they just won't get a present is all. 

Here is are the entries from the database:
(Note none of these have leading or following spaces). 

-----------------------------------------------------------------------------
|== Elf Employee Username == | ================= Password ================= |
-----------------------------------------------------------------------------
| BuddyElf                   | "N\v?i4mA*XYcG7x3Z$lHHBS<?bhl,6i^Lv          |
-----------------------------------------------------------------------------
| Elfy_McElface              | uK_cG>"l7Y<f;,Ei/Zf[*IN                      |
-----------------------------------------------------------------------------
| MiniSanta                  | uu;#Bh-Q`XelRFmw-.#;*!]                      |
-----------------------------------------------------------------------------


After spending all their resources to make presents, they didn't have a big budget for the security of their program, 
so hopefully you'll be able to break in and write your name off the naughty list and onto the nice list!! 


--------------
READ ME SECTION:

/------------ The Program ---------------/
- To compile the files/set permissions, run "make"
- To run the ElfHelpCentre program, use:
    ./ElfHelpCentre

/------------ The Sploit ----------------/
- To compile the sploits, run "make" *inside* the sploitFiles folder
- Then to run the sploit for naughty list editting, simply type in:
    ./sploit
    which will open a vim page to edit the naughty list for you to edit as you please. After you save it, you will
    likely need to restart the terminal. 
- Then to run the sploit for nice list editting, simply type in:
    ./sploit_nice
    which will open a vim page to edit the nice list for you to edit as you please. After you save it, you will
    likely need to restart the terminal. 

- To run the Vigenere program (to decode/encode), you can use:
    make encode
    or,  
    make decode
    to either encode or decode your plain/ciphertext. Follow the prompts for entering in your text and encryption key.  

/------------ Other Notes ----------------/
- I did not redact the key in ElfHelpCentre.c in my actual submission (although I did for the video), so that
    you can see the code
- Vigenere cipher: https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher
- Demo Username and Password
    name: Elfy_McElface
    password: HelpMeThisIsASweatsh0p!
