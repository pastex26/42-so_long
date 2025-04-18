/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:17:26 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 07:58:16 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

t_bool	ft_mlx_xpm(t_image *img, t_mlx_data *data, char *path, int size)
{
	img->pnt = mlx_xpm_file_to_image(data->co, path, &img->size.x,
			&img->size.y);
	if (!img->pnt)
		return (false);
	img->pixels = mlx_get_data_addr(img->pnt, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	*img = resize_mlx_image(data->co, img, size);
	if (!img->pnt)
		return (false);
	return (true);
}

void	ft_mlx_itow(t_image *img, t_mlx_data *data, t_vector pos)
{
	mlx_put_image_to_window(data->co, data->win, img->pnt, pos.x, pos.y);
}

static t_image	refill_pixels(t_image dest, t_image src, t_dvector scale,
	int tile_size)
{
	int		i;
	int		j;
	int		k;
	char	*src_pixel;
	char	*dest_pixel;

	i = -1;
	while (++i <= tile_size)
	{
		j = -1;
		while (++j <= tile_size)
		{
			k = -1;
			src_pixel = src.pixels + ((int)(i * scale.y) *src.line_length
					+ ((int)(j * scale.x) *(src.bits_per_pixel / 8)));
			dest_pixel = dest.pixels + (i * dest.line_length + j
					* (dest.bits_per_pixel / 8));
			while (++k <= src.bits_per_pixel / 8)
				dest_pixel[k] = src_pixel[k];
		}
	}
	return (dest);
}

t_image	resize_mlx_image(void *mlx_ptr, t_image *src_img, int tile_size)
{
	t_image		resized_img;
	t_dvector	scale;

	scale.x = (double)src_img->size.x / tile_size;
	scale.y = (double)src_img->size.y / tile_size;
	resized_img.pnt = mlx_new_image(mlx_ptr, tile_size, tile_size);
	if (!resized_img.pnt)
	{
		mlx_destroy_image(mlx_ptr, src_img->pnt);
		return ((t_image){NULL});
	}
	resized_img.pixels = mlx_get_data_addr(resized_img.pnt,
			&resized_img.bits_per_pixel, &resized_img.line_length,
			&resized_img.endian);
	resized_img.size.x = tile_size;
	resized_img.size.y = tile_size;
	resized_img = refill_pixels(resized_img, *src_img, scale, tile_size);
	mlx_destroy_image(mlx_ptr, src_img->pnt);
	return (resized_img);
}
