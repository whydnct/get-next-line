#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int			fd;

	fd = open(argv[1], O_RDONLY);
	(void)argc;
	printf("%s", fill_temp_stash(fd));
	printf("%s", fill_temp_stash(fd));
}
