/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:19:02 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/25 09:52:07 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_facing_tile(t_data *data, int tx, int ty)
{
	double	vec_x;
	double	vec_y;
	double	length;
	double	dot;

	vec_x = tx + 0.5 - data->player.pos_x;
	vec_y = ty + 0.5 - data->player.pos_y;
	length = sqrt(vec_x * vec_x + vec_y * vec_y);
	vec_x /= length;
	vec_y /= length;
	dot = vec_x * data->player.dir_x + vec_y * data->player.dir_y;
	return (dot > 0.5);
}

void	check_and_toggle(t_data *data, int tx, int ty)
{
	char	*tile;

	if (ty < 0 || ty >= data->map_size)
		return ;
	if (tx < 0 || tx >= (int)ft_strlen(data->map[ty]))
		return ;
	tile = &data->map[ty][tx];
	if ((*tile != 'D' && *tile != 'O') || !is_facing_tile(data, tx, ty))
		return ;
	if (*tile == 'D')
		*tile = 'O';
	else
		*tile = 'D';
}

void	toggle_door(t_data *data)
{
	int	px;
	int	py;

	px = (int)data->player.pos_x;
	py = (int)data->player.pos_y;
	check_and_toggle(data, px, py - 1);
	check_and_toggle(data, px, py + 1);
	check_and_toggle(data, px - 1, py);
	check_and_toggle(data, px + 1, py);
}
