/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:24:21 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 08:54:17 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	allow_mem_sprite(t_image **img)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		img[i] = ft_calloc(2, sizeof(t_image));
		if (!img[i])
		{
			if (i > 0)
				while (--i >= 0)
					ft_free(img[i]);
			return (perror("malloc fail allow_mem_sprite()"), false);
		}
		i++;
	}
	return (true);
}

static void	free_first_sprite(t_image **player, t_mlx_data *data)
{
	mlx_destroy_image(data->co, player[0][0].pnt);
	mlx_destroy_image(data->co, player[1][0].pnt);
	mlx_destroy_image(data->co, player[2][0].pnt);
	mlx_destroy_image(data->co, player[3][0].pnt);
}

static t_bool	init_player_sprite_first(t_game *g, t_mlx_data *data)
{
	if (!ft_mlx_xpm(&g->sprite.player[0][0], data, PLAYERUP1, g->tile_size))
		return (false);
	if (!ft_mlx_xpm(&g->sprite.player[1][0], data, PLAYERDOWN1, g->tile_size))
	{
		mlx_destroy_image(data->co, g->sprite.player[0][0].pnt);
		return (false);
	}
	if (!ft_mlx_xpm(&g->sprite.player[2][0], data, PLAYERRIGHT1, g->tile_size))
	{
		mlx_destroy_image(data->co, g->sprite.player[0][0].pnt);
		mlx_destroy_image(data->co, g->sprite.player[1][0].pnt);
		return (false);
	}
	if (!ft_mlx_xpm(&g->sprite.player[3][0], data, PLAYERLEFT1, g->tile_size))
	{
		mlx_destroy_image(data->co, g->sprite.player[0][0].pnt);
		mlx_destroy_image(data->co, g->sprite.player[1][0].pnt);
		mlx_destroy_image(data->co, g->sprite.player[2][0].pnt);
		return (false);
	}
	return (true);
}

static t_bool	init_player_sprite_second(t_game *g, t_mlx_data *data)
{
	if (!ft_mlx_xpm(&g->sprite.player[0][1], data, PLAYERUP2, g->tile_size))
		return (false);
	if (!ft_mlx_xpm(&g->sprite.player[1][1], data, PLAYERDOWN2, g->tile_size))
	{
		mlx_destroy_image(data->co, g->sprite.player[0][1].pnt);
		return (false);
	}
	if (!ft_mlx_xpm(&g->sprite.player[2][1], data, PLAYERRIGHT2, g->tile_size))
	{
		mlx_destroy_image(data->co, g->sprite.player[0][1].pnt);
		mlx_destroy_image(data->co, g->sprite.player[1][1].pnt);
		return (false);
	}
	if (!ft_mlx_xpm(&g->sprite.player[3][1], data, PLAYERLEFT2, g->tile_size))
	{
		mlx_destroy_image(data->co, g->sprite.player[0][1].pnt);
		mlx_destroy_image(data->co, g->sprite.player[1][1].pnt);
		mlx_destroy_image(data->co, g->sprite.player[2][1].pnt);
		return (false);
	}
	return (true);
}

t_bool	init_player(t_game *g, t_tile *tile)
{
	g->player.pos = get_tile(tile, 'P').pos;
	g->player.last_pos = g->player.pos;
	g->sprite.player = ft_calloc(4, sizeof(t_image *));
	if (!g->sprite.player)
		return (perror("malloc fail init_player()"), false);
	if (!allow_mem_sprite(g->sprite.player))
	{
		ft_free(g->sprite.player);
		return (false);
	}
	if (!init_player_sprite_first(g, &g->data))
	{
		free_player_sprite(g->sprite.player);
		return (false);
	}
	if (!init_player_sprite_second(g, &g->data))
	{
		free_first_sprite(g->sprite.player, &g->data);
		free_player_sprite(g->sprite.player);
		return (false);
	}
	g->sprite.u_player = g->sprite.player[1][0];
	g->player.sprite_nb.x = 1;
	g->player.sprite_nb.y = 0;
	return (true);
}
