/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:48:19 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/13 16:02:10 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
 
 need 2 ints - for the 2 n, argum ---> use atoi for conversion
 IF for each operator -- 
 
 
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int     main(int argc, char *argv[])
{
    if(argc != 4)
    {
        write (1, "\n", 1); 
        return 0;
    }
    
    int nb1 = atoi(argv[1]);
    int nb2 = atoi(argv[3]);

    if (argv[2][0] == '+')
        printf("%d\n", nb1 + nb2);

    if (argv[2][0] == '-')
        printf("%d\n", nb1 - nb2);
    
    if (argv[2][0] == '*')
        printf("%d\n", nb1 * nb2);

    if (argv[2][0] == '/')
        printf("%d\n", nb1 / nb2);
    
    if (argv[2][0] == '%')
        printf("%d\n", nb1 % nb2);

}