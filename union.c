/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:33:05 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/15 18:46:48 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$

//NOTES
(1) can also be done using only 1 index (i) by resetting it at the end of the first loop

*/


#include <unistd.h>

int     main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int tab[256] = {0};

    if (argc == 3)
    {
        while (argv[1][i] != '\0')
        {
            if (tab[argv[1][i]] == 0)
                {
                    tab[argv[1][i]] = 1;
                    write(1, &argv[1][i], 1);
                }
            i++;
        }
        //i = 0; (1)
        while (argv[2][j] != '\0')
         {
            if (tab[argv[2][j]] == 0)
                {
                    tab[argv[2][j]] = 1;
                    write(1, &argv[2][j], 1);
                }
            j++;
        }
    }
    write(1, "\n", 1);
}
