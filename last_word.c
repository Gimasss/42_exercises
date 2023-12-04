/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:44:53 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/11 18:21:00 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
--------------------------------------------------------------------------------
*/

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 2)
    {
        while (argv[1][i] != '\0')//arrivo in  fondo al vettore
            i++;
        /* if (argv[1][i] == '\0')
            printf("CAZZI siamo sul null %c\n", argv[1][i]);//am i at the end of the line? */
        i--; 
        //printf("MAZZI %c\n", argv[1][i]);//what hav i found?
        
        while (argv[1][i] == ' ' || argv[1][i] == '\t')//saltami eventuali spazi alla fine
            i--;//se trovo lo spazio vado indietro fino al char
        //printf("MAZZI %c\n", argv[1][i]);
        while (argv[1][i] != ' ' && argv[1][i] != '\t' && i >= 0)
            i--;//vado in cima alla parola arrivando nello spazio
        i++;
        while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
        {//  write(1, &argv[1][i++], 1); ALT
            write(1, &argv[1][i], 1);
            i++;
        }
        //printf("SBAZZI %c\n", argv[1][i]);
    }
    write(1, "\n", 1);
}