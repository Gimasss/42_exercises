/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:31:54 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/04 16:50:32 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that prints the numbers from 1 to 100, each separated by a
newline.
If the number is a multiple of 3, it prints 'fizz' instead.
If the number is a multiple of 5, it prints 'buzz' instead.
If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

//NOTES
fucking numbers
(1.0) setting it to 1 to do operations
(1.1) big while with limit control as requested in subject
(1.2) setting num control - if mod of 3, 5 is ) then they're multipliers, writes the string
(1.3) for every other fukn number write two functions to actually print them...
(2.0) function1 to convert and write int
(2.1) If num is smaller than 10, just write as it is.
(2.2) if num is bigger than 10, need to break it down to "evaluate" it.

*/

#include <unistd.h>

void	ft_putint(int nb)//(2.0)
{
	nb += 48;
	write(1, &nb, 1);
}

void ft_putnbr(int nb)//versione ricorsiva
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putint(nb % 10);
}

/*
void ft_putnbr(int nb)
{
    if (nb < 10)//(2.1)
	{
		ft_putint(nb);
	}
	else//(2.2)
	{
		ft_putnbr(nb / 10);
		ft_putint(nb % 10);
	}
}*/



/*
int main()
{
    int x = 1;//(1.0)

    while (x <= 100)//(1.1) 
    {
        if (x % 3 == 0 && x % 5 != 0)//(1.2)
            write (1,  "fizz", 4);
        else if (x % 5 == 0 && x % 3 != 0)
            write (1, "buzz", 4);
        else if (x % 3 == 0 && x % 5 == 0)
            write (1, "fizzbuzz", 8);
        else
            ft_putnbr(x);//(1.3)
        x++;
        write(1, "\n", 1);
    }

}
*/

int main()
{
    int x = 1;//(1.0)

    while (x <= 100)//(1.1) 
    {
        if (x % 3 != 0 && x % 5 != 0)//(1.2)
            ft_putnbr(x);
        else {
		if (x % 3 == 0)
		    write (1, "fizz", 4);
		if (x % 5 == 0)
			write (1, "buzz", 4);
        }
        x++;
        write(1, "\n", 1);
    }

}
