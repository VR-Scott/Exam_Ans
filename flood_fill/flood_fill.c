#include "t_point.h"
void	fill(char **tab, t_point size,int y,int x,char colour)
{
	if (x < size.x && y < size.y && x >= 0 && y >= 0 && tab[y][x] == colour)
	{
		tab[y][x] = 'F';
		fill(tab, size, y - 1, x, colour);
		fill(tab, size, y, x - 1, colour);
		fill(tab, size, y + 1, x, colour);
		fill(tab, size, y, x + 1, colour);
	}
}

void    flood_fill(char **tab, t_point size, t_point begin) 
{
	if (begin.x < size.x && begin.y < size.y && begin.x >= 0 && begin.y >= 0)
	{
		char colour = tab[begin.y][begin.x];
		fill(tab, size, begin.y, begin.x, colour);
	}
}
