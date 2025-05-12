// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e
// 1$
// $> ./pgcd | cat -e
// $
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int pgcd(int a, int b)
{
	int n;

	if (a > b)
		n = a;
	else
		n = b;
	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		{
			return (n);
		}
		n--;
	}
	return (0);
}
int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%d\n", 	pgcd(atoi(argv[1]), atoi(argv[2])));
	}
	else
		write(1, "\n", 1);
}