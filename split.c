#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tokens
{  
    char **symbols;
    int size;
}tokenbag;

tokenbag* split(char *str, const char delim)
{
    int i = 0;
    char *end = strchr(str, delim);
    char *start = str;
    tokenbag* tokens = calloc(1, sizeof(tokenbag));
    tokens->symbols = calloc(strlen(str), sizeof(char *));
    for (;; end = strchr(start, delim))
    {
        int len = !end ? strlen(start) : (end - start);
        tokens->symbols[i] = calloc(len + 1, 1);
        strncpy(tokens->symbols[i], start, len);
        tokens->symbols[i][len] = '\0';
        
        if (end)
        {
            start = end + 1;
            i++;
            tokens->size = i + 1;
        }
        else
            break;
    }
    
    return tokens;
}

char** split(char *str, const char delim)
{
    int i = 0;
    char *end = strchr(str, delim);
    char *start = str;
    char ** tokens = calloc(strlen(str), sizeof(char *));
    
    for (;; end = strchr(start, delim))
    {
        int len = !end ? strlen(start) : (end - start);
        tokens[i] = calloc(len + 1, 1);
        strncpy(tokens[i], start, len);
        tokens[i][len] = '\0';
        
        if (end)
        {
            start = end + 1;
            i++;
        }
        else
            break;
    }
    
    return tokens;
}

