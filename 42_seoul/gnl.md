# get next line (gnl)
```c
// function prototype:
char *get_next_line(int fd);
```
`get_next_line` is a function that takes in a file descripter, and returns the 'next line' each time the function is called. The program should be compiled with the gcc flag `-D BUFFER_SIZE=<some-number>`. The user of the function may change the value of `BUFFER_SIZE` accordingly. 

In case of error, or EOF, the function will return a NULL value.

The main goal of the gnl project is to understand and use static variables in a function. 

As a bonus, the function is able to switch between various file descripters without losing any information, while the program is still running.

```c
// The function can be used as follows:

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char	*line;
	int	fd;

	fd = open("path/to/textfile.txt", O_RDONLY);
	while ((line = get_next_line(fd))
	{
		printf("%s", line);
	}
}
```
