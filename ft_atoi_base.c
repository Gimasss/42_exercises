#include <unistd.h>

int	get_val(char c)
{
	// Se è un numero da 0 a 9
	if (c >= '0' && c <= '9')
		return (c - '0');
	// Se è una lettera minuscola da 'a' a 'f'
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	// Se è una lettera maiuscola da 'A' a 'F'
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	// Carattere non valido
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	i = 0;
	int	sign = 1;
	int	result = 0;
	int	val;

	// Gestione del segno, SOLO se il primo carattere è '-'
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	// Scorri ogni carattere della stringa
	while (str[i])
	{
		val = get_val(str[i]);

		// Se il carattere non è valido per la base, interrompi
		if (val == -1 || val >= base)
			break;

		// Accumula il risultato: moltiplica per la base e somma il valore
		result = result * base + val;
		i++;
	}
	return (result * sign);
}


// #include <stdio.h>

// int	ft_atoi_base(const char *str, int base);

// int	main(void)
// {
// 	printf("%d\n", ft_atoi_base("12fdb3", 16));  // 1244595
// 	printf("%d\n", ft_atoi_base("12FDB3", 16));  // 1244595
// 	printf("%d\n", ft_atoi_base("-1011", 2));    // -11
// 	printf("%d\n", ft_atoi_base("77", 8));       // 63
// 	printf("%d\n", ft_atoi_base("1a", 16));      // 26
// 	printf("%d\n", ft_atoi_base("1A", 16));      // 26
// }

