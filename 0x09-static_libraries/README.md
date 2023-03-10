
# 0x09. C - Static libraries

# 0 Task requirements

- Create the README.md file
- Create main.h and copy all the prepositions
- Create and add the main.c file
- Create and paste previous tasks of the .c file for all the object files listed in the task
- Write a code to convert each of the .c to .o file at once:  gcc  -c *.c
- Create the static library libmy.a    // ar rcs libmy.a *.o
- Run touch gitignore and add *.c *.o
- Run the command ar -t libmy.a *.o  to list all the .o object files  OR ar -cr libmy.a *.o
- Run nm libmy.a

# 1 Task requirements

- Touch create_static_lib.sh
- Copy the code below into the above file
- !/bin/bash
- gcc -c *.c
- ar -rc liball.a *.o	
- chmod u+x create_static_lib.sh
- test or run the executable file with ./create_static_lib.sh
