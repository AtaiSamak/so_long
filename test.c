// #include "so_long.h"
// #include "mlx.h"


//  Imges and window managment ===================

// typedef struct  s_data {
//     void *img;
//     char *addr;
//     int bits_per_pixel;
//     int line_length;
//     int endian;
// }               t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;
    
//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

// int main() {
//     void *mlx;
//     void *mlx_win;
//     t_data img;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//     img.img = mlx_new_image(mlx, 1920, 1080);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
//                         &img.line_length, &img.endian);
//     draw_square(&img, 50, 50, 0x00FF0000);
//     // my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 860, 540);
//     mlx_loop(mlx);
// }


// Hooking into key, mouse events ====================

// typedef struct  s_vars {
//     void    *mlx;
//     void    *win;
// }               t_vars;

// int key_hook(int keycode, t_vars *vars)
// {
//     if(keycode == 13) {
//         printf("up\n");
//     }else if(keycode == 2) {
//         printf("right\n");
//     } else if (keycode == 0) {
//         printf("left\n");
//     } else if (keycode == 1) {
//         printf("down\n");
//     } else if (keycode == 53) {
//         mlx_destroy_window(vars->mlx, vars->win);
//     } else {
//         printf("code - %d\n", keycode);
//     }
//     return(0);
// }

// int mouse_hook(int mousePos)
// {
//     printf("mouse - %d\n", mousePos);
//     return 0;
// }

// int main(void)
// {
//     t_vars  vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world");
//     mlx_key_hook(vars.win, key_hook, &vars);
//     mlx_mouse_hook(vars.win, mouse_hook, &vars);
//     mlx_loop(vars.mlx);
// }
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;


int key_hook(int keycode, t_vars *vars)
{
	printf("Hello world!%d\n", keycode);
	if(keycode == 1) {
		mlx_destroy_image(vars->mlx, vars->img);
	}
	return(0);
}

int	main(void)
{
	t_vars	vars;
	void	*img;
    void    *win;
	char	*relative_path = "img/wall.xpm";
	int		img_width = 11;
	int		img_height = 11;

	vars.mlx = mlx_init();
	img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
    win = mlx_new_window(vars.mlx, 500, 500, "Hello world");
	for(int i = 0; i < 500 - 49; i +=50) {
		mlx_put_image_to_window(vars.mlx, win, img, i, 0);
	} for(int i = 0; i < 500 - 49; i += 50) {
		mlx_put_image_to_window(vars.mlx, win, img, 0, i);
	} for(int i = 0; i < 500 - 49; i += 50) {
		mlx_put_image_to_window(vars.mlx, win, img, i, 450);
	} for(int i = 0; i < 500 - 49; i += 50) {
		mlx_put_image_to_window(vars.mlx, win, img, 450, i);
	}

	char *img_path = "img/exit.xpm";
	int 	del_img;
	mlx_put_image_to_window(vars.mlx, win, img, 100, 100);
	vars.img = mlx_xpm_file_to_image(vars.mlx, img_path, &img_width, &img_height);
	del_img = mlx_put_image_to_window(vars.mlx, win, vars.img, 100, 100);
	mlx_key_hook(win, key_hook, &vars);
    mlx_loop(vars.mlx);
}
