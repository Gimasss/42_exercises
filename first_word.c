/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:00:31 by gmastroc          #+#    #+#             */
/*   Updated: 2023/10/17 19:56:43 by gmastroc         ###   ########.fr       */
/*                                                                            */
/*

Allowed functions: write

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$

//NOTES
Double parenthesys required + av != NULL, otherwise it fails the exam.

/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i = 0;
	if (argc == 2)
	{
		while ((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i] != '\0') 
		//handles spaces and tabs, runs through them.
			i++;
		while ( argv[1][i] != ' ' && argv[1][i] != '\t') && argv[1][i] != '\0') 
		//if it find somethinng other than those, it writes down what it finds
		{
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

