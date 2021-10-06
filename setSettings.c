#include "so_long.h"

void setWidth(char *temp_map, t_map *map)
{
	int i;

	i = 0;
	while(temp_map[i] != '\n' && temp_map[i])
		i++;
	map->width = i;
}

void setHeight(char *temp_map, t_map *map)
{
	int		i;

	i = 0;
	map->height = 0;
	while(temp_map[i])
	{
		if(temp_map[i] == '\n')
			map->height++;
		i++;
	}
	map->height++;
}