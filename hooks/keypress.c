/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:11:18 by sshawish          #+#    #+#             */
/*   Updated: 2025/05/20 10:08:58 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	old_dir_y;
	double	old_plane_y;

	old_dir_x = data->player.dir_x;
	old_dir_y = data->player.dir_y;
	old_plane_x = data->player.plane_x;
	old_plane_y = data->player.plane_y;
	data->player.dir_x = old_dir_x * cos(-0.05) - old_dir_y * sin(-0.05);
	data->player.dir_y = old_dir_x * sin(-0.05) + old_dir_y * cos(-0.05);
	data->player.plane_x = old_plane_x * cos(-0.05) - old_plane_y * sin(-0.05);
	data->player.plane_y = old_plane_x * sin(-0.05) + old_plane_y * cos(-0.05);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	old_dir_y;
	double	old_plane_y;

	old_dir_x = data->player.dir_x;
	old_dir_y = data->player.dir_y;
	old_plane_x = data->player.plane_x;
	old_plane_y = data->player.plane_y;
	data->player.dir_x = old_dir_x * cos(0.05) - old_dir_y * sin(0.05);
	data->player.dir_y = old_dir_x * sin(0.05) + old_dir_y * cos(0.05);
	data->player.plane_x = old_plane_x * cos(0.05) - old_plane_y * sin(0.05);
	data->player.plane_y = old_plane_x * sin(0.05) + old_plane_y * cos(0.05);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	else
		handle_movement(keycode, data);
	return (0);
}
