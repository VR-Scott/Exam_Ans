#include <stdio.h>
#include <stdlib.h>

int	do_op(int a, char op, int b)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (op == '/')
		return (a / b);
	else
		return (a % b);
}

int	is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*'  || c == '/' || c == '%');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	main(int ac, char **av)
{	int i = -1;
	int j = 0;
	int tab[10] = {0};
	char *s;
	
	s = av[1];
	if (ac == 2)
	{
		while(s[j])
		{
			if (is_digit(s[j]) || (s[j] == '-' && is_digit(s[j + 1])))
			{
				i++;
				tab[i] = atoi(&s[j]);
				if (s[j] == '-')
					j++;
			}
			while (is_digit(s[j]))
				j++;
			if (is_operator(s[j]))
			{
				if (i < 1 || (tab[i] == 0 && (s[j] == '/' || s[j] == '%')))
				{
					printf("Error\n");
					return (-1);
				}
				tab[i - 1] = do_op(tab[i - 1], s[j],tab[i]);
				i--;
			}
			j++;
		}
		if (i != 0)
		{
			printf("Error\n");
			return (-1);
		}
		printf("%d\n",tab[i]);
		return(0);
	}
	printf("Error\n");
	return (-1);
}
