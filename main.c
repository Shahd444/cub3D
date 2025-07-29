/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:37:10 by sshawish          #+#    #+#             */
/*   Updated: 2025/05/28 08:36:59 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	read_map(const char *filename, t_data *data)
{
	int		fd;
	int		map_start;
	char	*line;
	size_t	len;

	map_start = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (parse_line(line, data, &map_start) == 1)
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}

int	mouse_move(int x, int y, t_data *data)
{
	(void)y;
	if (data->mouse_x > x)
		rotate_left(data);
	else if (data->mouse_x < x)
		rotate_right(data);
	data->mouse_x = x;
	render_frame(data);
	return (0);
}

void	setup_and_run(t_data *data)
{
	init_player(data);
	init_window(data);
	data->textures = malloc(sizeof(t_textures));
	if (!data->textures)
		exit(1);
	load_textures(data, data->textures);
	data->img.ptr = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	mlx_loop_hook(data->mlx, render_frame, data);
	mlx_hook(data->window, 17, 0, close_window, data);
	mlx_hook(data->window, 2, 1L << 0, key_hook, data);
	mlx_hook(data->window, 6, 1L << 6, mouse_move, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !valid_cub(av[1]))
	{
		ft_putstr_fd("Error\ntry ./cub3D valid file.cub\n", 2);
		return (EXIT_FAILURE);
	}
	init_data(&data);
	if (read_map(av[1], &data) == 1
		|| !data.north_texture || !data.south_texture
		|| !data.west_texture || !data.east_texture
		|| data.floor_color == -1 || data.ceiling_color == -1)
	{
		free_data(&data);
		return (EXIT_FAILURE);
	}
	if (!valid_map(&data))
	{
		free_data(&data);
		return (EXIT_FAILURE);
	}
	setup_and_run(&data);
	return (0);
}
