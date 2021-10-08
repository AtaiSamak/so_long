#include "so_long.h"

int		read_map(char *fileName, t_map *map)
{
	int fd;
	int reader;
	char	temp_map[BUFFER_SIZE];

	fd = open(fileName, O_RDONLY);
	if(fd == -1)
		return(-1);
	reader = read(fd, temp_map, BUFFER_SIZE);
	if(reader == -1)
		return(-1);
	temp_map[reader] = '\0';
	setWidth(temp_map, map);
	setHeight(temp_map, map);
	if(checkMapSizes(temp_map, map) == -1)
	{
		printf("Error mapSize\n");
		return(-1);
	}
	if(allocateMem(map) == 0)
		return(-1);
	writeMapToArr(temp_map, map);
	if(workMap(map) == -1)
		return(-1);
	return(1);
}

int main(int argc, char *argv[])
{
	t_map	map;

	if(argc == 2)
	{
		if(read_map(argv[1], &map) == -1)
		{
			printf("Error\n");
			return(0);
		}
	}
	else
	{
		printf("Please write correct!\n");
	}
	return 0;
}
