/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:00:47 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 08:46:54 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_map_size(int fd)
{
	char	*str;
	size_t	len;

	str = get_next_line(fd);
	if (!str)
		return (close(fd), false);
	len = ft_strlen(str);
	while (str)
	{
		if (str[ft_strlen(str) - 1] != '\n')
			len--;
		if (len != ft_strlen(str))
		{
			ft_free(str);
			close(fd);
			return (ft_printf("Error\nwrong map format\n"), false);
		}
		len = ft_strlen(str);
		ft_free(str);
		str = get_next_line(fd);
	}
	close(fd);
	ft_free(str);
	return (true);
}

t_bool	check_elements(t_tile *tile)
{
	size_t	i;
	int		count[3];

	ft_bzero(count, sizeof(count));
	i = 0;
	while (tile[i].id != -1)
	{
		if (tile[i].id == 'P')
			count[0] += 1;
		else if (tile[i].id == 'E')
			count[1] += 1;
		else if (tile[i].id == 'C')
			count[2] += 1;
		i++;
	}
	if (count[0] != 1 || count[1] != 1 || count[2] < 1)
	{
		ft_printf("Error\nelements invalid: Player=%d  | Exit=%d  | Coin=%d\n",
			count[0], count[1], count[2]);
		ft_printf("should be:\t  Player==1 | Exit==1 | Coin>0\n");
		return (false);
	}
	return (true);
}

t_bool	check_map_letter(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0'
			&& map[i] != 'C' && map[i] != 'E'
			&& map[i] != 'V' && map[i] != 'H'
			&& map[i] != 'P' && map[i] != '\n')
		{
			ft_printf("Error\nunrecognized map character \'%c\'\n", map[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

t_bool	check_map_border(t_tile *tile, t_vector size)
{
	size_t	i;

	i = 0;
	while (tile[i].id != -1)
	{
		if ((tile[i].pos.x == 0 && tile[i].id != '1')
			|| (tile[i].pos.y == 0 && tile[i].id != '1')
			|| (tile[i].pos.x == size.x - 1 && tile[i].id != '1')
			|| (tile[i].pos.y == size.y - 1 && tile[i].id != '1'))
			return (ft_printf("Error\nwrong map border\n"), false);
		i++;
	}
	return (true);
}

t_bool	check_map(t_map *map, t_vector size, int fd)
{
	if (!check_map_size(fd) || !check_map_letter(map->map)
		|| !check_map_border(map->map_tab, size)
		|| !check_elements(map->map_tab)
		|| !check_path(map->map_tab, size))
		return (false);
	return (true);
}
