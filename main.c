#include "get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int		fd;
	char	*str;
    int     animator;

	fd = open("ani1.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
        animator = 0;
        while (animator < 106 && str)
        {
		    printf("\033[1;39m%s\033[39m", str);
		    free(str);
		    str = get_next_line(fd);
            animator++;
        }
        usleep(200000);
		printf("\033[2J"); 

	}
    free (str);
	close(fd);
	return (0);
}