all: elf_help_centre pretend_database set_list_permissions

elf_help_centre: ElfHelpCentre.c
	gcc -fno-stack-protector -o ElfHelpCentre ElfHelpCentre.c
	chmod 4555 ElfHelpCentre

pretend_database: PretendItsADatabase.cpp
	g++ -O2 -Wall -o PretendItsADatabase PretendItsADatabase.cpp
	chmod 700 PretendItsADatabase

set_list_permissions:
	chmod 600 nice.txt
	chmod 600 naughty.txt
