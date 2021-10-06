#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10000

#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "mlx.h"

typedef struct  s_map
{
    char    **map;
    int     width;
    int     height;
    int     i;
    int     j;
    int     posX;
    int     posY;
}               t_map;

void    setWidth(char *temp_map, t_map *map);
void    setHeight(char *temp_map, t_map *map);
int		allocateMem(t_map *map);
int		writeMapToArr(char *temp_map, t_map *map);
int		checkMapSizes(char *temp_map,t_map *map);
void	freeMapStruct(t_map *map);
void	displayConsole(t_map *map);
int     workMap(t_map *map);
int     checkPresItems(t_map *map);
int     checkMapWalls(t_map *map);
int     checkMapItems(t_map *map);

#endif