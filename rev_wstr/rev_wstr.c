#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v');
}

static int	ft_isprint(char c)
{
	return (c > 32 && c < 127);
}

static void	ft_putword(char *str)
{
	int			i = 0;
	static int	c = 0;
	if (c++)
		ft_putchar(' ');
	while (str[i] && !ft_isspace(str[i]))
		ft_putchar(str[i++]);
}

int			main(int ac, char **av)
{
	int i;
	if (ac == 2)
	{
		i = ft_strlen(av[1]) - 1;

		while (ft_isspace(av[1][i]))
			i--;
		while(i >= 0)
		{
			while (i > 0 && ft_isprint(av[1][i]) && !ft_isspace(av[1][i - 1]))
				i--;
			if (ft_isprint(av[1][i]) && (i == 0 || ft_isspace(av[1][i - 1])))
				ft_putword(&av[1][i--]);
			while (ft_isspace(av[1][i]))
				i--;
		}
	}
	ft_putchar('\n');
	return (0);
}
