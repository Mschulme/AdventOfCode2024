#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    FILE *file;
    char line[256];
    size_t len = 256;
    ssize_t read;

    file = fopen("day_2.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char *token;
    int unsafe_counter = 0;
    int counter_inc = 0;
    int counter_dec = 0;
    bool stop_counting = false;

    while (fgets(line, len, file) != NULL)
    {
        counter_dec = 0;
        counter_inc = 0;
        stop_counting = false;

        token = strtok(line, " ");
        int pred = atoi(token);
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            if (token != NULL)
            {
                int succ = atoi(token);
                if (abs(pred - succ) > 3 && stop_counting == false)
                {
                    unsafe_counter += 1;
                    stop_counting = true;
                }
                if (succ - pred > 0)
                    counter_inc += 1;
                if (succ - pred < 0)
                    counter_dec += 1;
                if (succ == pred && stop_counting == false)
                {
                    unsafe_counter += 1;
                    stop_counting = true;
                }
                pred = succ;
            }
        }
        if (counter_dec != 0 && counter_inc != 0 && stop_counting == false)
        {
            unsafe_counter += 1;
        }
    }

    int res = 1000 - unsafe_counter;
    printf("The number of safe level is %i", res);
}
