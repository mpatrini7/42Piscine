#ifndef RUSH_H
# define RUSH_H

# define    SIZE_1B    1

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

enum e_bool {
	false,
	true,
};

enum e_io {
	in,
	out,
	err,
};

typedef struct s_list{
	int valore;
	int decine;
	char* nome;
	struct s_list *next;
	} t_nodo;

#endif
