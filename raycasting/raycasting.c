/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawish <sshawish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:20:28 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/26 13:00:32 by sshawish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	initialize_ray_steps(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	draw_floor(t_data *data, int x, int y)
{
	t_floor	floor_draw;

	calculate_floor_values(data, x, y, &floor_draw);
	floor_draw.tex_x = (int)(floor_draw.floor_x
			* TEXTURE_WIDTH) % TEXTURE_WIDTH;
	floor_draw.tex_y = (int)(floor_draw.floor_y
			* TEXTURE_HEIGHT) % TEXTURE_HEIGHT;
	if (floor_draw.tex_x < 0)
		floor_draw.tex_x += TEXTURE_WIDTH;
	if (floor_draw.tex_y < 0)
		floor_draw.tex_y += TEXTURE_HEIGHT;
	floor_draw.color = get_texture_color(data->textures->floor,
			floor_draw.tex_x, floor_draw.tex_y);
	put_pixel(data, x, y, floor_draw.color);
}

void	cast_ray(int x, t_data *data)
{
	t_ray	ray;
	int		y;

	y = 0;
	calculate_ray_direction(x, data, &ray);
	initialize_ray_steps(data, &ray);
	perform_dda(data, &ray);
	calculate_wall_distance_and_height(data, &ray);
	draw_textured_wall(x, &ray, data);
	while (y < ray.draw_start)
	{
		put_pixel(data, x, y, data->ceiling_color);
		y++;
	}
	y = ray.draw_end + 1;
	while (y > 0 && y < SCREEN_HEIGHT)
	{
		draw_floor(data, x, y);
		y++;
	}
}

int	render_frame(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cast_ray(x, data);
		x++;
	}
	draw_minimap(data);
	draw_player_minimap(data);
	draw_player_dir(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.ptr, 0, 0);
	return (0);
}
