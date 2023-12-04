/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:00:02 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/16 16:29:12 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

Ex 1- With (1, 3) you will return an array containing 1, 2 and 3.
Ex 2- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
Ex 3- With (0, 0) you will return an array containing 0.
Ex 4- With (0, -3) you will return an array containing 0, -1, -2 and -3.

//NOTES
(1) if (0, -1, -2, -3) start is bigger
(2) +1 bcs i'm including start and end 
	--> ie {3, 1} = 3, 2 ,1 [3] but 3-1 = [2], so I add +1 
(3) "--" because smaller numbers being before bigger ones...you gotta go back 
(4) if (1, 2, 3) end is bigger

*/

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int *tab;
    int size = 0;
    int i = 0;

    if (start >= end)//(1)
    {
        size = start - end + 1;//(2)
        tab = malloc(sizeof(int) * (size));
        
        while (i < size)
        {
            tab[i] = start;
            start--;//(3)
            i++;
        }        
    }
    
    else if (end > start)//(4)
    {
        size = end - start + 1;
        tab = malloc(sizeof(int) * (size));

        while (i < size)
        {
            tab[i] = start;
            start++;
            i++;
        }   
    }
    return (tab);
}

int     main()
{
    int i = 0; 
    
    int *tab1 = ft_range(1, 3);
    int *tab2 = ft_range(-1, 2);
    int *tab3 = ft_range(0, 0);
    
    while (i < 4)
    {
        printf("%d\n", tab3[i]);
        i++;
    }
}