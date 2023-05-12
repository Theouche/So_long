/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:17:55 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/11 19:45:57 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libmlx/mlx.h"

# define KEY_SPACE 32
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_A 97
# define KEY_ESC 65307
# define FOOTER_H 32 

typedef struct s_env
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	empty;
	int		count_c;
	int		count_p;
	int		count_e;

}	t_env;

typedef struct s_data
{
	int		h;
	int		hp;
	int		l;
	int		lp;
	int		count;
	int		c_collected;
	char	**map;
	char	*map_str;
	int		game;
	int		imput;
	int		coord_x;
	int		coord_y;
	int		coord_ex;
	int		coord_ey;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall;
	void	*empty;
	void	*player_r;
	void	*player_r1;
	void	*player_l;
	void    *player_l1;
	void	*player_u;
	void    *player_u1;
	void	*player_d;
	void    *player_d1;
	void	*exit;
	void	*collect;
	void	*mob;
	void	*step;
	void	*step_wall;
	t_env	env;
}	t_data;

char	*ft_strstr(const char *big, const char *little);
int		get_map_n_check(t_data *data, int argc, char **argv);
int		get_map(t_data *data, char *filename);
char	*ft_read(int fd, char *filename);
int		ft_len_doc(char *filename);
int		check_map(t_data *data);
int		check_path(t_data *data);
int		key_move(int key, t_data *data);
void	put_img(t_data *data, int x, int y);
void	create_map(t_data *data);
void	create_image(t_data *data);
void	ft_win(t_data *data);
void	ft_lose(t_data *data);
int		ft_quit(t_data *data);
void	ft_destroy(t_data *data);
void	ft_free(char **mapbis);
void	ft_count(t_data *data, char c);
int		check_char(char c);
void	ft_error(t_data *data);
void	choose_image_player(t_data *data, int x, int y);
void    put_image_odd(t_data *data, int x, int y);
void    put_image_even(t_data *data, int x, int y);
void	ft_footer(t_data *data);

#endif
