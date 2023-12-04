/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:22:19 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/04 19:25:13 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : max

The first parameter is an array of int, the second is the number of elements in
the array.
The function returns the largest number found in the array.

If the array is empty, the function returns 0. ---> (1.0)

//NOTES
(1.1) Si presuppone che MAX sia gia' il piu' grande, controllo se quello dopo e' piu grande ancora.
(1.2) len - 1: PC trova 5 spazi, ma conta (0, 1, 2, 3, 4). Senza -1 non mi troverebbe '4' ma end of line.
(1.3) C riconosce unsigned int e int come diversi, aiuto sintassi mettendolo
(1.4) tab[i + 1]: se tab[i]=87 --> i+1=43, mi prende il valore accanto (2nd: 11, 43)
*/

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    int i = 0;
    int max;
    
    if (len == 0)// controllo 1.0
    	return 0;
    
    max = tab[i];//(1.1) T1 = 0 || T2 = 87; 
    while (i < (int)len - 1)//(1.2)len -1 //(1.3)Aggiungo (int) per sintassi
    {   
        //printf("max: %d\n", max);
        if (tab[i + 1] > max)//(1.4) 
            max = tab[i + 1];//sostituisce max se il numero che segue e' piu' grande
        i++; 
    }
    //printf("max alla fine : %d\n", max);
    return (max);
}

/* 
int main()
{
    int tab[4] = {0, 11, 22, -5}; //T1
    int tab2[5] = {87, 43, 66, 17, 9}; //T2
    printf("%d\n", max(tab, 4));
    printf("%d\n", max(tab2, 5));
} */


//VERSIONE ALTERNATIVA SASHONE
	unsigned int i = 1;
    	int max;
    
    	if (len == 0)
    	return 0;
    
    	max = tab[0];
	while (i < len )
	{   
		if (tab[i] > max)//(1.4) 
           	max = tab[i];
           	i++;
	}
	return (max);
