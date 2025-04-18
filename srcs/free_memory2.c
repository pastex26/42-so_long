/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:21:20 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/01 00:34:04 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx(t_mlx_data *data)
{
	mlx_destroy_window(data->co, data->win);
	mlx_destroy_display(data->co);
	free(data->co);
}

void	free_map_sprite(t_game *g)
{
	mlx_destroy_image(g->data.co, g->sprite.wall.pnt);
	mlx_destroy_image(g->data.co, g->sprite.empty.pnt);
	mlx_destroy_image(g->data.co, g->sprite.exit.pnt);
}

void	free_map(t_map *map)
{
	ft_free(map->map);
	ft_free(map->map_tab);
}

void	free_pathfinding(int **visited, t_vector size)
{
	while (size.x - 1 >= 0)
	{
		ft_free(visited[size.x - 1]);
		size.x--;
	}
	free(visited);
	visited = NULL;
}
