/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:04:14 by lmarcucc          #+#    #+#             */
/*   Updated: 2024/11/24 11:00:46 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;

	res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, s);
	return (res);
}
