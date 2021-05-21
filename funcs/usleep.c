#include <unistd.h>

int main(void)
{
	while (1)
	{
		write(1, "Mississippi\n", 12);
		usleep(1000 * 1000);
	}
}
