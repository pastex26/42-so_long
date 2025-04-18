/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:29:50 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 08:23:56 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_vector	get_win_size(t_game *g)
{
	t_vector	size;

	size = (t_vector){0, 0};
	if (g->map.map_size.x > g->map.map_size.y)
		g->tile_size = WIN_SIZE / g->map.map_size.x;
	else
		g->tile_size = WIN_SIZE / g->map.map_size.y;
	size.x = g->map.map_size.x * g->tile_size;
	size.y = g->map.map_size.y * g->tile_size + 50;
	return (size);
}

static t_bool	init_window(t_game *g)
{
	t_vector	win_size;

	win_size = (t_vector){0, 0};
	g->data.co = mlx_init();
	if (!g->data.co)
		return (ft_printf("Error\nmlx pointer fail\n"), false);
	win_size = get_win_size(g);
	(void)win_size;
	g->data.win = mlx_new_window(g->data.co, win_size.x, win_size.y, WIN_TITLE);
	if (!g->data.win)
	{
		mlx_destroy_display(g->data.co);
		free(g->data.co);
		return (ft_printf("Error\nmlx window fail\n"), false);
	}
	return (true);
}

static t_bool	init_coin_player_enemy(t_game *g)
{
	if (!init_coin(g, g->map.map))
	{
		free_map(&g->map);
		free_map_sprite(g);
		free_mlx(&g->data);
		return (false);
	}
	if (!init_player(g, g->map.map_tab))
	{
		free_map(&g->map);
		free_map_sprite(g);
		free_coin(g);
		free_mlx(&g->data);
		return (false);
	}
	if (!init_enemy(g))
	{
		free_map(&g->map);
		free_map_sprite(g);
		free_coin(g);
		free_player(&g->data, g->sprite.player);
		free_mlx(&g->data);
		return (false);
	}
	return (true);
}

t_bool	init_game(t_game *g, char *map_file)
{
	g->map.map = ft_read_file(open(map_file, O_RDONLY));
	if (!g->map.map)
		return (ft_printf("Error\nread map fail\n"), false);
	g->map.map_size = get_map_size(g->map.map);
	if (!check_map_letter(g->map.map))
	{
		ft_free(g->map.map);
		return (false);
	}
	if (!init_window(g))
	{
		ft_free(g->map.map);
		return (false);
	}
	if (!init_map(g, map_file))
	{
		free_mlx(&g->data);
		return (false);
	}
	if (!init_coin_player_enemy(g))
		return (false);
	g->score = 0;
	g->last_frame = 0;
	g->playing = true;
	return (true);
}
