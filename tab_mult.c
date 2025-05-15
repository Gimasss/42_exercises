// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $

#include <stdlib.h>
#include <unistd.h>

void putc(char c)
{
	write(1, &c, 1);
}

void putn(int n)
{
	if (n > 9)
		putn(n / 10);
	putc(n % 10 + 48);

}
int tiny_atoi(char *s)
{
	int res = 0;
	int i = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return (res);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return(putc('\n'), 0);
	int i = 1;
	int num = tiny_atoi(argv[1]);
	while (argv[1][i] && i <= 9)
	{
		putn(i);
		write(1, " x ", 3);
		putn(num);
		write(1, " = ", 3);
		putn( i * num);
		putc('\n');
		i++;
	}
	return 0;
}
