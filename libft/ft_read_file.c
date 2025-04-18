/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:26:31 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 08:26:43 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*res;
	int		read_size;

	if (fd == -1)
		return (close(fd), NULL);
	read_size = 1;
	res = NULL;
	while (read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			close(fd);
			return (ft_free(res), NULL);
		}
		else if (read_size == 0)
			return (close(fd), res);
		buffer[read_size] = '\0';
		res = ft_strjoin_free(res, buffer);
		if (!res)
			return (close(fd), NULL);
	}
	return (close(fd), res);
}
