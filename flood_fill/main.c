#include "t_point.h"                                                            
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char *str)
{
	int i = 0;

	while(str[i])
	{
		ft_putchar(str[i++]);
	}
	ft_putchar('\n');
}

void	print_tab(char **tab)
{
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}

char	**make_area(char **zone, t_point size) 
{                                                                               
    int i = 0;                                                                  
    char **area = (char**)malloc(sizeof(char*) * size.y);                       
                                                                                
    while (i < size.y)                                                          
    {                                                                           
        area[i] = strdup(zone[i]);                                              
        i++;                                                                    
    }
	area[i] = NULL;
    return (area);                                                              
}                                                                               
                                                                                
int		main(void)
{                                                                               
    char **area;                                                                
    t_point size = { 8, 5 };                                                    
    t_point begin = { 29, 24 };                                                   
    char *zone[] = {                                                            
        "11111111",                                                             
        "10001001",                                                             
        "10010001",                                                             
        "10110001",                                                             
        "11100001"                                                              
    };                                                                          
                                                                                
    area = make_area(zone, size);
    print_tab(area);                                                            
    flood_fill(area, size, begin);                                              
    ft_putchar('\n');
    print_tab(area);                                                            
    return (0);                                                                 
}                                                                               
