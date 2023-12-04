/* 
Assignment name  : repeat_alpha
--------------------------------------------------------------------------------
Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.
'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
Case remains unchanged.
If the number of arguments is not 1, just display a newline.
Examples:

$>./repeat_alpha "abc"
abbccc 
--------------------------------------------------------------------------------

//CREATE COUNTER to set repetition based on Ascii Position
    
    count = argv[1][i] - 97 + 1;

The counter assigns a value to repeat the char --> a = 97 (ascii)
So: av - 97 = 0 // +1 not to skip 'a'.
with b: av(98) - 97 + 1 == 2(write it 2 times)
with c: av(99) - 97 + 1 == 3(write it 3 times) AND SO ON

//USUALLY with stuff (--) mi torna a zero, quindi:


//NOTES
(1) First control for arguments - remember \n
(2) Using a big while outside allows me to only have 1 main cycle, nesting IFs inside (only 1 i++ required)
(3) SET the counter
(4) (count--): cycles count n. times, writes till it reaches 0, exits the cycle.
(5) not sure tbh

*/


#include <unistd.h>

int     main(int argc, char *argv[])
{
    int i = 0;
    int count = 0;

    if (argc == 2)//(1)
    {
        while (argv[1][i] != '\0')//(2)
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z' )
            {
                count = argv[1][i] - 97 + 1;//(3)
                while (count --)//(4)
                    write(1, &argv[1][i], 1);
            }
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z' )
            {
                count = argv[1][i] - 65 + 1;
                while (count --)
                    write(1, &argv[1][i], 1);
            }
            else 
                write(1, &argv[1][i], 1);//(5)
            i++;
        }
    }
    write(1, "\n", 1);
}
