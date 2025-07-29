/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawish <sshawish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:21:18 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/26 13:00:23 by sshawish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	select_wall_texture(t_ray *ray, t_data *data, t_wallcast *w)
{
	char	tile;

	if (ray->hit_door)
	{
		tile = data->map[ray->map_y][ray->map_x];
		if (tile == 'D')
			w->texture_img = data->textures->door_closed;
		else if (tile == 'O')
			w->texture_img = data->textures->door_open;
		return ;
	}
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			w->texture_img = data->textures->east;
		else
			w->texture_img = data->textures->west;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			w->texture_img = data->textures->south;
		else
			w->texture_img = data->textures->north;
	}
}

void	draw_textured_wall(int x, t_ray *ray, t_data *data)
{
	t_wallcast	w;

	calculate_wall_texture(ray, data, &w);
	select_wall_texture(ray, data, &w);
	w.y = ray->draw_start;
	while (w.y < ray->draw_end)
	{
		w.tex_y = (int)w.tex_pos & (TEXTURE_HEIGHT - 1);
		w.color = get_texture_color(w.texture_img, w.tex_x, w.tex_y);
		put_pixel(data, x, w.y, w.color);
		w.tex_pos += w.step;
		w.y++;
	}
}

void	calculate_floor_values(t_data *data, int x, int y, t_floor *floor_draw)
{
	floor_draw->ray_dir_x0 = data->player.dir_x - data->player.plane_x;
	floor_draw->ray_dir_x1 = data->player.dir_x + data->player.plane_x;
	floor_draw->ray_dir_y0 = data->player.dir_y - data->player.plane_y;
	floor_draw->ray_dir_y1 = data->player.dir_y + data->player.plane_y;
	floor_draw->row_dist = (double)SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT);
	floor_draw->floor_step_x = floor_draw->row_dist * (floor_draw->ray_dir_x1
			- floor_draw->ray_dir_x0) / SCREEN_WIDTH;
	floor_draw->floor_step_y = floor_draw->row_dist * (floor_draw->ray_dir_y1
			- floor_draw->ray_dir_y0) / SCREEN_WIDTH;
	floor_draw->floor_x = data->player.pos_x + floor_draw->row_dist
		* floor_draw->ray_dir_x0 + x * floor_draw->floor_step_x;
	floor_draw->floor_y = data->player.pos_y + floor_draw->row_dist
		* floor_draw->ray_dir_y0 + x * floor_draw->floor_step_y;
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = data->img.addr + (y * data->img.line_length + x
			* (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	calculate_ray_direction(int x, t_data *data, t_ray *ray)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_dir_x = data->player.dir_x + data->player.plane_x * ray->camera_x;
	ray->ray_dir_y = data->player.dir_y + data->player.plane_y * ray->camera_x;
	ray->map_x = (int)data->player.pos_x;
	ray->map_y = (int)data->player.pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}
