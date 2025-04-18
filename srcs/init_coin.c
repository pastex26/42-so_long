/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:24:33 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 08:54:58 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_coin_tab(t_coin *coins, t_tile *tile, int coin_nb)
{
	size_t	i;

	coins[coin_nb].pos = (t_vector){-1, -1};
	i = 0;
	while (tile[i].id != -1)
	{
		if (tile[i].id == 'C')
		{
			coins[coin_nb - 1].pos = tile[i].pos;
			coins[coin_nb - 1].active = true;
			coin_nb--;
		}
		i++;
	}
}

t_bool	init_coin_sprite(t_image **coin, t_mlx_data *data, size_t tile_size)
{
	*coin = ft_calloc(3, sizeof(t_image));
	if (!*coin)
		return (perror("malloc fail init_coin_sprite()"), false);
	if (!ft_mlx_xpm(&(*coin)[0], data, COIN1, tile_size))
	{
		free(*coin);
		return (false);
	}
	if (!ft_mlx_xpm(&(*coin)[1], data, COIN2, tile_size))
	{
		mlx_destroy_image(data->co, coin[0]->pnt);
		free(*coin);
		return (false);
	}
	if (!ft_mlx_xpm(&(*coin)[2], data, COIN3, tile_size))
	{
		mlx_destroy_image(data->co, coin[0]->pnt);
		mlx_destroy_image(data->co, coin[1]->pnt);
		free(*coin);
		return (false);
	}
	return (true);
}

t_bool	init_coin(t_game *g, char *map)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			count++;
		i++;
	}
	g->coin = ft_calloc(count + 1, sizeof(t_coin));
	if (!g->coin)
		return (perror("malloc fail init_coin()"), false);
	init_coin_tab(g->coin, g->map.map_tab, count);
	if (!init_coin_sprite(&g->sprite.coin, &g->data, g->tile_size))
	{
		ft_free(g->coin);
		return (false);
	}
	g->sprite.coin_sprite = 0;
	g->sprite.u_coin = g->sprite.coin[0];
	return (true);
}
