/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:10:19 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/06 11:30:37 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	possible_tile(t_tile *tile, t_vector pos, t_vector size, int **visited)
{
	if ((pos.x + 1 < size.x && tile_id(tile, pos.x + 1, pos.y) != '1'
			&& !visited[pos.x + 1][pos.y]) || (pos.x - 1 >= 0 && tile_id(tile,
				pos.x - 1, pos.y) != '1' && !visited[pos.x - 1][pos.y])
		|| (pos.y + 1 < size.y && tile_id(tile, pos.x, pos.y + 1) != '1'
			&& !visited[pos.x][pos.y + 1]) || (pos.y - 1 >= 0 && tile_id(tile,
				pos.x, pos.y - 1) != '1' && !visited[pos.x][pos.y - 1]))
		return (true);
	return (false);
}

t_bool	solve_path(t_tile *tile, t_vector *pos, t_vector size, int **visited)
{
	t_vector	direction[4];
	t_vector	new_pos[2];
	size_t		i;

	direction[0] = (t_vector){1, 0};
	direction[1] = (t_vector){-1, 0};
	direction[2] = (t_vector){0, 1};
	direction[3] = (t_vector){0, -1};
	if (pos[0].x == pos[1].x && pos[0].y == pos[1].y)
		return (true);
	if (visited[pos[0].x][pos[0].y]
		|| !possible_tile(tile, pos[0], size, visited))
		return (false);
	visited[pos[0].x][pos[0].y] = 1;
	i = -1;
	while (++i < 4 && tile_id(tile, pos[0].x, pos[0].y) != '1')
	{
		new_pos[0] = pos[0];
		new_pos[0].x += direction[i].x;
		new_pos[0].y += direction[i].y;
		new_pos[1] = pos[1];
		if (solve_path(tile, new_pos, size, visited))
			return (true);
	}
	return (false);
}

int	**init_visited(t_vector size)
{
	int	i;
	int	**visited;

	visited = ft_calloc(size.x, sizeof(int *));
	if (!visited)
		return (perror("malloc fail init_visited()"), NULL);
	i = 0;
	while (i < size.x)
	{
		visited[i] = ft_calloc(size.y, sizeof(int));
		if (!visited[i])
		{
			while (--i >= 0)
				ft_free(visited[i]);
			ft_free(visited);
			return (perror("malloc fail init_visited()"), NULL);
		}
		i++;
	}
	return (visited);
}

t_bool	check_path(t_tile *tile, t_vector size)
{
	int			**visited;
	t_vector	pos[2];

	visited = init_visited(size);
	if (!visited)
		return (false);
	pos[0] = get_tile(tile, 'P').pos;
	pos[1] = get_tile(tile, 'E').pos;
	if (!solve_path(tile, pos, size, visited))
	{
		free_pathfinding(visited, size);
		return (ft_printf("Error\nno valid path to Exit\n"), false);
	}
	free_pathfinding(visited, size);
	return (true);
}
