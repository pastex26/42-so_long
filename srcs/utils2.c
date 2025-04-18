/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:31:13 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 08:29:50 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	get_map_size(char *map)
{
	t_vector	size;
	size_t		i;

	i = 0;
	size = (t_vector){0, 0};
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1])
			size.y++;
		if (size.y == 0)
			size.x++;
		i++;
	}
	size.y++;
	return (size);
}

void	put_score(t_game *g)
{
	char	*score;

	score = ft_itoa(g->score);
	if (!score)
	{
		mlx_string_put(g->data.co, g->data.win, 50,
			g->map.map_size.y * g->tile_size + 25, 0xFFFFFF, "fail");
		return ;
	}
	mlx_string_put(g->data.co, g->data.win, 50,
		g->map.map_size.y * g->tile_size + 25, 0xFFFFFF, score);
	free(score);
}

t_tile	get_tile(t_tile *map, int c)
{
	size_t	i;

	i = 0;
	while (map[i].id != -1)
	{
		if (map[i].id == c)
			return (map[i]);
		i++;
	}
	return (map[0]);
}

int	tile_id(t_tile *tile, int x, int y)
{
	size_t	i;

	i = 0;
	while (tile[i].id != -1)
	{
		if (tile[i].pos.x == x && tile[i].pos.y == y)
			return (tile[i].id);
		i++;
	}
	return (tile[i].id);
}
