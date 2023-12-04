/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:25:41 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/15 14:20:35 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.
--------------------------------------------------------------------------------
//FAMO SPLIT
mallocco array di stringhe (matrix a 2D) --- size di malloc sara' parole +1 ---> ritorno matrix

1 - Gotta count words --> need to know where [spaces] are to distinguish words
2 - I'll create space to store the no. words found 


(1) Space checker - if [spc] 1, else 0;
(1.1) using char c as i'm checking one char at a time
(2) Counting the words, i declare a counter index - to return COUNT 
(2.1) If my current char is a space I'll just move along
(2.2) its a LETTER, (2.3) so I'll count it (2.4), as long as i have letters i'll keep going
(3) Allocate space for the words
(3.1)!ft_space returna 0 --- ft_space return 1 o else (??)
(3.2)if no space // scorri fino a fine parola // works as STRCPY
(3.3)alloca fino allo spazio



 */

#include <stdlib.h>
#include <stdio.h>

//(1)
int     ft_space(char c)//(1.1)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return 1;
    return 0;
}

//(2)
int     count_words(char *str)
{
    int count = 0;
     
    while (*str)//str[i] w/ int i = 0; //*str e' il carattere corrente)
    {
        while (*str && ft_space(*str) == 1)//(2.1)
            str++;
        //printf("%c", *str);
        if (*str && ft_space(*str) == 0)//(2.2)
        {
            count++;//(2.3)
            while (*str && ft_space(*str) == 0)//(2.4)
                str++;
        }
    }
   // printf("NUMERO PAROLE: %d\n", count);
    return count;
}

//(3)
char    *word_mall(char *str)
{
    int i = 0;
    char *word; 
    
    while (str[i] && ft_space(str[i]) == 0)//(3.1)
        i++;

    //printf("\nlen word = %d\n", i);
    word = malloc(sizeof(char) * (i + 1));
    if (!word)
        return NULL;
    i = 0;
    while (str[i] && ft_space(str[i]) == 0)//(3.2)
    {
        //printf("%c\n", str[i]);
        word[i] = str[i];//(3.3)
        i++;
    }
    word[i] = '\0';
    //printf("%s\n", word);
    return word;
}

//(4)
char **ft_split(char *str)
{
    int i = 0;//scorre matrix
    char **split;//quello che devo ritornare 

    split = malloc(sizeof(char*) * (count_words(str) + 1));
    if(!split)//se esplode..
        return NULL;
    //ho fatto spazio nella memoria, ora devo allocare ogni singola parola 
    //ora che ho malloccato cose sistemo le parole con una nuova funz che creo(word_mall)

    while (*str)
    {
        while (*str && ft_space(*str) == 1)//DA RISPIEGARE why puntatore
            str++;//spaces? skip
        if (*str && ft_space(*str) == 0)//only printable so:
        {
            split[i] = word_mall(str); //alloca e copia la parola
            i++;
            while (*str && ft_space(*str) == 0)//scorre stringa se non c'e' spazi
                str++;//continua nella parola
        }
    }
    split[i] ='\0';//termina array
    return split;//ritornami tutta la matrice pls
}

//(5)
int     main()
{
    char **splat;
    char str[] = "si va in Cambogia a comandare";

    splat = ft_split(str);
    
    while (*splat != NULL)
    {
        printf("%s\n", *splat);
        splat++;
    }
}

/*
int     main()
{
    char **splat;

    char str[] = " hit me baby one more time  ";
    splat = ft_split(str);

    int i = 0;
    while (splat[i] != NULL)
    {
        printf("%s\n", splat[i]);
        free(splat[i]);
        i++;
    }
    free(splat);    
}*/