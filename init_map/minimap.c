/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:03:38 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/28 08:42:47 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_player_dir(t_data *data)
{
	t_minimap	d;

	d.i = 0;
	d.dx = data->player.dir_x;
	d.dy = data->player.dir_y;
	d.px = MINIMAP_MARGIN + (int)(data->player.pos_x * TILE_SIZE);
	d.py = MINIMAP_MARGIN + (int)(data->player.pos_y * TILE_SIZE);
	while (d.i < 10)
	{
		d.x = d.px + (int)(d.dx * d.i);
		d.y = d.py + (int)(d.dy * d.i);
		put_pixel(data, d.x, d.y, 0x00FF00);
		d.i++;
	}
}

void	draw_player_minimap(t_data *data)
{
	t_minimap	d;

	d.size = 2;
	d.px = MINIMAP_MARGIN + (int)(data->player.pos_x * TILE_SIZE);
	d.py = MINIMAP_MARGIN + (int)(data->player.pos_y * TILE_SIZE);
	d.y = -d.size;
	while (d.y <= d.size)
	{
		d.x = -d.size;
		while (d.x <= d.size)
		{
			put_pixel(data, d.px + d.x, d.py + d.y, 0xFF0000);
			d.x++;
		}
		d.y++;
	}
}

void	draw_minimap_tile(t_data *data, int i, int j, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			put_pixel(data,
				MINIMAP_MARGIN + j * TILE_SIZE + x,
				MINIMAP_MARGIN + i * TILE_SIZE + y,
				color);
			x++;
		}
		y++;
	}
}

void	get_minimap_tile_color(char tile, int *color)
{
	if (tile == '1')
		*color = 0x333333;
	else if (tile == '0' || tile == ' ')
		*color = 0xBBBBBB;
	else if (tile == 'D' || tile == 'O')
		*color = 0xFF0000;
	else
		*color = -1;
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			get_minimap_tile_color(data->map[i][j], &color);
			if (color != -1)
				draw_minimap_tile(data, i, j, color);
			j++;
		}
		i++;
	}
}
