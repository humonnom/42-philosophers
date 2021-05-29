#include "philo_one.h"

void
    print_philos(t_philo *philos, int number_of_philos)
{
    int i;

    i = -1;
    while (++i < number_of_philos)
    {
        printf("\n[ %s: %d ]\n", "philo philo_id", philos[i].philo_id);
        printf(" %-15s: %d\n", "eat_start", philos[i].eat_start);
        printf(" %-15s: %d\n", "sleep_start", philos[i].sleep_start);
        printf(" %-15s: %d\n", "eat_count", philos[i].eat_count);
        printf(" %-15s: %d\n", "time_left", philos[i].time_left);
        printf(" %-15s: %d\n", "left_fork", philos[i].left_fork);
        printf(" %-15s: %d\n", "right_fork", philos[i].right_fork);
    }
}
