/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:52:14 by gmastroc          #+#    #+#             */
/*   Updated: 2023/10/16 17:53:19 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//only print a char

#include <unistd.h>

int	main()
{
	write(1, "z", 1);
	return 0;
}
