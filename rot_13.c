/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:43 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/16 14:34:42 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Allowed functions: write
Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
--------------------------------------------------------------------------------
//NOTES
I will need to split the alphabet in 2 to stay within the ascii, so a~m and n~z 
*/

#include <unistd.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'm')
                argv[1][i] += 13;
            else if (argv[1][i] >= 'n' && argv[1][i] <= 'z')
                argv[1][i] -= 13;

            else if (argv[1][i] >= 'A' && argv[1][i] <= 'M')
                argv[1][i] += 13;
            else if (argv[1][i] >= 'N' && argv[1][i] <= 'Z')
                argv[1][i] -= 13;
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
