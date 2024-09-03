#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int distinct_chars(const char *a)
{
    int x = 0;
    int chars[26] = {0};

    while (*a != '\0') {
        int chr = (*a++) - 'a';
        if (chr < 26)
            chars[chr]++;
    }
    
    for (int i = 0; i < 26; i++)
        if (chars[i])
            x++;

    return x;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int ans = distinct_chars(a) - distinct_chars(b);
    return (ans) ? ans : lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int ans = strlen(a) - strlen(b);
    return (ans) ? ans : lexicographic_sort(a, b);
}

void string_sort(char** arr, const int len,int (*cmp_func)(const char* a, const char* b)) {
    int flag = 0;
    int s = len - 1;
    while (!flag) {
        flag = 1;
        for (int i = 0; i < s; i++) {
            if (cmp_func(arr[i], arr[i + 1]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 0;
            }
        }
        s--;
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}