/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lmarcucc42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:55:38 by lmarcucc          #+#    #+#             */
/*   Updated: 2024/11/11 14:42:44 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if ((nmemb * size) > 2147483647)
		return (NULL);
	if (size <= 0 || nmemb <= 0)
	{
		size = 0;
		nmemb = 0;
	}
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}
