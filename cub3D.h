/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:53:16 by sshawish          #+#    #+#             */
/*   Updated: 2025/05/26 12:49:57 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define MAX_LINES 1000
# define SCREEN_HEIGHT 800
# define SCREEN_WIDTH 800
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define SPACE 32
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define FLOOR_TEXTURE_PATH "textures/floor_tex3.xpm"
# define DOOR_TEXTURE_PATH	"textures/closed_door.xpm"
# define DOOR_OPEN_TEXTURE_PATH "textures/opened_door.xpm"
# define TILE_SIZE 8
# define MINIMAP_SCALE 0.2
# define MINIMAP_MARGIN 10

typedef struct s_floor
{
	double	ray_dir_x0;
	double	ray_dir_x1;
	double	ray_dir_y0;
	double	ray_dir_y1;
	double	row_dist;
	double	floor_step_x;
	double	floor_step_y;
	double	floor_x;
	double	floor_y;
	int		tex_x;
	int		tex_y;
	int		color;
}	t_floor;

typedef struct s_line
{
	int	x;
	int	start;
	int	end;
	int	color;
}	t_line;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_textures
{
	t_img	*north;
	t_img	*south;
	t_img	*west;
	t_img	*east;
	t_img	*floor;
	t_img	*door_closed;
	t_img	*door_open;
}	t_textures;

typedef struct s_wallcast
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	int		y;
	t_img	*texture_img;
}	t_wallcast;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		hit_door;
}	t_ray;

typedef struct s_minimap
{
	int		i;
	int		x;
	int		y;
	int		px;
	int		py;
	int		size;
	double	dx;
	double	dy;
}	t_minimap;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	char		**map;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color;
	int			ceiling_color;
	int			map_size;
	int			red;
	int			green;
	int			blue;
	int			mouse_x;
	int			tex_flag;
	t_player	player;
	t_img		img;
	t_textures	*textures;
}	t_data;

t_img	*load_texture(t_data *data, const char *texture_path);
void	load_textures(t_data *data, t_textures *tex);
int		is_wall(char **map);
int		valid_map(t_data *data);
int		check_walls(char *line);
int		render_frame(t_data *data);
int		close_window(t_data *data);
int		render_frame(t_data *data);
int		valid_cub(const char *filename);
int		key_hook(int keycode, t_data *data);
int		read_map(const char *filename, t_data *data);
int		parse_color(char *line, int *color, t_data *data);
int		parse_line(char *line, t_data *data, int *map_start);
int		get_texture_color(t_img *texture, int tex_x, int tex_y);
void	free_map(char **map);
void	free_data(t_data *data);
void	init_data(t_data *data);
void	init_window(t_data *data);
void	init_player(t_data *data);
void	toggle_door(t_data *data);
void	rotate_left(t_data *data);
void	init_window(t_data *data);
void	rotate_right(t_data *data);
void	draw_minimap(t_data *data);
void	free_textures(t_data *data);
void	cast_ray(int x, t_data *data);
void	draw_player_dir(t_data *data);
void	draw_player_minimap(t_data *data);
void	add_to_map(t_data *data, char *line);
void	perform_dda(t_data *data, t_ray *ray);
void	handle_movement(int keycode, t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
void	set_player_direction(t_data *data, char direction);
void	draw_textured_wall(int x, t_ray *ray, t_data *data);
void	calculate_ray_direction(int x, t_data *data, t_ray *ray);
void	select_wall_texture(t_ray *ray, t_data *data, t_wallcast *w);
void	calculate_wall_distance_and_height(t_data *data, t_ray *ray);
void	calculate_wall_texture(t_ray *ray, t_data *data, t_wallcast *w);
void	calculate_floor_values(t_data *data, int x, int y, t_floor *floor_draw);
#endif