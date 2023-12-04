/* Assignment name  : ulstr

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$ */

#include <unistd.h>

int     main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 2)//arguments check
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                argv[1][i] -= 32;//capitalizes
            }
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                argv[1][i] += 32;//decapitalizes (?)
            }
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}