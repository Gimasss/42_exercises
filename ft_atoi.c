/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:36:41 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/16 14:58:25 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);

//NOTES
(1) Spaces management
(2.0) Sign management
(2.1) when the - sign is found
(3) Conversion to int
*/

#include <stdlib.h>
#include <stdio.h>

int     ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] == 32 || str[i] >= 9 && str[i] <= 13)//(1)
        i++;
    //printf("%c\n", str[i] );
    if (str[i] == '+' || str[i] == '-')//(2.0)
    {
        if (str[i] == '-')//(2.1)
            sign = -1;
        i++;
    }
    //printf("%c\n", str[i] );
    while (str[i] >= '0' && str[i] <= '9')//(3)
    {
        result = (result*10) + (str[i] - '0');
        i++;
    }
    return(result * sign);
}/* 

int main()
{
    char str1[] = " 6678";
    char str2[] = "--678";
    char str3[] = "6623 478";
    char str4[] = "-986678";

    printf("%d\n", atoi(str1));
    printf("%d\n", ft_atoi(str1));
    printf("%d\n", atoi(str2));
    printf("%d\n", ft_atoi(str2));
    printf("%d\n", atoi(str3));
    printf("%d\n", ft_atoi(str3));
    printf("%d\n", atoi(str4));
    printf("%d\n", ft_atoi(str4));
} */
