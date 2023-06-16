#include "get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int		fd;
	char	*str;
    int     animator;

	fd = open("ani.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
        animator = 0;
        while (animator < 7 && str)
        {
		    printf("%s", str);
		    free(str);
		    str = get_next_line(fd);
            animator++;
        }
        usleep(200000);

	}
    free (str);
	close(fd);
	return (0);
}