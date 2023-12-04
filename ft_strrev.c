#include <stdio.h>
#include <string.h>

int     ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

char *ft_strrev(char *str)
{
    int i = 0;
    char temp;
    int len = ft_strlen(str);  
    printf("%d\n", len);

    //alternativa embedded strlen
    /* while (str[len])
        len++;
    len -= 1; arriva fino a prima del null, considero 5  (0 -5) */

    while (i < len)//as long as im within the lenght i found
    {
        temp = str[i];
        str[i] = str[len - 1]; //copio la posizione dell'ultima lettera
        str[len - 1] = temp;
        i++;
        len--;
    } 
    return (str);
}

int main(int ac, char **av)
{
    printf("%s\n", ft_strrev(av[1]));
    //printf("%s\n", ft_strrev(argv[argc - 1])); testo da terminal
}

/* 
int main(int argc, char *argv[])
{
    char str[] = "stocazzo";
    printf("%s\n", ft_strrev(str));
    
} */