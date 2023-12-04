
/* 
Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e 

//NOTES
I will be counting the length of s1, which should be found within s2. If it is, I'll print it.
(1) quick strlen within main function to know the length of s1
(2) if there's s2 and while within the length of s1-->
(3) compare s2 to s1 - i will count only when it finds similiar chars, j will keep on going anyway
(4) if the length found with i equals len, write s1 for its length.


*/


#include <unistd.h>

void	wdmatch(char *s1, char *s2)
{
	int len = 0;
	int i = 0;
	int j = 0;

	while (s1[len]) //(1)
		++len;
	while (s2[j] && i < len)//(2)
	{
		if (s2[j] == s1[i])//(3)
		{
			i++;
		}
		j++;
	}

	if (i == len)//(4) 
		write(1, s1, len);
	
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		wdmatch(av[1], av[2]);
		//write(1, &av[1], 1); NO mettendo cosi' mi stampa una roba a caso
	}
	write(1, "\n", 1);
	return (0);
}