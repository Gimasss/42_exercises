/* 
Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.
 */

/* 
1 controllo - num di parametri (2)
2 controllo - spazi/tab a fine e inizio stringa
3 controllo - individuo parole e spazi
 */
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;


    if (argc == 2)
    {

        while (argv[1][i] != '\0')//senza il controllo fino a NULL scorre in avanti a caso
        {
            while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))/*X*/
                i++;//skipping firts possible spaces and tabs til 1st word
            while (argv[1][i] && (argv[1][i] != ' ' || argv[1][i] != '\t'))//finche e' un char che piace a noi
            {   
                if (argv[1][i] == ' ' || argv[1][i] == '\t')//questo if si attiva solo se trovo lo spazio, altrimenti ignora e continua a scrivere
                   break ;//forzo uscita e torno a X
                write(1, &argv[1][i], 1);
                i++;
            }
            write(1, "   ", 3);
        }
    }
    write(1, "\n", 1);
}
