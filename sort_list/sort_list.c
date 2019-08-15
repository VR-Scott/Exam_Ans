/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:10:58 by exam              #+#    #+#             */
/*   Updated: 2019/07/18 16:51:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	swap_data(t_list *lst)
{
	int tmp;

	tmp = lst->data;
	lst->data = lst->next->data;
	lst->next->data = tmp;
}

t_list	*sort_list(t_list *lst, int(*cmp)(int, int))
{
	t_list	*tmp = lst;
	int		c; 

	while(lst)
	{
		c = 0;
		tmp = lst;
		while (tmp->next)
		{
			if(!cmp(tmp->data, tmp->next->data))
			{
				swap_data(tmp);
				c++;
			}
			tmp = tmp->next;
		}
		if (c == 0)
			break ;
	}
	return (lst);
}
