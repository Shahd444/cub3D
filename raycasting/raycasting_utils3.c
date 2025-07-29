/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawish <sshawish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:26:53 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/26 13:00:29 by sshawish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	calculate_wall_distance_and_height(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player.pos_x
				+ (1 - ray->step_x) / 2.0) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player.pos_y
				+ (1 - ray->step_y) / 2.0) / ray->ray_dir_y;
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
}

int	get_texture_color(t_img *texture, int tex_x, int tex_y)
{
	int		color;
	char	*pixel;

	pixel = texture->addr + (tex_y * texture->line_length + tex_x
			* (texture->bits_per_pixel / 8));
	color = *(int *)pixel;
	return (color);
}

void	calculate_wall_texture(t_ray *ray, t_data *data, t_wallcast *w)
{
	if (ray->side == 0)
		w->wall_x = data->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		w->wall_x = data->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	w->wall_x -= floor(w->wall_x);
	w->tex_x = (int)(w->wall_x * TEXTURE_WIDTH);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		w->tex_x = TEXTURE_WIDTH - w->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		w->tex_x = TEXTURE_WIDTH - w->tex_x - 1;
	w->step = (double)TEXTURE_HEIGHT / ray->line_height;
	w->tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + ray->line_height / 2)
		* w->step;
}
