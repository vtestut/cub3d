/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:27:39 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/30 11:50:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

typedef struct s_words {
	const char		*start;
	size_t			len;
}	t_word;

static char	**g_retv;

static void	free_all(char **r, t_list lst)
{
	char	**atmp;
	t_list	tmp;

	while (lst.list)
	{
		tmp.list = lst.list->next;
		if (lst.list->content)
			free(lst.list->content);
		free(lst.list);
		lst = tmp;
	}
	if (!r)
		return ;
	atmp = r;
	while (*r)
		free(*(r++));
	free(atmp);
}

static t_word	*allocate_word(const char **str, const char *charset)
{
	t_word	*word;
	size_t	i;

	word = malloc(sizeof(t_word));
	if (!word)
		return (NULL);
	word->start = *str;
	i = 0;
	while (!ft_strchr(charset, *(*str)++))
		++i;
	word->len = i;
	return (word);
}

static t_list	create_words(const char *str, const char *charset)
{
	t_word		*new;
	t_list		lst;
	const char	*end;

	end = str + ft_strlen(str);
	lst = (t_list){.list = NULL};
	while (str < end)
	{
		if (!ft_strchr(charset, *str))
		{
			new = allocate_word(&str, charset);
			if (!new)
				return (free_all(NULL, lst), (t_list){.list = NULL});
			ft_lstaddback(&lst, ft_lstnew((void *)new));
		}
		else
			++str;
	}
	ft_lstaddback(&lst, ft_lstnew(NULL));
	return (lst);
}

static int	func_iter(size_t i, void *content)
{
	t_word	word;

	if (!content)
		return (g_retv[i] = NULL, 1);
	word = *(t_word *)content;
	g_retv[i] = ft_strndup(word.start, word.len);
	if (!g_retv[i])
		return (0);
	return (1);
}

char	**ft_splitcs(const char *str, const char *charset)
{
	t_list	words;
	char	**retv;

	if (!str)
		return (NULL);
	words = create_words(str, charset);
	if (!words.list)
		return (NULL);
	retv = malloc(sizeof(char *) * (ft_lstsize(words)));
	if (!retv)
		return (free_all(NULL, words), NULL);
	g_retv = retv;
	if (!ft_lstiteri(words, func_iter))
		return (free_all(retv, words), NULL);
	free_all(NULL, words);
	return (retv);
}
