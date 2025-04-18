/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:01:43 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 08:25:33 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_enemy(t_game *g)
{
	ft_free(g->enemy);
	mlx_destroy_image(g->data.co, g->sprite.enemy.pnt);
}

void	free_player_sprite(t_image **player)
{
	ft_free(player[0]);
	ft_free(player[1]);
	ft_free(player[2]);
	ft_free(player[3]);
	ft_free(player);
}

void	free_player(t_mlx_data *data, t_image **player)
{
	mlx_destroy_image(data->co, player[0][0].pnt);
	mlx_destroy_image(data->co, player[0][1].pnt);
	mlx_destroy_image(data->co, player[1][0].pnt);
	mlx_destroy_image(data->co, player[1][1].pnt);
	mlx_destroy_image(data->co, player[2][0].pnt);
	mlx_destroy_image(data->co, player[2][1].pnt);
	mlx_destroy_image(data->co, player[3][0].pnt);
	mlx_destroy_image(data->co, player[3][1].pnt);
	free_player_sprite(player);
}

void	free_coin(t_game *g)
{
	ft_free(g->coin);
	mlx_destroy_image(g->data.co, g->sprite.coin[0].pnt);
	mlx_destroy_image(g->data.co, g->sprite.coin[1].pnt);
	mlx_destroy_image(g->data.co, g->sprite.coin[2].pnt);
	ft_free(g->sprite.coin);
}

void	free_all(t_game *g)
{
	free_map(&g->map);
	free_map_sprite(g);
	free_player(&g->data, g->sprite.player);
	free_coin(g);
	free_enemy(g);
	mlx_destroy_window(g->data.co, g->data.win);
	mlx_destroy_display(g->data.co);
	ft_free(g->data.co);
}
