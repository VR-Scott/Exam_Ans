#include "check_mate.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_pawn(char **av, int ac, int i, int j)
{
	int	check = 0;

	if (i > 1)
	{
		if (j > 0 && av[i - 1][j - 1] == 'K')
			check = 1;
		else if(j < ac - 2 && av[i - 1][j + 1] == 'K')
			check = 1;
	}
	return (check);
}

int	ft_ispiece(char c)
{
	return (c == 'Q' || c == 'R' || c == 'P' || c == 'B');
}

int			main(int ac, char **av)
{
	int	i = 1;
	int	j = 0;
	int	check = 0;

	if (ac > 1)
	{
		while (i < ac && !check)
		{
			j = 0;
			while (j < ac - 1)
			{
				if (av[i][j] == 'P' && (check = ft_pawn(av, ac, i, j)))
					break;
				if ((av[i][j] == 'B' || av[i][j] == 'Q') && (check = ft_bish(av, ac, i, j)))
					break;
				if ((av[i][j] == 'R' || av[i][j] == 'Q') && (check = ft_rook(av, ac, i, j)))
					break;
				j++;
			}
			i++;
		}
		if (check)
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	ft_putchar('\n');
	return (0);
}
