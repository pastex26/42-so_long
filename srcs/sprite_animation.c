/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:11:26 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/01 00:34:11 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_image	update_coin(t_image *coin, t_image use_coin, int *nb)
{
	if (*nb == 0)
	{
		*nb = 1;
		use_coin = coin[1];
	}
	else if (*nb == 1)
	{
		*nb = 2;
		use_coin = coin[2];
	}
	else if (*nb == 2)
	{
		*nb = 0;
		use_coin = coin[0];
	}
	return (use_coin);
}

static t_image	update_player(t_image **img, t_image *use_img, t_vector *nb)
{
	if (nb->y == 0)
	{
		nb->y = 1;
		use_img = &img[nb->x][nb->y];
	}
	else if (nb->y == 1)
	{
		nb->y = 0;
		use_img = &img[nb->x][nb->y];
	}
	return (*use_img);
}

void	update_animation(t_game *g)
{
	g->sprite.u_coin = update_coin(g->sprite.coin, g->sprite.u_coin,
			&g->sprite.coin_sprite);
	g->sprite.u_player = update_player(g->sprite.player,
			&g->sprite.u_player, &g->player.sprite_nb);
}
