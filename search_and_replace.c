/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:34:23 by gmastroc          #+#    #+#             */
/*   Updated: 2023/10/16 18:53:05 by gmastroc         ###   ########.fr       */
/*

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre


//NOTES
(1.0) Preliminary control on arguments - better to do it by itself as there's more info to give it, it needs to get out of the cycle if it doesn't correspond


/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i = 0;

	if (argc != 4 || argv[2][1] || argv[3][1])//(1.0)
	{
		write(1, "\n", 1);
		return 0;
	}

	while (argv[1][i])
	{
		if (argv[2][0] == argv[1][i])//(2)ifyou find the content of 2.0 in 1.i 
		{
			argv[1][i] = argv[3][0];//(3)replace that position with arg 3.0
		}
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}




/*
also works like this
while (argv[1][i] != '\0')
	{
		if (argv[2][0] == argv[1][i])
		{
			argv[1][i] = argv[3][0];
			write(1, &argv[1][i], 1);
		}
		else 
			write(1, &argv[1][i], 1);
		i++;
	}
	*/
