/*
Assignment name  : rotone

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.
'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
The output will be followed by a \n.
If the number of arguments is not 1, the program displays \n.

Example:
$>./rotone "abc"
bcd

//NOTES 
(1) First control for arguments - remember \n
(2) Using a big while outside allows me to only have 1 main cycle, nesting IFs inside (only 1 i++ required)
(3) av[1][i] += 1 ---> finds the following ascii char || i.e. 'a' + 1 -> 'b'
(4) Extra control as ofc after z you don't have an A, so you send it back with -25
(5) Write it all and repeat till '\0'
*/

#include <unistd.h>

int     main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 2)//(1)
    {
        while (argv[1][i] != '\0')//(2)
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'y')//(3)
                argv[1][i] += 1;              
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Y')
                argv[1][i] += 1;
            else if (argv[1][i] == 'Z' || argv[1][i] == 'z')//(4) 
                argv[1][i] -= 25;                
            write(1, &argv[1][i], 1);//(5)
            i++;   
        }
    }
    write(1, "\n", 1);
}
