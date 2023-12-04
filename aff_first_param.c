/* ************************************************************************** */
/*                                                                            
--------------------------------------------------------------------------------

Write a program that takes strings as arguments, and displays its first
argument followed by a \n.
If the number of arguments is less than 1, the program displays \n.

Example:
$> ./aff_first_param vincent mit "l'ane" dans un pre et "s'en" vint | cat -e
vincent$
*/

#include <unistd.h>

int		main(int ac, char **av)
{
	int i = 0;

	if (ac < 2)//conditions control
	{
		write(1, "\n", 1);
		return 0;
	}

	while (av[1][i] != '\0')
	{
		write(1, &av[1][i], 1);
		i++;
	}
}
