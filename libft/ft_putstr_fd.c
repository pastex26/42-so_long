/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:03:45 by lmarcucc          #+#    #+#             */
/*   Updated: 2024/11/24 14:40:09 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
	size_t	count;

	count = 0;
	count += write(fd, s, ft_strlen(s));
	return (count);
}
