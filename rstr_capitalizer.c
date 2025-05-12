// Assignment name  : rstr_capitalizer
// Expected files   : rstr_capitalizer.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes one or more strings and, for each argument, puts
// the last character of each word (if it's a letter) in uppercase and the rest
// in lowercase, then displays the result followed by a \n.

// A word is a section of string delimited by spaces/tabs or the start/end of the
// string. If a word has a single letter, it must be capitalized.

// If there are no parameters, display \n.

// Examples:

// $> ./rstr_capitalizer | cat -e
// $
// $> ./rstr_capitalizer "Premier PETIT TesT" | cat -e
// premieR petiT tesT$
// $> ./rstr_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
// deuxiemE tesT uN peU moinS  facilE$
//    attentioN c'esT paS duR quanD memE$
// alleR uN dernieR 0123456789pouR lA routE    E $
// $>

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

// is_low
int is_low(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
// is_up
int is_up(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

bool is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (true);
	return (false);
}
void pchar(char c)
{
	write(1, &c, 1);
}

void capit(char *s)
{
	int i = 0;
	while (s[i])
	{
		// printf("%d\n", s[i]);
		while (s[i] && is_up(s[i]) == 1)
			s[i] += 32;

		if (s[i] && is_low(s[i]) == 1 && is_space(s[i + 1]))
		{

			s[i] -= 32;
		}
		// printf("%d\n", s[i]);
		pchar(s[i++]);
		//i++;
	}
}

int main(int argc, char *argv[])
{
	int ag = 1;

	if (argc < 2)
		return(write(1, "\n", 1), 1);
	if (argc >= 2)
	{
		while (argv && argv[ag])
		{
			capit(argv[ag]);
			ag++;
		}
		pchar('\n');
	}
}
/*
int main(int argc, char *argv[])
{
	int ag = 1;
	int i = 0;

	if (argc < 2)
		return(write(1, "\n", 1), 1);
	while (argv && argv[ag])
	{
		while (argv[ag][i])
		{
			// printf("%d\n", argv[ag][i]);
			while (argv[ag][i] && is_up(argv[ag][i]) == 1)
				argv[ag][i] += 32;

			if (argv[ag][i] && is_low(argv[ag][i]) == 1 && is_space(argv[ag][i + 1]))
			{

				argv[ag][i] -= 32;
			}
			// printf("%d\n", argv[ag][i]);
			pchar(argv[ag][i++]);
			//i++;
		}
		i = 0;
		ag++;
		pchar('\n');
	}
	return 0;
} */

