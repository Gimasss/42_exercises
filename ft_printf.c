// Write a function named `ft_printf` that will mimic the real printf but
// it will manage only the following conversions: s,d and x.

// Your function must be declared as follows:

// int ft_printf(const char *, ... );

// Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
// To test your program compare your results with the true printf.

// Exemples of the function output:

// call: ft_printf("%s\n", "toto");
// out: toto$

// call: ft_printf("Magic %s is %d", "number", 42);
// out: Magic number is 42%

// call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// out: Hexadecimal for 42 is 2a$

// Obs: Your function must not have memory leaks. Moulinette will test that.

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define F ft_printf


int	put_c(char c)
{
	return (write(1, &c, 1));
}

int put_s(char *s)
{
	int i = 0;
	if (!s)
	{
		put_s("(null)");
		return (6);
	}
	while (s[i])
	{
		put_c(s[i]);
		i++;
	}
	return (i);
}

int put_nb(long n, char *base)
{
	int count = 0;
	int base_len = 0;

	while(base[base_len])
		base_len++;
	if (n < 0)
	{
		count += put_c('-');
		n = -n;
	}
	if (n >= base_len)
		count += put_nb(n / base_len, base);
	count += put_c(base[n % base_len]);
	return (count);

}

int format(char c, va_list arg)
{
	int print = 0;
	if (c == '%')
		print += put_c('%');
	else if (c == 's')
		print += put_s(va_arg(arg, char *));
	else if (c == 'd')
		print += put_nb(va_arg(arg, int), BASE10);
	else if (c == 'x')
		print += put_nb(va_arg(arg, unsigned int), BASE16);
	return (print);
}

int ft_printf(const char *form, ... )
{
	int		i = 0;
	int 	count = 0;
	va_list	arg;

	va_start(arg, form);
	if (form == NULL)
		return (-1);
	while (form[i] != '\0')
	{
		if (form[i] == '%' && form[i + 1])
			count += format(form[++i], arg);
		else
			count += put_c(form[i]);
		i++;
	}
	va_end(arg);
	return (count);
}

// int main()
// {
// 	// F("Simple test\n");
// 	// F("");
// 	// F("--Format---");
// 	// F("\n");
// 	// F("%d\n", 0);
// 	F("%d\n", 42);
// 	// F("%d\n", 1);
// 	// F("%d\n", 5454);
// 	F("%d\n", (int)2147483647);
// 	F("%d\n", (int)2147483648);
// 	F("%d\n", (int)-2147483648);
// 	F("%d\n", (int)-2147483649);
// 	printf("og: %d\n", (int)2147483647);
// 	printf("og: %d\n", (int)2147483648);
// 	printf("og: %d\n", (int)-2147483648);
// 	printf("og: %d\n", (int)-2147483649);
// 	// F("\n");
// 	// F("%x\n", 0);
// 	// F("%x\n", 42);
// 	// F("%x\n", 1);
// 	// F("%x\n", 5454);
// 	// F("%x\n", (int)2147483647);
// 	// F("%x\n", (int)2147483648);
// 	// F("%x\n", (int)-2147483648);
// 	// F("%x\n", (int)-2147483649);
// 	// F("%x\n", (int)0xFFFFFFFF);
// 	// F("\n");
// 	// F("%s\n", "");
// 	F("%s\n", "toto");
// 	// F("%s\n", "wiurwuyrhwrywuier");
// 	F("%s\n", NULL);
// 	// F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	// F("\n--Mixed---\n");
// 	// F("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
// 	// F("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
// 	// F("\n");
// 	// F("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	// F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	return 0;

// }
