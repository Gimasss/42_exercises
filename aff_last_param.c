/* ************************************************************************** */
/*                                                                            

Write a program that takes strings as arguments, and displays its last
argument followed by a newline.

If the number of arguments is less than 1, the program displays a newline.

Examples:

$> ./aff_last_param "zaz" "mange" "des" "chats" | cat -e
chats$
--------------------------------------------------------------------------------
*/

#include <unistd.h>

int		main(int argc, char **argv)
{
	int i = 0;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	//while (*argv[i] != NULL)//meglio null che '\0' che si usa per char char
	
	while (argv[argc - 1][i] != '\0')
	///1. char dell'ultimo param/mi interessa la pos 3(ultima) ultimo param
	{
		write(1, &argv[argc - 1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}

/*
--------------------------------------------------------------------------------
*/

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i = 0;
	int	j = argc -1;

	if (argc < 2) //CONDITION if less than 1 argum
	{
		write(1, "\n", 1);
		return 0;
	}

	while (argv[j][i])
	{
		write(1, &argv[j][i], 1);
			i++;
	}
	write(1, "\n", 1);
	return 0;
}
