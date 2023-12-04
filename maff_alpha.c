/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:29:04 by gmastroc          #+#    #+#             */
/*   Updated: 2023/10/16 16:33:18 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// print alphabet in reberse

#include <unistd.h>

int	main()
{
	write(1,"aBcDeFgHiJkLmNoPqRsTuVwXyZ\n", 27);
	return 0;
}
