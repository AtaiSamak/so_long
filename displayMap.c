#include "so_long.h"

int     openWindow(t_map *map)
{
    map->blockSize = 50;
    map->win_width = map->width * map->blockSize;
    map->win_height = map->height * map->blockSize;
    map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, map->win_width, map->win_height, "So_long!");
    return(1);
}

void    initItems(t_map *map)
{

    map->wall = mlx_xpm_file_to_image(map->mlx, "img/wall.xpm", &map->blockSize, &map->blockSize);
    map->exit = mlx_xpm_file_to_image(map->mlx, "img/exit.xpm", &map->blockSize, &map->blockSize);
    map->coll = mlx_xpm_file_to_image(map->mlx, "img/collect.xpm", &map->blockSize, &map->blockSize);
    map->bg = mlx_xpm_file_to_image(map->mlx, "img/bg.xpm", &map->blockSize, &map->blockSize);
    map->pl_front = mlx_xpm_file_to_image(map->mlx, "img/pl_front.xpm", &map->blockSize, &map->blockSize);
    map->pl_up = mlx_xpm_file_to_image(map->mlx, "img/pl_up.xpm", &map->blockSize, &map->blockSize);
    map->pl_left = mlx_xpm_file_to_image(map->mlx, "img/pl_left.xpm", &map->blockSize, &map->blockSize);
    map->pl_right = mlx_xpm_file_to_image(map->mlx, "img/pl_right.xpm", &map->blockSize, &map->blockSize);
}

void    putItem(t_map *map, int y, int x, char type)
{
    if(type == '1')
        mlx_put_image_to_window(map->mlx, map->win, map->wall, x, y);
    else if(type == '0')
        mlx_put_image_to_window(map->mlx, map->win, map->bg, x, y);
    else if(type == 'C')
    {
        mlx_put_image_to_window(map->mlx, map->win, map->bg, x, y);
        mlx_put_image_to_window(map->mlx, map->win, map->coll, x, y);
    }
    else if(type == 'E')
    {
        mlx_put_image_to_window(map->mlx, map->win, map->bg, x, y);
        mlx_put_image_to_window(map->mlx, map->win, map->exit, x, y);
    }
    else if (type == 'P')
    {
        mlx_put_image_to_window(map->mlx, map->win, map->bg, x, y);
        mlx_put_image_to_window(map->mlx, map->win, map->pl_front, x, y);
    }
}

void    setItems(t_map *map)
{
    map->i = 0;

    while(map->i < map->height)
    {
        map->j = 0;
        while(map->j < map->width)
        {
            if(map->map[map->i][map->j] == '1')
                putItem(map, map->i * map->blockSize, map->j * map->blockSize, '1');
            else if(map->map[map->i][map->j] == '0')
                putItem(map, map->i * map->blockSize, map->j * map->blockSize, '0');
            else if(map->map[map->i][map->j] == 'C')
                putItem(map, map->i * map->blockSize, map->j * map->blockSize, 'C');
            else if(map->map[map->i][map->j] == 'E')
                putItem(map, map->i * map->blockSize, map->j * map->blockSize, 'E');
            else if(map->map[map->i][map->j] == 'P')
                putItem(map, map->i * map->blockSize, map->j * map->blockSize, 'P');
            map->j++;
        }
        map->i++;
    }
}