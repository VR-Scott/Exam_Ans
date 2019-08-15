#include <unistd.h>

static int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_is_pal(char *s, int b, int e)
{
	while (b < e)
	{
		if (s[b++] != s[e--])
			return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	int b = 0;
	int big = 0;
	int len;
	int e;
	char *big_pal;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		e = len;
		while (av[1][b])
		{
			if (((e - b + 1) >= big) && ft_is_pal(av[1], b, e))
			{
				big_pal = &av[1][b];
				big = e - b + 1;
			}
			e--;
			if(b > e)
			{
				b ++;
				e = len;
				if (e - b + 1 < big)
					break;
			}
		}
		write(1, big_pal, big);
	}
	write(1, "\n", 1);
	return (0);
}
