#include "check_mate.h"

int	ft_r_m_s(char **av, int ac, int i, int j)
{
	if (i < 1 || ft_ispiece(av[i][j]))
		return (0);
	if (av[i][j] == 'K')
		return (1);
	return (ft_r_m_s(av, ac, i - 1, j));
}

int	ft_r_s_m(char **av, int ac, int i, int j)
{
	if (j < 0 || ft_ispiece(av[i][j]))
		return (0);
	if (av[i][j] == 'K')
		return (1);
	return (ft_r_s_m(av, ac, i, j - 1));
}

int	ft_r_p_s(char **av, int ac, int i, int j)
{
	if (i > ac - 1 || ft_ispiece(av[i][j]))
		return (0);
	if (av[i][j] == 'K')
		return (1);
	return (ft_r_p_s(av, ac, i + 1, j));
}

int	ft_r_s_p(char **av, int ac, int i, int j)
{
	if (j > ac - 2 || ft_ispiece(av[i][j]))
		return (0);
	if (av[i][j] == 'K')
		return (1);
	return (ft_r_s_p(av, ac, i, j + 1));
}

int	ft_rook(char **av, int ac, int i, int j)
{
	if (ft_r_m_s(av, ac, i - 1, j))
		return (1);
	if (ft_r_s_m(av, ac, i, j - 1))
		return (1);
	if (ft_r_p_s(av, ac, i + 1, j))
		return (1);
	if (ft_r_s_p(av, ac, i, j + 1))
		return (1);
	return (0);
}
