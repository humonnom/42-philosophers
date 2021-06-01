#include "philo_one.h"

//     print_forks_status(t_philo *philo, int number_of_philos)
// {
//     printf("forks-status: ");
//         for (int j = 0; j < number_of_philos; j++)
//         {
//             printf("\t[%d]%d", j, philo->forks[j]);
//         }
//         printf("\n");
// }

void
    print_philos(t_philo *philos, int number_of_philos)
{
    int i;

    i = -1;
    while (++i < number_of_philos)
    {
        printf("\n[ %s: %d ]\n", "philo philo_id", philos[i].philo_id);
        printf(" %-15s: %llu\n", "eat_start", philos[i].eat_start);
        // printf(" %-15s: %d\n", "sleep_start", philos[i].sleep_start);
        printf(" %-15s: %d\n", "eat_left", philos[i].eat_left);
        // printf(" %-15s: %d\n", "time_left", philos[i].time_left);
        // printf(" %-15s: %d\n", "left_fork", philos[i].left_fork);
        // printf(" %-15s: %d\n", "right_fork", philos[i].right_fork);
        // print_forks_status(&philos[i], number_of_philos);
    }
}
