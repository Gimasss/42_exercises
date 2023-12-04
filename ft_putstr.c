/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:51:33 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/15 17:57:58 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Allowed functions: write

Write a function that displays a string on the standard output.
The pointer passed to the function contains the address of the string's first
character.
Your function must be declared as follows:

void	ft_putstr(char *str);
--------------------------------------------------------------------------------

*/
#include <unistd.h>

void    ft_putstr(char *str)
{
    int i = 0;
    
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }     
}
/* int main ()
{
    char str[] = "dammelo";
    ft_putstr(str);
} */


//check
void	ft_putstr(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return(0);
}

int	main()
{
	char str[] = "bitches";
	printf("%s", ft_putstr(str));
}
