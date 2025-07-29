/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:38:40 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/26 12:13:43 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;
	float	speed;

	speed = 0.1;
	new_x = data->player.pos_x + data->player.dir_x * speed;
	new_y = data->player.pos_y + data->player.dir_y * speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1' &&
		data->map[(int)data->player.pos_y][(int)new_x] != 'D')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1' &&
		data->map[(int)new_y][(int)data->player.pos_x] != 'D')
		data->player.pos_y = new_y;
}

void	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;
	float	speed;

	speed = 0.1;
	new_x = data->player.pos_x - data->player.dir_x * speed;
	new_y = data->player.pos_y - data->player.dir_y * speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1' &&
		data->map[(int)data->player.pos_y][(int)new_x] != 'D')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1' &&
		data->map[(int)new_y][(int)data->player.pos_x] != 'D')
		data->player.pos_y = new_y;
}

void	move_left(t_data *data)
{
	double	new_x;
	double	new_y;
	float	speed;

	speed = 0.1;
	new_x = data->player.pos_x - data->player.plane_x * speed;
	new_y = data->player.pos_y - data->player.plane_y * speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1' &&
		data->map[(int)data->player.pos_y][(int)new_x] != 'D')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1' &&
		data->map[(int)new_y][(int)data->player.pos_x] != 'D')
		data->player.pos_y = new_y;
}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;
	float	speed;

	speed = 0.1;
	new_x = data->player.pos_x + data->player.plane_x * speed;
	new_y = data->player.pos_y + data->player.plane_y * speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1' &&
		data->map[(int)data->player.pos_y][(int)new_x] != 'D')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1' &&
		data->map[(int)new_y][(int)data->player.pos_x] != 'D')
		data->player.pos_y = new_y;
}

void	handle_movement(int keycode, t_data *data)
{
	if (keycode == W)
		move_forward(data);
	else if (keycode == S)
		move_backward(data);
	else if (keycode == A)
		move_left(data);
	else if (keycode == D)
		move_right(data);
	else if (keycode == SPACE)
		toggle_door(data);
	else if (keycode == LEFT_ARROW)
		rotate_left(data);
	else if (keycode == RIGHT_ARROW)
		rotate_right(data);
}
