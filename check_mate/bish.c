#include "check_mate.h"
int	ft_b_m_m(char **av, int ac, int i, int j)
{
	if (i < 1 || j < 0 || ft_ispiece(av[i][j]))
		return (0);
	if (av[i][j] == 'K')
		return (1);
	return (ft_b_m_m(av, ac, i - 1, j - 1));
}

int	ft_b_m_p(char **av, int ac, int i, int j)
{
	if (i < 1 || j > ac - 2 || ft_ispiece(av[i][j]))
		return (0);
	if (av[i][j] == 'K')
		return (1);
	return (ft_b_m_p(av, ac, i - 1, j + 1));
}

int	ft_b_p_m(char **av, int ac, int i, int j)
{
	if (i > ac - 1 || j < 0 || ft_ispiece(av[i][j]))
		return (0);
	if (av[i][j] == 'K')
		return (1);
	return (ft_b_p_m(av, ac, i + 1, j - 1));
}

int	ft_b_p_p(char **av, int ac, int i, int j)
{
	if (i > ac - 1 || j > ac - 2 || ft_ispiece(av[i][j]))
		return (0);
	if (av[i][j] == 'K')
		return (1);
	return (ft_b_p_p(av, ac, i + 1, j + 1));
}

int	ft_bish(char **av, int ac, int i, int j)
{
	if (ft_b_m_m(av, ac, i - 1, j - 1))
		return (1);
	if (ft_b_m_p(av, ac, i - 1, j + 1))
		return (1);
	if (ft_b_p_m(av, ac, i + 1, j - 1))
		return (1);
	if (ft_b_p_p(av, ac, i + 1, j + 1))
		return (1);
	return (0);
}
