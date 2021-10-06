#include "so_long.h"

int		allocateMem(t_map *map)
{
	int		i;

	i = 0;
	map->map = (char **)malloc(sizeof(char *) * map->height);
	if(map->map == NULL)
		return(0);
	while(i < map->height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->width));
		if(map->map[i] == NULL)
			return(0);
		i++;
	}
	return(1);
}

int		writeMapToArr(char *temp_map, t_map *map)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while(temp_map[i] != '\0') 
	{
		if(temp_map[i] == '\n')
		{
			map->map[x++][y] = '\0';
			i++;
			y = 0;
		}
		else
			map->map[x][y++] = temp_map[i++];
	}
	map->map[x][y] = '\0';
	return(1);
}