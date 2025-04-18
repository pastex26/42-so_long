/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lmarcucc42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:03:56 by lmarcucc          #+#    #+#             */
/*   Updated: 2024/11/11 16:00:27 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tab(char **tab, int index)
{
	index--;
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
}

static int	count_words(char const *s, char sep)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != sep && s[i + 1] == sep)
			|| (s[i] != sep && s[i + 1] == 0))
		{
			words++;
		}
		i++;
	}
	return (words);
}

static int	allow_mem(char **tab, char const *s, char sep)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != sep)
			count++;
		if ((s[i] != sep && s[i + 1] == sep)
			|| (s[i] != sep && s[i + 1] == 0))
		{
			tab[j] = ft_calloc(count + 1, sizeof(char));
			if (!tab[j])
				return (free_tab(tab, j), 0);
			j++;
			count = 0;
		}
		i++;
	}
	return (1);
}

static void	copy(char **tab, char const *s, char sep)
{
	size_t	str_index;
	size_t	tab_index;
	size_t	char_index;

	str_index = 0;
	tab_index = 0;
	char_index = 0;
	while (s[str_index])
	{
		if (s[str_index] != sep)
		{
			tab[tab_index][char_index] = s[str_index];
			char_index++;
		}
		if ((s[str_index] != sep && s[str_index + 1] == sep)
			|| (s[str_index] != sep && s[str_index + 1] == 0))
		{
			tab_index++;
			char_index = 0;
		}
		str_index++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = ft_calloc(words + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	if (!allow_mem(tab, s, c))
		return (free(tab), NULL);
	copy(tab, s, c);
	return (tab);
}
