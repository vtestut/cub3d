/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:46:13 by vtestut            #+#    #+#             */
/*   Updated: 2023/06/14 12:59:08 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	ft_lstnew(void *content)
{
	t_list	new;

	new.list = malloc(sizeof(struct s_list));
	if (!new.list)
		return ((t_list){.list = NULL});
	ft_memset(new.list, 0, sizeof(struct s_list));
	new.list->content = content;
	return (new);
}
