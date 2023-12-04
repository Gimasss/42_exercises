/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:48:38 by gmastroc          #+#    #+#             */
/*   Updated: 2023/11/16 16:18:33 by gmastroc         ###   ########.fr       */
/*                                                                            */
/*/

Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int     ft_strlen(char *src)
{
    int i = 0;

    while (src[i] != '\0')
        i++;
    return i;
}


char    *ft_strdup(char *src)
{
    int i = 0;
    char *dup;

    dup = malloc(sizeof(char) * (ft_strlen(src) + 1));

    if (!dup)
        return NULL;

    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

int     main()
{
    char src[] = "minchiabboni";
    
    printf("%s\n", ft_strdup(src));
    printf("%s\n", strdup(src));
}