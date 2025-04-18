/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:52:57 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 08:24:51 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	init_map_sprite(t_game *g)
{
	if (!ft_mlx_xpm(&g->sprite.empty, &g->data, EMPTY, g->tile_size))
		return (false);
	if (!ft_mlx_xpm(&g->sprite.wall, &g->data, WALL, g->tile_size))
	{
		mlx_destroy_image(g->data.co, g->sprite.empty.pnt);
		return (false);
	}
	if (!ft_mlx_xpm(&g->sprite.exit, &g->data, EXIT, g->tile_size))
	{
		mlx_destroy_image(g->data.co, g->sprite.empty.pnt);
		mlx_destroy_image(g->data.co, g->sprite.wall.pnt);
		return (false);
	}
	return (true);
}

static void	init_map_tab(t_map *map)
{
	size_t		i;
	size_t		j;
	t_vector	i_pos;

	i = 0;
	j = 0;
	i_pos = (t_vector){0, 0};
	while (map->map[i])
	{
		if (map->map[i] == '\n')
		{
			i_pos.y++;
			i_pos.x = 0;
		}
		else
		{
			map->map_tab[j].id = map->map[i];
			map->map_tab[j].pos = i_pos;
			i_pos.x++;
			j++;
		}
		i++;
	}
	map->map_tab[map->map_size.x * map->map_size.y].id = -1;
}

t_bool	init_map(t_game *g, char *file_path)
{
	g->map.map_tab = malloc(sizeof(t_tile) * ((g->map.map_size.x
					* g->map.map_size.y)
				+ 1));
	if (!g->map.map_tab)
	{
		ft_free(g->map.map);
		return (false);
	}
	init_map_tab(&g->map);
	if (!check_map(&g->map, g->map.map_size, open(file_path, O_RDONLY)))
	{
		free_map(&g->map);
		return (false);
	}
	if (!init_map_sprite(g))
	{
		free_map(&g->map);
		return (false);
	}
	return (true);
}
