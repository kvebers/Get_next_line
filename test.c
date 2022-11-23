/*
This is a test to get better understanding how the read function works and how to work  with the project this will not be included in submited project
Huge thanks to https://tomah56.github.io/42_hackatlon/code/level_3.html very good project to learn the basics of the get_next_line
*/
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
