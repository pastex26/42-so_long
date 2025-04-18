/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:23:46 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/06 11:54:53 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_win(t_game *g)
{
	free_all(g);
	exit (0);
}

static int	game_loop(t_game *g)
{
	long	current_time;
	long	elapsed_time;

	current_time = get_time_ms();
	if (g->last_frame == 0)
		g->last_frame = current_time;
	elapsed_time = current_time - g->last_frame;
	if (elapsed_time >= FRAME)
	{
		if (!g->playing)
		{
			put_score(g);
			return (0);
		}
		g->last_frame += FRAME;
		update_animation(g);
		draw_all(g);
	}
	return (1);
}

static int	handle_input(int key, t_game *g)
{
	if (key == XK_Escape)
	{
		free_all(g);
		exit(0);
	}
	if ((key == XK_w || key == XK_a || key == XK_d || key == XK_s)
		&& g->playing)
	{
		if (!move_player(g, key))
			return (0);
		move_enemy(g->enemy, g->map.map_tab);
		mlx_clear_window(g->data.co, g->data.win);
		if (check_collision(g))
		{
			g->playing = false;
			return (0);
		}
		draw_map(g);
		draw_all(g);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (ft_printf("Error\nno args map\n"), 1);
	if (!init_game(&game, argv[1]))
		return (1);
	draw_map(&game);
	draw_all(&game);
	mlx_hook(game.data.win, 17, 0, close_win, &game);
	mlx_hook(game.data.win, KeyPress, KeyPressMask, handle_input, &game);
	mlx_loop_hook(game.data.co, game_loop, &game);
	mlx_loop(game.data.co);
	free_all(&game);
	return (0);
}
