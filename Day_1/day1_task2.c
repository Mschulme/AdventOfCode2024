#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main(void)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen("day_1.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int *array_1 = malloc(sizeof(int) * 1000);
    int *array_2 = malloc(sizeof(int) * 1000);
    char *token;
    int i = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        token = strtok(line, " ");
        array_1[i] = atoi(token);
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            if (token != NULL)
                array_2[i] = atoi(token);
        }
        ++i;
    }

    qsort(array_1, i, sizeof(int), compare);
    qsort(array_2, i, sizeof(int), compare);

    int sum = 0;
    for (int i = 0; i < 1000; ++i)
        sum += abs(array_1[i] - array_2[i]);

    printf("The final result is: %i\n", sum);

    int *number_of_occurences = malloc(sizeof(int) * 100000);
    memset(number_of_occurences, 0, sizeof(int) * 100000);
    for (int i = 0; i < 1000; ++i)
    {
        number_of_occurences[array_2[i]] += 1;
    }

    int similarity_score = 0;
    for (int i = 0; i < 1000; ++i)
        similarity_score += array_1[i] * number_of_occurences[array_1[i]];

    printf("The final result is: %i\n", similarity_score);

    free(line);
    fclose(file);
    return EXIT_SUCCESS;
}