/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:12:54 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/15 18:27:40 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$


//NOTES
(1) using tab buffer 256 ascii + non ascii char to check which ascci is already present
(2) checking first if 1 exists as we use that for reference
(3) check if 2 also exist, if so compare 1 and 2
(4)set inside my buffer av1 - if ascii (==0 not present)
(5) set the count to 1 when you find a new one


*/


#include <unistd.h>

int     main(int argc, char *argv[])
{
    int i = 0;
    int j;
    int tab[256] = {0};//(1)

    if (argc == 3)
    {
        while (argv[1][i] != '\0')//(2)
        {
            j = 0;
            while (argv[2][j] != '\0')//(3)
            {
                if (argv[1][i] == argv[2][j])
                {
                    if (tab[argv[1][i]] == 0)//(4)
                    {
                        tab[argv[1][i]] = 1;//(5) 
                        write(1, &argv[1][i], 1);
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}
