/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:45:25 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/01 00:48:04 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *g)
{
	t_vector	pos;

	pos.x = g->player.pos.x * g->tile_size;
	pos.y = g->player.pos.y * g->tile_size;
	ft_mlx_itow(&g->sprite.u_player, &g->data, pos);
}

void	draw_coin(t_game *g)
{
	size_t		i;
	t_vector	pos;

	i = 0;
	while (g->coin[i].pos.x != -1)
	{
		if (g->coin[i].active)
		{
			pos.x = g->coin[i].pos.x * g->tile_size;
			pos.y = g->coin[i].pos.y * g->tile_size;
			ft_mlx_itow(&g->sprite.u_coin, &g->data, pos);
		}
		i++;
	}
}

void	draw_map(t_game *g)
{
	size_t		i;
	t_vector	pos;

	i = 0;
	while (g->map.map_tab[i].id != -1)
	{
		pos.x = g->map.map_tab[i].pos.x * g->tile_size;
		pos.y = g->map.map_tab[i].pos.y * g->tile_size;
		if (g->map.map_tab[i].id == '1')
			ft_mlx_itow(&g->sprite.wall, &g->data, pos);
		else if (g->map.map_tab[i].id == 'E')
			ft_mlx_itow(&g->sprite.exit, &g->data, pos);
		else
			ft_mlx_itow(&g->sprite.empty, &g->data, pos);
		i++;
	}
}

void	draw_enemy(t_game *g)
{
	size_t		i;
	t_vector	pos;

	i = 0;
	while (g->enemy[i].pos.x != -1)
	{
		pos.x = g->enemy[i].pos.x * g->tile_size;
		pos.y = g->enemy[i].pos.y * g->tile_size;
		ft_mlx_itow(&g->sprite.enemy, &g->data, pos);
		i++;
	}
}

void	draw_all(t_game *g)
{
	put_score(g);
	draw_player(g);
	draw_coin(g);
	draw_enemy(g);
}
