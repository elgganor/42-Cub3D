#include "cub3d.h"

void print_map(t_vars *vars)
{
	size_t x = 0;
	size_t y = 0;

	while (y < MAP->nb_row)
	{
		x = 0;
		while (x < MAP->nb_col)
		{
			ft_putnbr(MAP->layout[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void update_window(t_vars *vars)
{
	mlx_clear_window(WIN->mlx_ptr, WIN->win_ptr);
}

int print_key(int key_code, t_vars *vars)
{

	update_window(vars);
	if (key_code == KEY_A)
		mlx_string_put(WIN->mlx_ptr, WIN->win_ptr, WIN->width / 2, WIN->height / 2, CUB->c_color, "Key A");
	else if (key_code == KEY_S)
		mlx_string_put(WIN->mlx_ptr, WIN->win_ptr, WIN->width / 2, WIN->height / 2, CUB->c_color, "Key S");
	else if (key_code == KEY_D)
		mlx_string_put(WIN->mlx_ptr, WIN->win_ptr, WIN->width / 2, WIN->height / 2, CUB->c_color, "Key D");
	else if (key_code == KEY_W)
		mlx_string_put(WIN->mlx_ptr, WIN->win_ptr, WIN->width / 2, WIN->height / 2, CUB->c_color, "Key W");
	return (0);
}