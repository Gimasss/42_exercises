/*
Assignment name  : hidenp
Allowed functions: write

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.
Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.
If the number of parameters is not 2, the program displays a newline.

Examples :
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$

or 0

--------------------------------------------------------------------------------

*/
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;

    if (argc == 3)
    {
        while (argv[2][j] != '\0' && argv[1][i])//both arg exist
        {
            if (argv[1][i] == argv[2][j])//comparing the two strings
                i++;//scorre solo se trova caratteri comuni
            j++;//scorre a prescindere
        }
        if (!argv[1][i])
            write(1, "1", 1);//se ho terminato arg 1, ho somiglianze scrivo 1
        else
            write(1, "0", 1);//non ho terminato 1, non ho somiglianze quindi 0
    }
    write(1, "\n", 1);
    return (0);
}




//alternativa con funzione esterna DA RIVEDERE
int  hidenp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int ret_value = 0;

    while (s1[len])//calcolo lunghezza
        ++len;
    while (s2[j] && i < len)
        {
            if(s2[j] == s1[i])
            {   
                i++;
            }
            j++;
        }
                        
    if (i == len)
        write(1, s1, len);
        /*
        ret_value++;
    return ret_value;*/ //versionehidenp
}

int     main(int ac, char **av)
{
    if (ac == 3)
    {
        if (hidenp(av[1], av[2]) == 1)
            write(1, "1", 1);
        else 
            write(1, "0", 1);
    }
    write(1, "\n", 1);
    return (0);
}
