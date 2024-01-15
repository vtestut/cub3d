/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:45:32 by vtestut          #+#    #+#             */
/*   Updated: 2023/11/23 18:38:59 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

t_list	ft_lstdup(t_list lst, void *(*dup)(void *), void (*del)(void *))
{
	t_list	new;
	t_list	tmp;
	t_list	iter;
	void	*content;

	new = (t_list){.list = NULL};
	iter = lst;
	while (iter.list)
	{
		content = dup(iter.list->content);
		if (!content)
		{
			ft_lstclear(new, del);
			return ((t_list){.list = NULL});
		}
		tmp = ft_lstnew(content);
		if (!tmp.list)
		{
			ft_lstclear(new, del);
			return ((t_list){.list = NULL});
		}
		ft_lstaddback(&new, tmp);
		iter.list = iter.list->next;
	}
	return (new);
}
