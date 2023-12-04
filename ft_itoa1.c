#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		nbrlen(int n)//how long is final str
{
	int count = 0;

	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char *ft_itoa(int nb)
{
	long n = nb;//mettiamo il num in piu' spazio per evitare overflow
	int len = nbrlen(nb);

	char* res = malloc(sizeof(char) * (len + 1));//malloc di lunghezza stringa+1
	res[len] = '\0';//chiudo con null byte
	len--;//oppure res[len--]

	if (nb < 0)
	{
		res[0] = '-';
		n = n * -1; //trasformo in positivo per poter fare %
	}
	//printf("%d\n", len);
	while (len >=  0+ (nb < 0))//va da fine a inizio stringa per inserire cifre. Index arriva a 0 - sovrascrive il "-"
	{
		res[len] = n % 10 + 48;//'0'
		n = n / 10;
		len--;
	}
	return (res);
}

int main()
{
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(42));
	//printf("%s\n", itoa(-42));
}