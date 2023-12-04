/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:46:53 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/13 14:04:12 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.
A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.
A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word 

//NOTES
(1)Find Capital Letters (im in the position before it as usual) 
(2)insert underscore between words(before capital)
(3)reduce all capitals

*/ 

#include <unistd.h>

int     main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {            
            if (argv[1][i] >= 'A' && argv[1][i] <= 'Z' )//(1)
            {
                write(1, "_", 1);//(2)
                argv[1][i] +=32;//(3)
            }
            write(1, &argv[1][i], 1);
            i++;       
         }
    }
    write(1, "\n", 1);
}
