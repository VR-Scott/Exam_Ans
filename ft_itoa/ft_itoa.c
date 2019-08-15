#include <stdlib.h>

int	ft_dig_cnt(int nbr)
{
	int	d;

	d = 0;
	while (nbr)
	{
		nbr /= 10;
		d++;
	}
	return (d);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		dec;
	int		neg;
	int		i;

	if (nbr ==  -2147483648)
		return ("-2147483648");
	neg = 0;
	if (nbr == 0)
		return ("0");
	if (nbr < 0)
	{
		neg = -1;
		nbr *= -1;
	}
	dec = ft_dig_cnt(nbr);
	if (!(str = (char*)malloc(sizeof(char) * (dec + -neg + 1))))
		return (NULL);
	if (neg)
		str[0] = '-';
	i = dec + -neg;
	str[i--] = '\0';
	while (i >= -neg)
	{
		str[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
