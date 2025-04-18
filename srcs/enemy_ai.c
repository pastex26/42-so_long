/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lmarcucc42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:36:37 by lmarcucc          #+#    #+#             */
/*   Updated: 2024/12/30 16:48:46 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	valid_tile(t_tile *tile, int x, int y)
{
	if (tile_id(tile, x, y) == 'E' || tile_id(tile, x, y) == '1'
		|| tile_id(tile, x, y) == 'C')
		return (false);
	return (true);
}

void	move_enemy_h(t_enemy *e, t_tile *tile)
{
	if (e->dir == 0)
	{
		if (valid_tile(tile, e->pos.x + 1, e->pos.y))
			e->pos.x += 1;
		else if (valid_tile(tile, e->pos.x - 1, e->pos.y))
		{
			e->pos.x -= 1;
			e->dir = 1;
		}
	}
	else
	{
		if (valid_tile(tile, e->pos.x - 1, e->pos.y))
			e->pos.x -= 1;
		else if (valid_tile(tile, e->pos.x + 1, e->pos.y))
		{
			e->pos.x += 1;
			e->dir = 0;
		}
	}
}

void	move_enemy_v(t_enemy *e, t_tile *tile)
{
	if (e->dir == 0)
	{
		if (valid_tile(tile, e->pos.x, e->pos.y + 1))
			e->pos.y += 1;
		else if (valid_tile(tile, e->pos.x, e->pos.y - 1))
		{
			e->pos.y -= 1;
			e->dir = 1;
		}
	}
	else
	{
		if (valid_tile(tile, e->pos.x, e->pos.y - 1))
			e->pos.y -= 1;
		else if (valid_tile(tile, e->pos.x, e->pos.y + 1))
		{
			e->pos.y += 1;
			e->dir = 0;
		}
	}
}

void	move_enemy(t_enemy *enemy, t_tile *tile)
{
	size_t	i;

	i = 0;
	while (enemy[i].pos.x != -1)
	{
		enemy[i].last_pos = enemy[i].pos;
		if (enemy[i].behavior == 'H')
			move_enemy_h(&enemy[i], tile);
		else
			move_enemy_v(&enemy[i], tile);
		i++;
	}
}
