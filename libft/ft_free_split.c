/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:22:35 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/01 19:30:40 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		ft_free(tab[i]);
		i++;
	}
	free(tab);
}
