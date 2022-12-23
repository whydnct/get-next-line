#include "get_next_line.h"

int	main(int argc, char **argv)
{
	static char	*temp_stash;
	int			fd;

	temp_stash = malloc(BUFFER_SIZE + 1);
	temp_stash[BUFFER_SIZE] = '\n';
	fd = open(argv[1], O_RDONLY);
	(void)argc;
	printf("%s", fill_temp_stash(fd, temp_stash));
	printf("Entre prints %s \n", temp_stash);
	printf("%s", fill_temp_stash(fd, temp_stash));
}
