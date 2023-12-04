/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:12 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/13 16:34:38 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

Ex 1- With (1, 3) you will return an array containing 3, 2 and 1
ex 2- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
ex 3- With (0, 0) you will return an array containing 0.
ex 4- With (0, -3) you will return an array containing -3, -2, -1 and 0.

//NOTES
(1)
(2)
(3)

*/

#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
    int *tab;
    int size = 0;
    int i = 0;

    if (end >= start)
    {
        size = end - start + 1; 
        //printf("%d\n", size);
        tab = malloc (sizeof(int) * (size));
    
        while (i < size)
        {   
            //printf("%d\n", end);
            tab[i] = end;
            end--;
            i++;
        }
    }
    else if (start > end)
    {
        size = start - end + 1;
        tab = malloc (sizeof(int) * (start - end + 1));
     
        while (i < size)
            {
                tab[i] = end;
                end++;//fixes the given value
                i++;
            }
    }
    return (tab);
}

int     main()
{
    int *tab = ft_rrange(1,-1);

    printf("%d\n", tab[0]);
    printf("%d\n", tab[1]);
    printf("%d\n", tab[2]);
    free(tab);
} 
/*

void print(int *res, int len)
{
    for (int i = 0; i < len; i++)
    {
        ft_putnbr(res[i]);
        ft_putchar(' ');
    }
    ft_putchar('\n');
    free(res);
}

int main()
{
    print(ft_rrange(1, 3), 3);
    print(ft_rrange(-1, 2), 4);
    print(ft_rrange(0, 0), 1);
    print(ft_rrange(0, -3), 4);
    return 0;
}*/