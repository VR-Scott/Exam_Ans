#include <stdlib.h>
#include <stdio.h>

int	is_prime(int nb)
{
	int i = 2;

	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return(0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int nb;
		int i = 2;
		int fst = 0;

		nb = atoi(av[1]);
		if (is_prime(nb))
			printf("%d", nb);
		else
			while (i <= nb)
			{
				if (is_prime(i))
					if (nb % i == 0)
					{
						if (fst++)
							printf("*");
						printf("%d", i);
						nb /= i;
						i = 1;
					}
				i++;
			}
	}
	printf("\n");
	return (0);
}
