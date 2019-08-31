#include <unistd.h>

/*int		is_print(char c)
{
	return (c > 31 && c < 127);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_memhex(unsigned char mem)
{
		char *hex = "0123456789abcdef";

		ft_putchar(hex[mem / 16]);
		ft_putchar(hex[mem % 16]);
}

void	print_memchar(unsigned char *tab, size_t j)
{
	size_t	i = 0;

	while (i < j && (!i || (i % 16)))
	{
		if (is_print(tab[i]))
			ft_putchar(tab[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char *tab = (unsigned char*)addr;
	size_t i = 0;

	while (i < size || (i % 16) || !i)
	{
		if (i >= size && i++)
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		else
			print_memhex(tab[i++]);
		//ft_putchar(i + '0');
		if (!(i % 2))
			ft_putchar(' ');
		if (!(i % 16))
		   print_memchar(&tab[i - 16], size - (i - 16));
	}
}*/

void	putcharordot(char c)
{
	if (c > 31 && c < 127)
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	printhex(unsigned char c)
{
	char *str = "0123456789abcdef";
	putcharordot(str[c / 16]);
	putcharordot(str[c % 16]);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char *ad = (unsigned char*)addr;
	size_t i = 0;

	while (i < size)
	{
		while (i < 16 && i < size)
		{
			printhex(ad[i]);
			if (i % 2)
				write(1, " ",1);
			i++;
		}
		while (i < 16)
		{
			write(1, "  ", 2);
			if (i % 2)
				write(1, " ", 1);
			i++;
		}
		i = 0;
		while (i < 16 && i < size)
			putcharordot(ad[i++]);
		size -= i;
		ad += i;
		write(1, "\n", 1);
		i = 0;
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 65536,
	             12, 16,  42, 103};
	print_memory(tab, sizeof(tab));
	return (0);
}
