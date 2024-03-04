/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:02:37 by merboyac          #+#    #+#             */
/*   Updated: 2024/03/04 18:10:16 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdlib.h>

int get_key(int keycode)
{
	if(keycode == 53)
	{
		system("leaks so_long");
		exit(0);
	}
	return (0);
}

int main()
{
	void	*image;
	void	*mlx;
	void	*mlx_win;
	int		a;

	mlx = mlx_init();
	if(!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	if(!mlx_win)
		return (free(mlx), 1);
	mlx_key_hook(mlx_win, get_key, (void *)0);
	image = mlx_xpm_file_to_image(mlx, "./textures/floor.xpm", &a, &a);
	if (!image)
		return (1);
	mlx_put_image_to_window(mlx, mlx_win, image, 0, 0);
	mlx_loop(mlx);
}
