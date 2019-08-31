/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 09:57:13 by exam              #+#    #+#             */
/*   Updated: 2019/08/31 12:56:20 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_ordot(char c)
{
	if (c > 31 && c < 127)
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	ft_printhex_twodig(unsigned char c)
{
	char *str;
	
	str = "0123456789abcdef";
	ft_putchar_ordot(str[c / 16]);
	ft_putchar_ordot(str[c % 16]);
}


void	print_memory(const void *addr, size_t size)
{
	unsigned char	*ad;
	size_t	i;

	ad = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		while (i < 16 && i < size)
		{
			ft_printhex_twodig(ad[i]);
			if (i % 2 != 0)
				write(1, " ", 1);
			i++;
		}
		while (i < 16)
		{
			write(1, "  ", 2);
            if (i % 2 != 0)
                write(1, " ", 1);
			i++;
		}
		i = 0;
		while (i < 16 && i < size)
        {
			ft_putchar_ordot(ad[i]);
			i++;
		}
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
	write(1, "\n\n", 2);
	return (0);
}
/*
$> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e

0000 0000 1700 0000 9600 0000 ff00 0000 ................$
0c00 0000 1000 0000 2a00 0000 6700 0000 ........*...g...$
0000 0000 0000 0000                     ........$

*/
