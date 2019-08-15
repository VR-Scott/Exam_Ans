#ifndef check_mate_h
# define check_mate_h

#include <unistd.h>

void	ft_putchar(char c);
int		ft_pawn(char **av, int ac, int i, int j);
int		ft_ispiece(char c);
int		ft_r_m_s(char **av, int ac, int i, int j);
int		ft_r_s_m(char **av, int ac, int i, int j);
int		ft_r_p_s(char **av, int ac, int i, int j);
int		ft_r_s_p(char **av, int ac, int i, int j);
int		ft_rook(char **av, int ac, int i, int j);
int		ft_b_m_m(char **av, int ac, int i, int j);
int		ft_b_m_p(char **av, int ac, int i, int j);
int		ft_b_p_m(char **av, int ac, int i, int j);
int		ft_b_p_p(char **av, int ac, int i, int j);
int		ft_bish(char **av, int ac, int i, int j);

# endif
