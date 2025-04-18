/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:12:12 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 08:56:05 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_enemy(t_tile *tile)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (tile[i].id != -1)
	{
		if (tile[i].id == 'V' || tile[i].id == 'H')
			count++;
		i++;
	}
	return (count);
}

void	init_enemy_tab(t_enemy *enemy, t_tile *tiles, int nb)
{
	size_t	i;

	i = 0;
	enemy[nb].pos.x = -1;
	while (tiles[i].id != -1)
	{
		if (tiles[i].id == 'V' || tiles[i].id == 'H')
		{
			enemy[nb - 1].pos = tiles[i].pos;
			enemy[nb - 1].last_pos = tiles[i].pos;
			if (tiles[i].id == 'V')
				enemy[nb - 1].behavior = 'V';
			else
				enemy[nb - 1].behavior = 'H';
			nb--;
		}
		i++;
	}
}

t_bool	init_enemy(t_game *g)
{
	size_t	count;

	count = count_enemy(g->map.map_tab);
	if (!ft_mlx_xpm(&g->sprite.enemy, &g->data, ENEMY, g->tile_size))
		return (false);
	g->enemy = ft_calloc(count + 1, sizeof(t_enemy));
	if (!g->enemy)
	{
		mlx_destroy_image(g->data.co, g->sprite.enemy.pnt);
		return (perror("malloc fail init_enemy()"), false);
	}
	init_enemy_tab(g->enemy, g->map.map_tab, count);
	return (true);
}
