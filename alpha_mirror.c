/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:28:55 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/23 19:50:55 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allowed functions: write
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.
Case is not changed.
If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
--------------------------------------------------------------------------------
//NOTES
(1) Sums a = 97 + z = 122 - alternative version: 'a' + 'z' - argv[1][i];
(2) Sums A = 65 + Z = 90;

*/
#include <unistd.h>

int     main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
                argv[1][i] = 219 - argv[1][i]; //(1)
          
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                argv[1][i] = 155 - argv[1][i];//(2)
            write(1, &argv[1][i], 1);
            i++;
        }
        
    }
    write(1, "\n", 1);
}
