#include <sys/time.h>
#include <stdio.h>

static struct timeval  tv1, tv2;

void start_timer(void)
{
    gettimeofday(&tv1, NULL);
}

void end_timer(void)
{
    gettimeofday(&tv2, NULL);

    printf ("Total time = %f seconds\n",
                        (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
                                      (double) (tv2.tv_sec - tv1.tv_sec));
}
