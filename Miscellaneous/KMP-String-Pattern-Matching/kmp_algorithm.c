#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATCHES 1000

typedef struct {
    int* indices;
    int count;
    int capacity;
} SearchResult;

SearchResult* createSearchResult() {
    SearchResult* result = (SearchResult*)malloc(sizeof(SearchResult));
    result->capacity = MAX_MATCHES;
    result->indices = (int*)malloc(result->capacity * sizeof(int));
    result->count = 0;
    return result;
}

void freeSearchResult(SearchResult* result) {
    if (result) {
        free(result->indices);
        free(result);
    }
}

void addMatch(SearchResult* result, int index) {
    if (result->count < result->capacity)
        result->indices[result->count++] = index;
}

void computeLPS(const char* pattern, int m, int* lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

SearchResult* kmpSearch(const char* text, const char* pattern) {
    SearchResult* result = createSearchResult();
    int n = strlen(text);
    int m = strlen(pattern);
    if (m == 0) return result;

    int* lps = (int*)malloc(m * sizeof(int));
    computeLPS(pattern, m, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            addMatch(result, i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    free(lps);
    return result;
}

int main() {
    char text[1000], pattern[1000];
    printf("Enter text: ");
    scanf("%[^\n]%*c", text);
    printf("Enter pattern: ");
    scanf("%[^\n]%*c", pattern);

    SearchResult* result = kmpSearch(text, pattern);

    if (result->count > 0) {
        printf("Pattern found at indices: ");
        for (int i = 0; i < result->count; i++)
            printf("%d ", result->indices[i]);
        printf("\n");
    } else {
        printf("Pattern not found.\n");
    }

    freeSearchResult(result);
    return 0;
}
