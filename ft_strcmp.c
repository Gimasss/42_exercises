/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:48:28 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/15 18:54:56 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Allowed functions: none
Reproduce the behavior of the function strcmp (man strcmp).
Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
--------------------------------------------------------------------------------
//NOTES 

*/

#include <stdio.h>
#include <string.h>


int    ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && (s1[i] == s2[i]))
        i++;
    return (s1[i] - s2[i]);
}
/* 
int main()
{
    char s1[] = "bitch";
    char s2[] = "BITCH";
    printf("%d\n", ft_strcmp("bitch", "BITCH"));
    printf("%d\n", ft_strcmp("bitch", "noob"));
    printf("%d\n", ft_strcmp("bitch", "bitch"));

    printf("%d\n", strcmp("bitch", "BITCH"));
    printf("%d\n", strcmp("bitch", "noob"));
    printf("%d\n", strcmp("bitch", "bitch"));
     
}
*/
