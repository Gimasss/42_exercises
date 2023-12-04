/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:55:19 by gmastroc          #+#    #+#             */
/*   Updated: 2023/10/16 18:07:34 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//return the length of a string

#include <string.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')//la stringa esiste! scorrila. ritornami l'int.
		i++;
	return (i);
}

/*int	main()
{
	char str[] = "whadupbitches";
	printf("%d\n", ft_strlen(str));
	return 0;
}*/
