/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:46:56 by gmastroc          #+#    #+#             */
/*   Updated: 2023/10/30 20:08:10 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
    char* str;
    int i = 0; //loop index
    int counter = 1; //size che daro' a malloc basically strlen
    int num;
    int flag = 0;//tells me if N is neg - T o F

    if (nbr < 0)
    {
        counter++;
        flag = 1;// if flag is 1 (tru) i need to write -
        nbr *= -1; //nbr = nbr * -1; makes it positive

    } 
    num = nbr;//storing nbr in num for ease - also keeps my nbr intonso to be used again
    while (num / 10 != 0)
    {        
       // printf("before counter %d\n", num);
        num = num % 10;
        counter++;//if mod diff from 0, counter keeps on operating
       // printf("after counter %d\n", num);
    }
   // printf("counter is %d\n", counter);
    str = (char*) malloc(sizeof(char)*(counter + 1));
    if (!str)
    {
       // printf("Malloc esploso\n"); //togliere ad esame
        return NULL;
    }
    if (flag == 1)
    {
        str[i] = '-'; //i = 0 - so in the 1st position
        counter--;
        i++;
    }

    while (counter > 0)
    {
        str[i] = nbr / 10 + 48;//scrivimi 1 (+48 per conversione in ascii)
        nbr = nbr % 10;// mi scorre il loop
        nbr *= 10;
        counter--;
        i++;
      //  printf("nbr %d\n", nbr);
        
    }
    str[i++] = '\0';
    return str;
}


int main()
{
    printf("I mallocked: %s\n", ft_itoa(-16));
}