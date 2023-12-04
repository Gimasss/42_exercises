/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:44:44 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/24 12:37:16 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
Write a function that takes a string and displays the string in reverse
order followed by the newline.
Its prototype is constructed like this : 
  	char *ft_rev_print (char *str)
It must return its argument

$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
 */ 
//NOTES

/* ************************************************************************** */
//MAIN ONLY VERSION
#include <unistd.h>

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int i;

		i = 0;
		while(argv[1][i])//like strln
			i++;//get to the bottom of the string
		while(i)//finche; i e' vera/diversa da 0, continuo a scrivere
			//write(1, &argv[1][--i], 1); ////HASNT WORKED WITH VARIANTS SO CHECK THIS
		{
				i--;
				write(1, &argv[1][i], 1);
		}
	}
	write(1 ,"\n", 1);
	return (0);
}

//FUNCTION + MAIN VERSION
/*
void    rev_print(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    i--;
    while ( i >= 0)
    {
        write(1, &str[i], 1);
        i--;
    }
}

int     main(int argc, char *argv[])
{
    
    if(argc == 2)
    {
        rev_print(argv[1]);
    }
    write(1, "\n", 1);
}
*/