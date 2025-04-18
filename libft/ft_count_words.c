/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:33:57 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/01 19:38:50 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *str)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i + 1] == ' ')
			|| (str[i] != ' ' && str[i + 1] == 0))
		{
			words++;
		}
		i++;
	}
	return (words);
}
