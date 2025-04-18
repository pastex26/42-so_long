/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:10:40 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/06 15:40:12 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	t_bool	check_coin_collected(t_coin *coin)
{
	size_t	i;

	i = 0;
	while (coin[i].pos.x != -1)
	{
		if (coin[i].active == 1)
			return (false);
		i++;
	}
	return (true);
}

static t_bool	check_wall_colision(t_map *m, t_coin *coin, t_vector new_pos)
{
	size_t	i;

	i = 0;
	while (m->map_tab[i].id != -1)
	{
		if (m->map_tab[i].pos.x == new_pos.x
			&& m->map_tab[i].pos.y == new_pos.y)
		{
			if (m->map_tab[i].id == 'E' && !check_coin_collected(coin))
				return (false);
			if (m->map_tab[i].id != '1')
				return (true);
			else
				return (false);
		}
		i++;
	}
	return (false);
}

static void	update_player_sprite(t_game *g, int key)
{
	if (key == XK_w)
	{
		g->player.sprite_nb = (t_vector){0, 0};
		g->sprite.u_player = g->sprite.player[0][0];
	}
	if (key == XK_s)
	{
		g->player.sprite_nb = (t_vector){1, 0};
		g->sprite.u_player = g->sprite.player[1][0];
	}
	if (key == XK_a)
	{
		g->player.sprite_nb = (t_vector){3, 0};
		g->sprite.u_player = g->sprite.player[3][0];
	}
	if (key == XK_d)
	{
		g->player.sprite_nb = (t_vector){2, 0};
		g->sprite.u_player = g->sprite.player[2][0];
	}
}

t_bool	move_player(t_game *g, int key)
{
	t_vector	new_pos;
	int			move;

	new_pos = g->player.pos;
	update_player_sprite(g, key);
	if (key == XK_w)
		new_pos.y -= 1;
	if (key == XK_s)
		new_pos.y += 1;
	if (key == XK_a)
		new_pos.x -= 1;
	if (key == XK_d)
		new_pos.x += 1;
	move = check_wall_colision(&g->map, g->coin, new_pos);
	if (!move)
		return (0);
	g->player.last_pos = g->player.pos;
	g->player.pos = new_pos;
	g->score += move;
	return (true);
}
