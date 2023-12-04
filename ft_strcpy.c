/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:45:06 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/16 13:56:46 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
--------------------------------------------------------------------------------
*/

#include <string.h>
#include <stdio.h>
char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] && s2[i])
    { 
        s1[i] = s2[i];
        i++;
    }
    s1[i] = s2[i]//terminala li' per copiare anche '\0'
    // s1[i]= '\0'; alternativa
    return (s1);     
}
/* 
int main()
{
    char s1[] = "bella";
    char s2[] = "merda";

    printf("%s\n", ft_strcpy(s1, s2));
    printf("%s\n", strcpy(s1, s2));
} */

int	main(int ac, char **av)
{
	printf("%s\n", ft_strcpy(av[1],av[2]));
	return 0;
}

