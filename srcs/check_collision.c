/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:21:32 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/01 00:33:57 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_enemy_collide(t_vector p_pos, t_vector pl_pos, t_enemy *enemy)
{
	size_t	i;

	i = 0;
	while (enemy[i].pos.x != -1)
	{
		if ((enemy[i].pos.x == p_pos.x && enemy[i].pos.y == p_pos.y)
			|| (enemy[i].last_pos.x == p_pos.x && enemy[i].last_pos.y == p_pos.y
				&& enemy[i].pos.x == pl_pos.x && enemy[i].pos.y == pl_pos.y))
			return (true);
		i++;
	}
	return (false);
}

t_bool	check_coin_colide(t_game *g)
{
	size_t	i;

	if (tile_id(g->map.map_tab, g->player.pos.x, g->player.pos.y) == 'C')
	{
		i = 0;
		while (g->coin[i].pos.x != -1)
		{
			if (g->coin[i].pos.x == g->player.pos.x
				&& g->coin[i].pos.y == g->player.pos.y)
			{
				g->coin[i].active = false;
				return (true);
			}
			i++;
		}
	}
	return (false);
}

t_bool	check_collision(t_game *g)
{
	check_coin_colide(g);
	if (check_enemy_collide(g->player.pos, g->player.last_pos, g->enemy)
		|| tile_id(g->map.map_tab, g->player.pos.x, g->player.pos.y) == 'E')
		return (true);
	return (false);
}
