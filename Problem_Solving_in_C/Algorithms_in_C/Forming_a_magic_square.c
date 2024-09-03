#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

#define N 3
#define MAGIC_SUM 15

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generate_permutations(int *arr, int l, int r, int *min_cost, int **s) {
    if (l == r) {
        // Check if the permutation forms a magic square
        int magic[N][N];
        int k = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                magic[i][j] = arr[k++];

        int rows[N] = {0}, cols[N] = {0}, diag1 = 0, diag2 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                rows[i] += magic[i][j];
                cols[j] += magic[i][j];
                if (i == j) diag1 += magic[i][j];
                if (i + j == N - 1) diag2 += magic[i][j];
            }
        }

        int valid = 1;
        for (int i = 0; i < N; i++) {
            if (rows[i] != MAGIC_SUM || cols[i] != MAGIC_SUM) {
                valid = 0;
                break;
            }
        }
        if (diag1 != MAGIC_SUM || diag2 != MAGIC_SUM) valid = 0;

        if (valid) {
            // Calculate the cost
            int cost = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cost += abs(s[i][j] - magic[i][j]);
                }
            }
            if (cost < *min_cost) *min_cost = cost;
        }
    } else {
        for (int i = l; i <= r; i++) {
            swap(&arr[l], &arr[i]);
            generate_permutations(arr, l + 1, r, min_cost, s);
            swap(&arr[l], &arr[i]);
        }
    }
}

int formingMagicSquare(int s_rows,int s_columns, int **s) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int min_cost = INT_MAX;
    generate_permutations(arr, 0, 8, &min_cost, s);
    return min_cost;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int** s = malloc(3 * sizeof(int*));

    for (int i = 0; i < 3; i++) {
        *(s + i) = malloc(3 * (sizeof(int)));

        char** s_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            int s_item = parse_int(*(s_item_temp + j));

            *(*(s + i) + j) = s_item;
        }
    }

    int result = formingMagicSquare(3, 3, s);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
